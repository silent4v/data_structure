#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
class TSet
{
    set<char,bool>data;
    TSet& operator +(TSet &x);
    TSet& operator -(TSet &x);
    TSet& operator *(TSet &x);
};

int main()
{
    int num;
    while(cin >> num)
    {
        TSet **d;
        d = new TSet*[num];
        for(int i = 0 ; i < num ; i++)
            d[i] = new TSet[2];
        string cache;


    }
}

TSet& TSet::operator +(TSet &x)
{
    TSet* cache = new TSet();
    merge(this->data.begin(),this->data.end(),x.data.begin(),x.data.end(),cache->data.begin());
    return *cache;
}
