#include<stdio.h>
#include<stdlib.h>

void countingSort(int a[],int b[],int n,int r)
{
	int i=0;
	int c[r];
	for(i=0;i<r;i++)c[i]=0;
	for(i=0;i<n;i++)c[a[i]]++;
	for(i=1;i<r;i++)c[i]+=c[i-1];

	for(i=0;i<n;i++){
		b[c[a[i]]-1]=a[i];
		c[a[i]]--;}
}

int main(void)
{
	int n;
	scanf("%d",&n);
	int i;
	int a[n];
	int b[n];
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	countingSort(a,b,n,9);
	printf("\n");
	for(i=0;i<n;i++)
		printf("%d ",b[i]);
	printf("\n");
}
	
