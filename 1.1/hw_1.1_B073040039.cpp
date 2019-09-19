#include <iostream>
using namespace std;
//B073040039
// 09/09
int main()
{
    cout << "1.\n\n1\n" << endl;  
    for(int i = 3 ; i <= 9 ; i+=2)
    {
        int data[i][i];
        for(int j = 0 ; j < i ; j++)
            for(int k = 0 ; k < i ; k++)
                data[j][k] = 0;
        int nowi = 0 , nowj = (i/2);
        int filled = 1;
        data[nowi][nowj] = filled;
        
        while(filled <= i*i)
        {
            nowi--;
            nowj--;
            if(nowi < 0)
                nowi += i;
            if(nowj < 0)
                nowj += i;
            if(data[nowi][nowj] == 0)
                data[nowi][nowj] = ++filled;
            else
                data[++nowi][nowj] = ++filled;
        }
        cout << i << ".\n" << endl;
        for(int j = 0 ; j < i ; j++)
        {
            for(int k = 0 ; k < i ; k++)
                cout << data[j][k] << " ";
            cout << endl;
        }
        cout << endl;
        cout << endl;
    }
}