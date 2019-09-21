#include <iostream>
using namespace std;

/*
    author:b073040039
    date:2019/09/21
    purpose:魔方陣
*/

int main()
{
    cout << "1.\n\n1\n" << endl;  //1
    for(int i = 3 ; i <= 9 ; i+=2)  //不想一行一行打
    {
        int data[i][i];
        for(int j = 0 ; j < i ; j++)
            for(int k = 0 ; k < i ; k++)
                data[j][k] = 0;
        int nowi = 0 , nowj = (i/2);
        int filled = 1;     //該填入的東西
        data[nowi][nowj] = filled; //前置中
        
        while(filled <= i*i)    //配置中
        {
            nowi--;
            nowj--;
            if(nowi < 0)
                nowi += i;
            if(nowj < 0)
                nowj += i;
            if(data[nowi][nowj] == 0)
                data[nowi][nowj] = ++filled;    //填入
            else
                data[++nowi][nowj] = ++filled;  //填入
        }
        cout << i << ".\n" << endl;
        for(int j = 0 ; j < i ; j++)    //印出
        {
            for(int k = 0 ; k < i ; k++)
                cout << data[j][k] << " ";
            cout << endl;
        }
        cout << endl;
        cout << endl;
    }
}