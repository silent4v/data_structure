#include <iostream>
#include <map>
using namespace std;
class Tset
{
	public:
		map<char,int>data;
		friend Tset operator +(Tset &,Tset &);
		friend Tset operator *(Tset &,Tset &);
		friend Tset operator -(Tset &,Tset &);
};

int main()
{
	int num , i;
	string c;
	char cache;
	while(cin >> num)
	{
		Tset input[num][2];
		for(int j = 0 ; j < num ;  j++)
		{
			cin.ignore(1);
			for(int i = 0 ; i < 2 ; i++)
			{
				getline(cin,c);
				cout << c << endl;
				for(int k = 0 ; k < c.length() ; k++)
					input[j][i].data[c[k]]++;
			}
			cin >> cache;
		}
		for(int j = 0 ; j < num ; j++)
		{
			Tset cc, d , e ,f;
			cout << "Test Case " << j+1 << ":" << endl;
			cout << "A : {";
			for(map<char,int>::iterator p = input[j][0].data.begin() ; p  !=  input[j][0].data.end() ; p++)
				cout << p->first;
			cout << "}" << endl;
			cout << "B : {";
			for(map<char,int>::iterator p = input[j][1].data.begin() ; p  !=  input[j][1].data.end() ; p++)
				cout << p->first;
			cout << "}" << endl;
			cc = input[j][0] + input[j][1];
			d = input[j][0] * input[j][1];
			e = input[j][0] - input[j][1];
			f = input[j][1] - input[j][0];
			cout << "A+B : {";
			for(map<char,int>::iterator p = cc.data.begin() ; p != cc.data.end() ; p++)
				cout << p->first;
			cout << "}" << endl;
			cout << "A*B : {";
			for(map<char,int>::iterator p = d.data.begin() ; p != d.data.end() ; p++)
				cout << p->first;
			cout << "}" << endl;
			cout << "A-B : {";
			for(map<char,int>::iterator p = e.data.begin() ; p != e.data.end() ; p++)
				cout << p->first;
			cout << "}" << endl;
			cout << "B-A : {";
			for(map<char,int>::iterator p = f.data.begin() ; p != f.data.end() ; p++)
				cout << p->first;
			cout << "}" << endl;

		}

	}
	return 0;
}

Tset operator +(Tset &x,Tset &y)
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
	for(map<char,int>::iterator p = y.data.begin() ; p != y.data.end() ; p++)
		if(x.data[p->first] > 0)
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
