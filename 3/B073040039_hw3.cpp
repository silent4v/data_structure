#include <iostream>
#include <cstdlib>
#include <map>
using namespace std;

class pair
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

map<int,pair>K;
K[1].x = -2; K[1].y = 1;
K[2].x = -1; K[2].y = 2;
K[3].x = 1; K[3].y = 2;
K[4].x = 2; K[4].y = 1;
K[5].x = 2; K[5].y = -1;
K[6].x = 1; K[6].y = -2;
K[7].x = -1; K[7].y = -2;
K[8].x = -2; K[8].y = -1;

int main()
{
    int n;
    while(cin >> n)
        cout << n << endl;
    
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
        return err;
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
        int cache = this->now->value;
        cout << "now = " << cache << endl;
        if(this->now->down == NULL)
        {
            delete now;
            now = NULL;
            return cache;
        }
        this->now = this->now->down;
        cout << "now = " << this->now->value << endl;
        system("pause");
        delete this->now->up;
        this->now->up = NULL;
        return cache;
    }
    catch(int err)
    {
        cout << "stack is empty" << endl;
        return -1;
    }
    
    
}