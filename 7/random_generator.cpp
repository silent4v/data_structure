#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#define SIZE 500000
using namespace std;
int main()
{
    srand(time(NULL));
    ofstream file;
    file.open("input.txt",ios::trunc);
    for(int i = 0 ; i < 10 ; i++)
    {
        file << SIZE << endl;
        for(int j = 0 ; j < SIZE ; j++)
            file << rand() << " ";
        file << endl;
    }
    file.close();
    return 0;
}