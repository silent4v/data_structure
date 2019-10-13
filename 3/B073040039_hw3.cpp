#include <iostream>
#include <cstdlib>
#include <map>
#include <cstring>
using namespace std;

class Pair
{
    public:
        int x , y;
};

template <class T>
class node
{
    public:
        T value;
        node<T> *up , *down;
        node();
};

template <class T>
class stack
{
    private:
        node<T> *now , *head;
        bool started;
    public:
        stack();
        T top();
        bool empty();
        void push(T);
        T pop();
        
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
            next_step = 1;
        }
};

const int K[9][2] =
{
    {0,0},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}
};

int main()
{
    int n;
    bool flag;
    stack<chess_knight>use;
    while(cin >> n)
    {
        
        int visit[n][n];
        int filled = 0;
        memset(visit,0,sizeof(int)*n*n);
        chess_knight cache;
        while(filled <= n*n)
        {
            cout << "step " << filled+1 << endl;; 
            flag = false;
            for(int i = cache.next_step ; i <= 8 ; i++)
            {
                if( !(visit[cache.pos.x + K[i][0]][cache.pos.y + K[i][1]]) && ( (cache.pos.x + K[i][0]) >= 0) && ( (cache.pos.x + K[i][0]) < n) && ( (cache.pos.y + K[i][1]) >= 0) && ( (cache.pos.y + K[i][1]) < n) )
                {
                    visit[cache.pos.x][cache.pos.y] = ++filled;
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
            if(!flag)
            {
                visit[cache.pos.x][cache.pos.y] = 0;
                cout << "now pop" << endl;
                cache = use.pop();
                
                --filled;
            }
                
        }
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
                cout << visit[i][j] << " ";
            cout << endl;
        }
        while(!use.empty())
            use.pop();
    }
    
    return 0;
}

template<class T>
node<T>::node()
{
    this->up = NULL;
    this->down = NULL;
}

template<class T>
stack<T>::stack()
{
    this->now = NULL;
    this->started = false;
}

template<class T>
bool stack<T>::empty()
{
    if(this->now == NULL)
        return true;
    return false;
}

template<class T>
T stack<T>::top()
{
    try
    {
        if(this->empty())
            throw -1;
        return this->now->value;
    }
    catch(int err)
    {
        cout << "stack is empty" << endl;
        return this->now->value;
    }
    
}

template<class T>
void stack<T>::push(T x)
{
    if(!(this->started))
    {
        this->now = new node<T>;
        this->now->down = NULL;
        this->head = this->now;
        this->started = true;
    }
        
    else
    {
        this->now->up = new node<T>;
        this->now->up->down = this->now;
        this->now = this->now->up;
    }
    this->now->value = x;
    
}

template<class T>
T stack<T>::pop()
{
    try
    {
        T cache = this->now->value;
        //cout << "now = " << cache << endl;
        if(this->now->down == NULL)
        {
            delete now;
            now = NULL;
            return cache;
        }
        this->now = this->now->down;
        //cout << "now = " << this->now->value << endl;
        //system("pause");
        delete this->now->up;
        this->now->up = NULL;
        return cache;
    }
    catch(int err)
    {
        cout << "stack is empty" << endl;
        return this->now->value;
    }
    
    
}