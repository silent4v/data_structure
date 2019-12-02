#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <fstream>
#include <map>
/*
    author:B073040039
    date:2019/12/02
    description:sort
    ps: c++1x
*/
using namespace std;
int compare (const void * a, const void * b) {return ( *(int*)a - *(int*)b );}
void swap(int &x , int &y)
{ 
    if(x == y) return;
    x ^= y; y ^= x; x ^= y; 
}
void insertion_sort(vector<int> &a)     //insertion_sort
{
    bool flag;
    for(int i = 0 ; i < a.size() ; i++)
    {
        flag = false;
        for(int j = 0 ; j < i ; j++)
        {
            if(a[i] <= a[j])
                flag = true;
            if(flag)
                swap(a[i],a[j]);
        }
    }
}
void min_heap(vector<int> &a,int len)   //min_heap
{
    int root,lch,rch; // for any subtree
    for(int i = len-1 ; i >= 0 ; i--)
    {
        root = i+1; lch = root*2; rch = lch+1; root--; lch--; rch--;
        while((lch < len) && (rch < len) && ((a[root] > a[lch]) || (a[root] > a[rch])))
        {
            if(a[root] > a[lch])
                swap(a[root],a[lch]);
            else
                swap(a[root],a[rch]);
        }
    }
}
void heap_sort(vector<int> &a)  //heap_sort
{
    int len = a.size();
    min_heap(a,len);
    for(int i = 0 ; i < a.size() ; i++)
    {
        swap(a[0],a[len-1]);
        min_heap(a,--len);
    }
    reverse(a.begin(),a.end());     //min_heap,reverse
}
void quick_sort(vector<int> &a,int first,int last)      
{
    if(first == last)
        return;
    int left,right,pivot; left = first-1 ; pivot = last-1;
    for(int i = first ; i < last ; i++)
    {
        if(a[i] < a[pivot])
            swap(a[++left],a[i]);
    }
    swap(a[++left],a[pivot]); pivot = left; right = pivot+1;
    quick_sort(a,first,left);
    quick_sort(a,right,last);
}
void radix_sort(vector<int> &a)     //radix_sort
{
    map<int,vector<int>>space;
    int key = 1;
    bool flag = true;
    while(flag)
    {
        flag = false;
        for(auto &&x: a)
        {
            if(x/key != 0)
                flag = true;
            space[(x/key)%10].push_back(x);
        }
        a.clear();
        for(auto &&[x,y] : space)
            for(auto &&t : y)
                a.push_back(t);
        space.clear();
        key *= 10;
    }

}
int main()
{
    vector<int>data,sort_data;
    int num,size; double time_start,time_end;
    fstream input,output;
    input.open("input.txt",ios::in);
    output.open("output5.txt",ios::out);    //just for report,please modify by yourself
    while(input >> size)
    {
        data.clear(); sort_data.clear();
        for(int i = 0 ; i < size ; i++)
        {
            input >> num;
            data.push_back(num);
        }
        sort_data = data;
        time_start = clock();
        sort(sort_data.begin(),sort_data.end());        //same as above
        time_end = clock();
        output << "time : " << (time_end - time_start)/CLOCKS_PER_SEC << endl;
        for(auto &&x : sort_data)
            output << x << " ";
        output << "\n" << endl;
    }
    input.close();
    output.close();
}
