#include <iostream>
#include <cstring>
using namespace std;
/*
    Author:B073040039
    Date:2019/09/21
    Purpose:階層(大數版)
*/
int main()
{
    int data[1000] , num;   //data是大數資料模板,num是輸入測資
    bool flag;  //用來避免印出沒必要的位數
    while(cin >> num && num)
    {
        memset(data , 0 , sizeof(int)*1000);    //初始化陣列
        data[0] = 1;    
        cout << "1!\t=\t1" << endl;  //'\t'用來排版
        for(int i = 2 ; i <= num ; i++)     //我不想打num-1次,所以用迴圈
        {
            flag = false;   //重置判斷變數            
            cout << i << "!\t=\t";  //排版
            for(int j = 0 ; j < 1000 ; j++)
                data[j] *= i;  //現有資料*i
            for(int j = 0 ; j < 999 ; j++)  //用來進位的迴圈
            {
                data[j+1] += data[j] / 10;
                data[j] %= 10;
            }
            for(int j = 999 ; j >= 0 ; j--) //避免不必要的位數印出
            {
                if(data[j] != 0)
                    flag = true;   //flag = true 開始輸出
                if(flag)
                    cout << data[j];
            }
            cout << endl;
        }
    }
    return 0;
}