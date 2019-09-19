#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int data[1000] , num;
    bool flag;
    while(cin >> num && num)
    {
        memset(data , 0 , sizeof(int)*1000);
        data[0] = 1;
        cout << "1!\t=\t1" << endl;  //'\t'用來排版
        for(int i = 2 ; i <= num ; i++)
        {
            flag = false;            
            cout << i << "!\t=\t";
            for(int j = 0 ; j < 1000 ; j++)
                data[j] *= i;
            for(int j = 0 ; j < 999 ; j++)
            {
                data[j+1] += data[j] / 10;
                data[j] %= 10;
            }
            for(int j = 999 ; j >= 0 ; j--)
            {
                if(data[j] != 0)
                    flag = true;
                if(flag)
                    cout << data[j];
            }
            cout << endl;
        }
    }
    return 0;
}