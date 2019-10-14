#include <iostream>
#include <list>
#include <cstring>
using namespace std;

class Pair
{
    public:
        int x,y;
        Pair()
        {
            x = 0;
            y = 0;
        }
        Pair & operator =(Pair u)
        {
            x = u.x;
            y = u.y;
        }
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

const int K[9][2] =
{
    {0,0},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}
};

int main()
{
    stack<Pair>pos;
    stack<int>step;
    Pair now_pos;
    int next_step , n , filled;
    bool solution , p , flag;
    while(cin >> n)
    {
        p = true;
        solution = true;
        flag = true;
        int visit[n][n];
        memset(visit,0,sizeof(int)*n*n);
        next_step = 0;
        filled = 0;
        while(filled < n*n)
        {
            if(flag)
            {
                visit[now_pos.x][now_pos.y] = ++filled;
                pos.push(now_pos);
                next_step = 0;
            }
            if(filled >= n*n)
                break;
            flag = false;
            for(int i = next_step+1 ; i <= 8 ; i++)
            {
                if(!(visit[now_pos.x + K[i][0]][now_pos.y + K[i][1]]) && ( (now_pos.x + K[i][0]) >= 0) && ( (now_pos.x + K[i][0]) < n) && ( (now_pos.y + K[i][1]) >= 0) && ( (now_pos.y + K[i][1]) < n) )
                {
                    next_step = i;
                    step.push(next_step);
                    now_pos.x += K[i][0]; now_pos.y += K[i][1];
                    flag = true;
                    break;
                }
            }

            if(!flag)
            {
                visit[now_pos.x][now_pos.y] = 0;
                --filled;
                pos.pop();
                if(pos.empty())
                {
                    solution = false;
                    break;
                }
                next_step = step.pop();
                now_pos = pos.top();
                p = false;
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
        else
            cout << "no solution" << endl;
    }
}