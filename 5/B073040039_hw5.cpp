#include <iostream>
using namespace std;
/*
    author:B073040039
    date:2019/11/04
    description:poly
*/
class node
{
    public:
        int co , ex;    //co is coefficient , ex is exponent
        node *next;
        //constructor
        node()  {co = 0; ex = 0; next = nullptr;}
        node(int c,int e){co = c; ex = e; next = nullptr;}
};

class poly
{
    public:
        node *head , *end;
        poly(){ head = end = nullptr; }
        bool empty(){ return ((head == end) ? true : false); }
        void add(node *x)   //add node
        {
            node *prev,*cache;
            if(this->empty()) {head = x->next; end = x;}
            else if(x->co == 0) return;
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
                    if((cache != head) && (x->ex == cache->ex))
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
        void clear()    //clear node
        {
            node *cache;
            while(end != head)
            {
                cache = end;
                end = end->next;
                delete cache;
            } 
        }
        friend ostream& operator <<(ostream &,poly);    //operator << overloading
        friend poly* operator +(poly&,poly&);    //operator + overloading
        poly& operator =(poly &x)    //operator = overloading
        {
            node *cache,*space;
            if(!(this->empty()))
                this->clear();
            cache = x.end;
            while(cache != x.head)
            {
                space = new node(cache->co,cache->ex);
                this->add(space);
                cache = cache->next;
            }
            return *this;
        }
        poly& operator =(poly *x)    //another operator << overloading
        {
            this->end = x->end;
            this->head = x->head;
            return *this;
        }
        friend poly* operator *(poly&,poly&);
};

int main()
{
    poly a,b,*plus,*mul;
    int p,q,c,e;    //p is a's size , q is b's size,coeffient,exponent
    node *input;
    while(cin >> p)
    {
        for(int i = 0 ; i < p ; i++)    //add p
        {
            cin >> c >> e;
            input = new node(c,e);
            a.add(input);
        }
        cin >> q;
        if(!p && !q)
            break;
        for(int i = 0 ; i < q ; i++)    //add q
        {
            cin >> c >> e;
            input = new node(c,e);
            b.add(input);
        }
        plus = (a+b);
        mul = (a*b);
        //output
        cout << "A:\n" << a ;
        cout << "B:\n" << b ;
        cout << "plus\n" << *plus;
        cout << "multiple\n" << *mul;
        a.clear();
        b.clear();
        plus->clear();
        mul->clear();
        //clean heap
        delete plus;
        delete mul;
    }
    return 0;
}

ostream& operator <<(ostream &s,poly x)
{
    int sum = 0;
    if(x.empty())      //if list is empty , print 0,0
        s << "(0 , 0)" << endl;
    else
    {
        node *cache;
        cache = x.end;
        while(cache != x.head)
        {
            if(cache->co != 0)
            {
                s << "(" << cache->co << " , " << cache->ex << ")" << endl;
                sum++;
            }
           
            cache = cache->next;
        }
         if(sum == 0)
                s << "(0 , 0)" << endl;
    }
    return s;
}

poly* operator +(poly &x,poly &y)
{
    poly *for_return = new poly;
    node *space,*cache;
    cache = x.end;
    while(cache != x.head)  //add node 
    {
        space = new node(cache->co,cache->ex);
        for_return->add(space);
        cache = cache ->next;
    }
    cache = y.end;
    while(cache != y.head)  //add node again
    {
        space = new node(cache->co,cache->ex);
        for_return->add(space);
        cache = cache ->next;
    }
    return for_return;
}
poly* operator *(poly &x,poly &y)
{
    poly *for_return = new poly;
    node *space,*nowx,*nowy;
    int c,e;
    nowx = x.end;
    while(nowx != x.head)
    {
        nowy = y.end;
        while(nowy != y.head)
        {
            c = nowy->co;
            c *= nowx->co;
            e = nowy->ex;
            e += nowx->ex;
            space = new node(c,e); 
            for_return->add(space);     //add node again and again
            nowy = nowy->next;
        }
        nowx = nowx->next;
    }
    return for_return;
}