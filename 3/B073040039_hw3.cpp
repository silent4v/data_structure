#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

class Pair
{
    public:
        int x , y;
};

template<class T>
class node
{
    public:
        T value;
        node<T> *down;
        node()
        {
            down = NULL;
        }
};

template <class T>
class stack
{
    public:
        int level;
        node<T> *now , *head , *add;
        T top() { return now->value; }
        bool empty()
        {
            if(now == head )
                return true;
            return false;
        }
        void push(T x)
        {
            if(!level)
            {
                now = new node<T>;
                head = now->down;
                now->value = x;
            }
            else
            {
                add = new node<T>;
                add->value = x;
                add->down = now;
                now = add;
            }
            level ++;
        }
        T pop()
        {
            if(empty())
            {
                cout << "stack is empty";
            }
            else
            {
                T cache;
                add = now;
                cache = add->value;
                now = now->down;
                delete add;
                level--;
                return cache;
            }
            
        }
        stack()
        {
            level = 0;
            head = NULL;
            now = head;
        }
        
};

class chess_knight
{
    public:
        Pair pos;
        int next_step;
        chess_knight()
        {
            pos.x = 0;
            pos.y = 0;
            next_step = 0;
        }
};

const int K[9][2] =
{
    {0,0},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}
};

int main()
{
    int n;
    bool flag , solution;
    stack<chess_knight>use;
    while(cin >> n)
    {
        solution = true;
        int visit[n][n];
        int filled = 0;
        memset(visit,0,sizeof(int)*n*n);
        chess_knight cache;
        while(filled <= n*n)
        {
            cout << "step " << filled+1 << endl;
            if(flag)
                cache.next_step = 0;
            flag = false;
            visit[cache.pos.x][cache.pos.y] = ++filled;
            for(int i = cache.next_step+1 ; i <= 8 ; i++)
            {
                
                if( !(visit[cache.pos.x + K[i][0]][cache.pos.y + K[i][1]]) && ( (cache.pos.x + K[i][0]) >= 0) && ( (cache.pos.x + K[i][0]) < n) && ( (cache.pos.y + K[i][1]) >= 0) && ( (cache.pos.y + K[i][1]) < n) )
                {
                    
                    cache.next_step = i;
                    use.push(cache);
                    cache.pos.x += K[i][0];
                    cache.pos.y += K[i][1];
                    cout << "x = " << cache.pos.x << "\ny = " << cache.pos.y << endl;
                    cout << filled << ". top = " << use.top().pos.x << " " << use.top().pos.y << " " << use.top().next_step << endl;
                    flag = true;
                    break;
                }
            }
            if(filled == 0)
            {
                solution = false;
                cout << "no solution" << endl;
                break;
            }
            if(!flag)
            {
                visit[cache.pos.x][cache.pos.y] = 0;
                //cout << "top = " << use.top().pos.x << " " << use.top().pos.y << " " << use.top().next_step << endl;
                cout << "now pop" << endl;
                cache = use.pop();
                //cout << "cache = " << cache.pos.x << " " << cache.pos.y << " " << cache.next_step << endl;
                --filled;
            }
            
            cout << endl;
            for(int i = 0 ; i < n ; i++)
            {
                for(int j = 0 ; j < n ; j++)
                    cout << visit[i][j] << " ";
                cout << endl;
            }
            cout << endl;
            
                
        }
        if(solution)
        {
            for(int i = 0 ; i < n ; i++)
            {
                for(int j = 0 ; j < n ; j++)
                    cout << visit[i][j] << " ";
                cout << endl;
            }
        }
        while(!use.empty())
            use.pop();
    }
    
    return 0;
}
