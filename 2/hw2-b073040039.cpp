#include <iostream>
#include <map>
#include <string>
#include <conio.h>
/*
	author:b073040039
	date:2019/09/30
	description:set operator redefine
*/
using namespace std;
class Tset		//
{
	public:
		map<char,int>data;
		friend Tset operator +(Tset &,Tset &);	//+
		friend Tset operator *(Tset &,Tset &);	//*
		friend Tset operator -(Tset &,Tset &);	//-
};

int main()
{
	int num , i;
	string c;
	while(cin >> num)
	{
		char cache[num];	//第三個輸入
		Tset input[num][2];		//A,B
		for(int j = 0 ; j < num ;  j++)
		{
			cin.ignore(1);	//防geline吃'\n'
			for(int i = 0 ; i < 2 ; i++)
			{
				getline(cin,c);		//輸入資料
				for(int k = 0 ; k < c.length() ; k++)
					input[j][i].data[c[k]]++;
			}
			cache[j] = getchar();
		}
		for(int j = 0 ; j < num ; j++)
		{
			Tset cc, d , e ,f;
			cout << "Test Case " << j+1 << ":" << endl;
			cout << "A : {";	//印出A
			for(map<char,int>::iterator p = input[j][0].data.begin() ; p  !=  input[j][0].data.end() ; p++)
				cout << p->first;		
			cout << "}" << endl;
			cout << "B : {";	//印出B
			for(map<char,int>::iterator p = input[j][1].data.begin() ; p  !=  input[j][1].data.end() ; p++)
				cout << p->first;
			cout << "}" << endl;
			//題目要求
			cc = input[j][0] + input[j][1];
			d = input[j][0] * input[j][1];
			e = input[j][0] - input[j][1];
			f = input[j][1] - input[j][0];
			cout << "A+B : {";	//A+B
			for(map<char,int>::iterator p = cc.data.begin() ; p != cc.data.end() ; p++)
				cout << p->first;
			cout << "}" << endl;
			cout << "A*B : {";	//A*B
			for(map<char,int>::iterator p = d.data.begin() ; p != d.data.end() ; p++)
				cout << p->first;
			cout << "}" << endl;
			cout << "A-B : {";	//A-B
			for(map<char,int>::iterator p = e.data.begin() ; p != e.data.end() ; p++)
				cout << p->first;
			cout << "}" << endl;
			cout << "B-A : {";	//B-A
			for(map<char,int>::iterator p = f.data.begin() ; p != f.data.end() ; p++)
				cout << p->first;
			cout << "}" << endl;
			bool flag = true;
			for(map<char,int>::iterator p = input[j][1].data.begin() ; p != input[j][1].data.end() ; p++)
				if((input[j][0].data)[p->first] == 0)
					flag = false;	//檢查元素是否存在
			if(flag)
				cout << "A contains B" << endl;
			else
				cout << "A does not contain B" << endl;
			flag = true;	//檢查元素是否存
			for(map<char,int>::iterator p = input[j][0].data.begin() ; p != input[j][0].data.end() ; p++)
				if((input[j][1].data)[p->first] == 0)
					flag = false;
			if(flag)
				cout << "B contains A" << endl;
			else
				cout << "B does not contain A" << endl;
			cout << "\'" << cache[j] << "\' is ";
			if((input[j][0].data)[cache[j]])
				cout << "in A" << endl;
			else
				cout << "not in A" << endl;
			cout << "\'" << cache[j] << "\' is ";
			if((input[j][1].data)[cache[j]])
				cout << "in B" << endl;
			else
				cout << "not in B" << endl;


		}

	}
	return 0;
}

Tset operator +(Tset &x,Tset &y)	//+
{
	Tset r;
	for(map<char,int>::iterator p = x.data.begin() ; p != x.data.end() ; p++)
		r.data[p->first]++;
	for(map<char,int>::iterator p = y.data.begin() ; p != y.data.end() ; p++)
		r.data[p->first]++;
	return r;
}

Tset operator *(Tset &x,Tset &y)
{
	Tset r;
	for(map<char,int>::iterator p = x.data.begin() ; p != x.data.end() ; p++)
		if(y.data[p->first] > 0)
			r.data[p->first]++;
	return r;
}

Tset operator -(Tset &x,Tset &y)
{
	Tset r;
	for(map<char,int>::iterator p = x.data.begin() ; p != x.data.end() ; p++)
		if(y.data[p->first] == 0)
			r.data[p->first]++;
	return r;
}
