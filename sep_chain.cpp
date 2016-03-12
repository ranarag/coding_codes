#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
vector< string > h[20];

//////////////////////////////////////////////////
// HASH FUNCTION
//////////////////////////////////////////////////
int hashFunc(string s)
{
	int c=0;
	for(int i=0;i<s.length();i++)
		c+=(int)s[i];
	return c%20;
}
///////////////////////////////////////////////////////
//FUNCTION TO INSERT IN HASH TABLE
/////////////////////////////////////////////////////
void insert(string s)
{
	int index = hashFunc(s);
	h[index].push_back(s);
}
//////////////////////////////////////////////////////
//FUNCTION TO SEARCH FROM HASH TABLE
//////////////////////////////////////////////////////
void search(string s)
{
	int index = hashFunc(s);
	for(int i=0;i<h[index].size();i++)
	{
		if(h[index][i]==s)
		{
			cout<<s<<" present in table\n";
			return ;
		}

	}
	cout<<s<<" not present\n";
}
////////////////////////////////////////////////////////
//FUNCTION TO DELETE FROM HASH TABLE
////////////////////////////////////////////////////////
void del(string s)
{
	int index = hashFunc(s);
	for(int i=0;i<h[index].size();i++)
	{
		
	}
	cout<<s<<" not present\n";

}
/////////////////////////////////////////////////////////
// DRIVER PROGRAM
////////////////////////////////////////////////////////
int main(void)
{
	string s[100];
	cout<<"enter strings\n";
	for(int i=0;i<3;i++)cin>>s[i],insert(s[i]);
		cout<<"enter string to search\n";
	string v;
	cin>>v;
	search(v);
	//del(v);

}