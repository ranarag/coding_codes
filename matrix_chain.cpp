#include<bits/stdc++.h>
using namespace std;
void printchain(int *s[],int i,int j){
if(j==0)
return;
if(i==j){
cout<<"A"<<i;
return;
}
else{
cout<<"(";
printchain(s,i,s[i][j]);
printchain(s,s[i][j]+1,j);
cout<<")";
}
return;
}
void matrix_dp(int p[],int n){
int m[n][n];
int *s[n];
for(int i=0;i<=n;i++)
s[i]=new int[n];

int j;
for(int i=0;i<=n;i++)
m[i][i]=0;
for(int l = 2;l<=n;l++){

	for(int i=0;i<n-l+1;i++){
	j=i+l-1;
	m[i][j]=INT_MAX;
	for(int k=i;k<j;k++){
	int q = m[i][k]+m[k+1][j]+p[i]*p[k]*p[j];
		if(q<m[i][j]){
		m[i][j]=q;
		s[i][j]=k;
		}	
	}
	
	}
}
cout<<m[0][n-1]<<endl;
printchain(s,0,n-1);

}

int main(void){
int p[100];
int n;
cin>>n;
for(int i=0;i<=n;i++){
	cin>>p[i];

}
matrix_dp(p,n+1);
cout<<endl;
}
