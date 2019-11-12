#include <iostream>
#include <stack>
using namespace std;
class node
{
    public:
        int value;
        node *lch,*rch,*dad;
        node(int x) {value = x; dad = lch = rch = nullptr;}
        node() {value = 0; dad = lch = rch = nullptr;}
        void info()
        {
            cout << "dad : ";
            if(this->dad == nullptr)
                cout << "nullptr" << endl;
            else
                cout << this->dad->value << endl;
            cout << "lch : ";
            if(this->lch == nullptr)
                cout << "nullptr" << endl;
            else
                cout << this->lch->value << endl;
            cout << "rch : ";
            if(this->rch == nullptr)
                cout << "nullptr" << endl;
            else
                cout << this->rch->value << endl;
        }
};

class tree
{
    private:
        node *root;
    public:
        void rootinfo() {root->info();}
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
            bool child = lr(x,x->dad);
            string check = state(x);
            if(check == "leaf")
            {
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
                        x->dad->lch = x->lch;
                    else
                        x->dad->rch = x->lch;
                }
                delete x;
            }
            else
            {
                node *succesor;
                succesor = x->rch;
                while(succesor->lch != nullptr)
                    succesor = succesor->lch;
                if(state(succesor) == "leaf")
                {
                    
                    succesor = succesor->dad;
                    delete succesor->lch;
                    succesor->lch = nullptr;
                }
                else 
                {
                    succesor->rch->dad = succesor->dad;
                    succesor->dad->lch = succesor->rch;
                    delete succesor; 
                }
            }
            
        }
        bool empty() {return (root == nullptr);}
        tree() {root = nullptr;}
        void add(node* x) 
        {
            if(empty())
            {
                root = x;
                return;
            }
            bool exist = false;
            bool position;
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
};
int main()
{
    int n;
    tree data;
    node *space;
    while(cin >> n)
    {
        space = new node(n);
        data.add(space);
        cout << n << endl;
        space->info();
        cout << endl;
        cout << "root : " << endl;
        data.rootinfo();
    }
    return 0;
}