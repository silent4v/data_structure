#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
using namespace std;
const int n = 3;
class Pair      //pair
{
    public:
        int x,y;
        Pair() { x = 0; y = 0;}
        Pair & operator =(Pair u) { x = u.x; y = u.y;}
};

const int K[9][2] ={ {0,0},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1} };

void f(int x[][n],int step,Pair pos,bool* flag,bool* solution)
{
    int prev,next = step;
    *flag = true;
    if(*solution)
        return;
    Pair cache = pos;
    x[pos.x][pos.y] = next;
    if(next == n*n)
    {
        *solution = true;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
                cout << x[i][j] << " ";
            cout << endl;
        }
        return;
    }
    for(int i = 1 ; i <= 8 ; i++)
    {
        if(!(x[pos.x + K[i][0]][pos.y + K[i][1]]) && ( (pos.x + K[i][0]) >= 0) && ( (pos.x + K[i][0]) < n) && ( (pos.y + K[i][1]) >= 0) && ( (pos.y + K[i][1]) < n) )
        {
            fflush(stdout);
            fflush(stdin);
            if(!(*flag))
                cache.x -= K[prev][0]; cache.y -= K[prev][1];
            cache.x += K[i][0]; cache.y += K[i][1];
            prev = i;
            f(x,next+1,cache,flag,solution);
        }
    }   
    x[pos.x][pos.y] = 0;
    *flag = false;
    if(next <= 1 && !(*solution))
        cout << "no solution" << endl;
    return;
}

int main()
{
    int visit[n][n];
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++)
            visit[i][j] = 0;
    Pair cache;
    bool *check = new bool;
    bool *answer = new bool;
    *check = true;
    *answer = false;
    f(visit,1,cache,check,answer);
    delete check;
    delete answer;
}