#include <iostream>
#include <vector>
using namespace std;
/*
    author:B073040039
    date:2019/10/14
    description:stack
*/
class point     //point
{
    public:
        int x,y;
        point() {x=0;y=0;}
        point& operator =(point u) {x=u.x;y=u.y;}
};
const int K[9][2] = {{0,0},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};    //initialize
void f(vector<vector<int>> &x , int step , point pos , int s , bool *flag)   //s is size
{
    if(step > s*s)
    {
        *flag = true;   //have answer
        for(int i = 0 ; i < s ; i++)
        {
            for(int j = 0 ; j < s ; j++)
                cout << x[i][j] << " ";
            cout << endl;
        }
        return;
    }
    point next_pos;     //for recursive
    x[pos.x][pos.y] = step;
    if(step == s*s)
    {
        *flag = true;
        for(int i = 0 ; i < s ; i++)
        {
            for(int j = 0 ; j < s ; j++)
                cout << x[i][j] << " ";
            cout << endl;
        }
        return;
    }
    for(int i = 1 ; i <= 8 ; i++)
    {
        if(*flag)   //if have answer , return
            return;
        if(((pos.x + K[i][0]) >= 0) && ( (pos.x + K[i][0]) < s) && ( (pos.y + K[i][1]) >= 0) && ( (pos.y + K[i][1]) < s))
        {
            if(!(x[pos.x + K[i][0]][pos.y + K[i][1]]))
            {
                next_pos = pos;
                next_pos.x += K[i][0]; next_pos.y += K[i][1];
                f(x,step+1,next_pos,s,flag);
            }
        }
    }
    x[pos.x][pos.y] = 0;
    if(step == 1)   //no answer
        cout << "no solution" << endl;
    return;
}
int main()
{
    int n;
    point p;
    vector<vector<int>>visit;
    vector<int>v;
    bool *check = new bool;
    for(n = 3 ; n <= 6 ; n++)
    {
        visit.clear();
        *check = false;    
        for(int i = 0 ; i < n ; i++)    //initialize visit 
        {
            v.clear();
            for(int j = 0 ; j < n ; j++)
                v.push_back(0);
            visit.push_back(v);
        }
        f(visit , 1 , p , n , check);
        cout << endl;
    }
    return 0;
}