#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int MAX = 1e4+5;
int f[MAX];
int l;
char p[MAX];
void init()
{
	for(int i=0;i<=l;i++)f[i]=0;
}
void failure_function()
{
	//int l = strlen(p);
	init();
	int j=0;
	for(int i=1;i<l;i++)
	{
		while(j>=0&&p[j]!=p[i])
		{
			if(j-1>=0)
				j = f[j-1];
			else
				j = -1;
		}
		j += 1;
		f[i] = j;
	}

}
void find_occurrences()
{
	failure_function();
	int lp = l;
	char c=getchar();
	int j=0,i=0;
	while((c = getchar())!='\n')
	{
		if(c==EOF)
		exit(1);
		while(j>=0&&c!=p[j])
		{
			if(j-1>=0)
				j = f[j-1];
			else
				j = -1;
		}
		j+=1;
		if(j==lp)
		{
			j = f[lp-1];
			cout<<i-lp+1<<endl;
		}
		i++;
	}
	if(c==EOF)
		exit(1);
	
}
int main(void)
{
	while(1)
	{
	scanf("%d",&l);
	scanf("%s",p);
	
	find_occurrences();
	}
}