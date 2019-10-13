
#include <iostream>
using namespace std;
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
        int top() { return now->value; }
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

int main()
{
    int a;
    stack<int> b;
    while(cin >> a)
    {
        b.push(a);
    }
    while(!b.empty())
    {
        cout << b.top() << endl;
        b.pop();
    }
    cout << endl;
}