#include <iostream>
#include <stack>
#include <map>
#include <list>
/*
    author:B073040039
    date:2019/11/17
    description:bst
    ps: c++1x
*/
using namespace std;
class node
{
    public:
        int value;
        node *lch,*rch,*dad;
        node(int x) {value = x; dad = lch = rch = nullptr;}
        node() {value = 0; dad = lch = rch = nullptr;}
};
map<int,node*>output;
class tree
{
    private:
        node *root;
    public:
        bool lr(node *child,node *father) {return (father->lch == child);}  //check child item of node,true for lch,false for rch
        const string state(node *x)
        {
            if(x->rch == nullptr && x->lch == nullptr)  //leaf node
                return "leaf";
            else if(x->rch == nullptr || x->lch == nullptr)     //node only has one son
                return "oneson";
            else    //node has two son
                return "trouble";   
        }
        void del(node* x)
        {
            bool child;
            if(x != root)
                child = lr(x,x->dad);
            string check = state(x);
            if(check == "leaf")
            {
                if(x == root)
                {
                    delete x;
                    root = nullptr;
                    return;
                }
                x = x->dad;
                if(child)
                {
                    delete x->lch;
                    x->lch = nullptr;
                }
                else 
                {
                    delete x->rch;
                    x->rch = nullptr;
                }
                
            }
            else if(check == "oneson")
            {
                bool son_position;  
                if(x->lch == nullptr)
                    son_position = false;   //if son is rch,son_position is false
                else 
                    son_position = true;
                if(x == root)
                {
                    if(son_position)
                        root = x->lch;
                    else
                        root = x->rch;
                    delete x;
                    return;
                }
                if(son_position)
                {
                    x->lch->dad = x->dad;
                    if(child)
                        x->dad->lch = x->lch;
                    else
                        x->dad->rch = x->lch;
                }
                else
                {                    
                    x->rch->dad = x->dad;
                    if(child)
                        x->dad->lch = x->rch;
                    else
                        x->dad->rch = x->rch;
                }
                delete x;
            }
            else
            {
                node *succesor;
                succesor = x->rch;
                while(succesor->lch != nullptr)
                    succesor = succesor->lch;
                x->value = succesor->value;
                child = lr(succesor,succesor->dad);
                if(state(succesor) != "leaf")   //if succesor has a child,it will be rch
                {
                    succesor->rch->dad = succesor->dad;
                    if(child)
                        succesor->dad->lch = succesor->rch;
                    else
                        succesor->dad->rch = succesor->rch;
                }
                else
                {
                    if(child)
                        succesor->dad->lch = nullptr;
                    else
                        succesor->dad->rch = nullptr;
                }
                output[x->value] = x;
                delete succesor;
            }
            
        }
        bool empty() {return (root == nullptr);}
        tree() {root = nullptr;}    //constructor of tree
        void add(node* x) 
        {
            if(empty()){ root = x; return;}
            bool position,exist = false;
            node* now = root;
            node* prev = nullptr;
            while(now != nullptr)
            {
                if(x->value < now->value)
                {
                    prev = now;
                    now = now->lch;
                    position = true;
                }
                else if(x->value > now->value)
                {
                    prev = now;
                    now = now->rch;
                    position = false;
                }
                else
                {
                    del(now);
                    output.erase(x->value);
                    exist = true;
                    break;
                }
            }
            if(!exist)
            {
                now = x;
                now->dad = prev;
                if(position)
                    prev->lch = now;
                else
                    prev->rch = now;
                
            }
            return;
        }
        void clear()
        {
            for(auto &&[x,y]:output)
                delete y;
            root = nullptr;
        }
};
void print()    //for output
{
    cout << "node:\t";
        for(auto &&[x,y] : output )
            if(y != nullptr)
                cout << x << "\t";
        cout << "\nleft:\t";
        for(auto &&[x,y] : output )
        {
            if(y != nullptr)
            {
                if(y->lch != nullptr)
                    cout << y->lch->value << "\t";
                else
                    cout << "0\t";
            }
        }
        cout << "\nright:\t";
        for(auto &&[x,y] : output )
        {
            if(y != nullptr)
            {
                if(y->rch != nullptr)
                    cout << y->rch->value << "\t";
                else
                    cout << "0\t";
            }
        }
        cout << "\n" << endl;
}
int main()
{
    int n;
    tree data;
    list<int>input;
    node *space;
    while(cin >> n)
    {
        if(n == -1)
        {
            for(auto &&x : input)
            {
                space = new node(x);
                output[x] = space;
                data.add(space);
            }
            print();
            data.clear();
            output.clear();
            input.clear();
        }
        else
            input.push_back(n);
    }
    data.clear();
    return 0;
}