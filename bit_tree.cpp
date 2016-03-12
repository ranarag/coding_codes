#include <iostream>
using namespace std;
const int MAX = 1e4+5;
int BIT[MAX];
int a[MAX];
int n;
int update(int x, int val)
{
	for(;x <= n;x += x&-x)
		BIT[x] += val;
}
int query(int x)
{
	int sum = 0;
	for(;x>0;x -= x&-x)
		sum += BIT[x];
	return sum;
}
int main(void)
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		update(i, a[i]);
	}
	//for(int i=0;i<=n;i++)
		//cout<<BIT[i]<<endl;
	cout<<query(2)<<endl;
}