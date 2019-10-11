#include <iostream>
using namespace std;

template <class T>
class node
{
    public:
        T value;
        node *up , *down;
        node(T);
};

int main()
{
    string a = "aaa";
    node <string> data(a);
    cout << data.value << endl;
}   

template <class T>
node<T>::node(T x)
{
    this->value = x;
}
