#include <iostream>
#include <cstdlib>
#include <map>
using namespace std;

class pair
{
    private:
        int x , y;
};

class node
{
    public:
        int value;
        node *up , *down;
        node();
};

class stack
{
    private:
        node *now , *head;
        bool started;
    public:
        stack();
        int top();
        bool empty();
        void push(int);
        int pop();
        
};

int main()
{
    /*map <int,pair> K;
    int n;
    while(cin >> n)
    {

    }*/
    
    return 0;
}

node::node()
{
    this->up = NULL;
    this->down = NULL;
}

stack::stack()
{
    this->now = NULL;
    this->started = false;
}

bool stack::empty()
{
    if(this->now == NULL)
        return true;
    return false;
}

int stack::top()
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

void stack::push(int x)
{
    if(!(this->started))
    {
        this->now = new node;
        this->now->down = NULL;
        this->head = this->now;
        this->started = true;
    }
        
    else
    {
        this->now->up = new node;
        this->now->up->down = this->now;
        this->now = this->now->up;
    }
    this->now->value = x;
    
}

int stack::pop()
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