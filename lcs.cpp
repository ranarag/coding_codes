#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>

using namespace std;
void lcs(char a[],char b[],int n,int m){
int lcs[n+1][m+1];
char c[100];
int k=0;


for(int i=0;i<=n;i++){
	for(int j=0;j<=m;j++){
		if(i==0||j==0)
		lcs[i][j]=0;
		else{
		if(a[i-1]==b[j-1]){
		lcs[i][j]=lcs[i-1][j-1]+1;}
		//c[k++]=a[i];}
		else{
		lcs[i][j]=max(lcs[i][j-1],lcs[i-1][j]);
		
		}
		}
		}
}

	/*c[lcs[n][m]]='\0';
	int i=n,j=m;
	int index=lcs[n][m];
//index-=1;
	while(i>0&&j>0){
		if(a[i-1]==b[j-1]){
			c[--index]=a[i-1];

			i--;
			j--;

		}
		else if(lcs[i-1][j]>lcs[i][j-1])
			i--;
		else
			j--;
	}*/
	int i=1,j=1;
	 k=0;
	while(i<=n&&j<=m){
	//cout<<a[i-1]<<" "<<b[j-1]<<"  "<<i<<" "<<j<<endl;
		if(a[i-1]==b[j-1]){
		//cout<<a[i-1]<<endl;
			c[k++]=a[i-1];
			i++;
			j++;
		}
		else if(i==n)
			j++;
		else if(j==n)
			i++;
		else if(lcs[i+1][j]>=lcs[i][j+1])
			i++;
		else
		j++;
	}
	c[k]='\0';
	//c[lcs[n][m]]='\0';
	cout<<c<<" "<<lcs[n][m]<<endl;
}
int main(void){
	int n,m;
	cin>>n>>m;
	char a[1000],b[1000];
	scanf("%s",a);
	scanf("%s",b);
	lcs(a,b,n,m);

}

