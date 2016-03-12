#include<bits/stdc++.h>
using namespace std;
vector< vector<float> > v(100);
void bubbleSort(int l)
{
	float tmp;
	int swp;
	int n=v[l].size();
	if(!n)
	return;
	for(int i=0;i<n;i++){
		swp=0;
		for(int j=0;j<n-1-i;j++)
		{
			if(v[l][j+1]<v[l][j])
			{
				swp=1;
				tmp=v[l][j+1];
				v[l][j+1]=v[l][j];
				v[l][j]=tmp;
			}
		}
			if(!swp)
			break;
	}	
}
void Print(int j){
	int n=v[j].size();
	if(!n)
	return;
	for(int i=0;i<n;i++)cout<<v[j][i]<<" ";}
void bucketSort(float a[],int n)
{
	for(int i=0;i<n;i++)v[floor(log(a[i]*100))].push_back(a[i]);
	for(int i=0;i<n;i++)bubbleSort(i);
	for(int i=0;i<n;i++)Print(i);
}
int main(void){
	int n;
	cin>>n;
	float a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	bucketSort(a,n);
	}
