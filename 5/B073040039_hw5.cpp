#include <iostream>
#include <map>
using namespace std;
class node
{
    public:
        int co , ex;    //co is coefficient , ex is exponent
        node *next;
        node() 
        {
            co = 0;
            ex = 0;
            next = NULL;
        }
        node(int c,int e)
        {
            co = c;
            ex = e;
            next = NULL;
        }
};
class poly
{
    public:
        node *head , *end;
        poly(){ head = end = NULL; }
        bool empty()
        {
            if(head == end)
                return true;
            return false;
        }
        void add(node *x)
        {
            node *prev,*cache;
            if(this->empty())
            {
                   head = x->next; 
                   end = x;
            }
            else
            {
                if(x->ex > end->ex)
                {
                    x->next = end;
                    end = x;
                }
                else
                {
                    cache = prev = end;
                    while((cache != head) && (x->ex < cache->ex))      //condition 1 and condition 2,if condition 1 is false,then don't judge condition 2
                    {
                        prev = cache;
                        cache = cache->next;
                    }
                    if(x->ex == cache->ex)
                    {
                        cache->co += x->co;
                    }
                    else
                    {
                        prev -> next = x;
                        x ->next = cache;    
                    }
                }
            }
        }
        void clear()
        {
            node *cache;
            do
            {
                cache = end;
                cout << "(" << cache->co << " , " << cache->ex << ")" << endl;
                end = end->next;
                delete cache;
            } while(end != head);
        }
        friend poly* operator +(poly&,poly&);
        poly& operator =(poly x)
        {
            node *for_new,*cache = x.end;
            while(cache != x.head)
            {
                for_new = new node(cache->co,cache->ex);
                this->add(for_new);
                cache = cache->next;
            }
            return *this;
        }
        poly& operator =(poly *x)
        {
            this->end = x->end;
            this->head = x->head;
            return *this;
        }
};

int main()
{
    poly a,b,plus;
    int p,q,c,e;    //p is a's size , q is b's size,coeffient,exponent
    node *input;
    while(cin >> p)
    {
        for(int i = 0 ; i < p ; i++)
        {
            cin >> c >> e;
            input = new node(c,e);
            a.add(input);
        }
        cin >> q;
        if(!p && !q)
            break;
        for(int i = 0 ; i < q ; i++)
        {
            cin >> c >> e;
            input = new node(c,e);
            b.add(input);
        }
        plus = (a+b);
        cout << "A:" << endl;
        a.clear();
        cout << "B" << endl;
        b.clear();
        cout << "plus:" << endl;
        plus.clear();
        cout << "delete complete" << endl;
    }
    return 0;
}

poly* operator +(poly &x,poly &y)
{
    poly *for_return = new poly;
    node *nowx,*nowy,*cache;
    int c,e;
    nowx = x.end; nowy = y.end;
    while(nowx != x.head)
    {
        nowy = y.end;
        c = nowx->co;
        while(nowy != y.head)
        {
            if(nowx->ex == nowy->ex)
                c += nowy->co;
            nowy = nowy->next;
        }
        e = nowx->ex;
        cache = new node(c,e);
        for_return->add(cache);
        nowx = nowx->next;
    }   
    nowy = y.end;
    while(nowy != y.head)
    {
        nowx = x.end;
        c = nowy->co;
        while(nowx != x.head)
        {
            if(nowy->ex == nowx->ex)
                c += nowy->co;
            nowx = nowx->next;
        }
        e = nowx->ex;
        cache = new node(c,e);
        for_return->add(cache);
        nowy = nowy->next;
    }
    return for_return;
}