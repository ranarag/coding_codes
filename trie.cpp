#include <bits/stdc++.h>
using namespace std;
////////////////////////////////////////////
// TRIE STRUCTURE
////////////////////////////////////////////
typedef struct trie{
	int eos;
	trie *child[26];
}trie;
char s2[30];
////////////////////////////////////////////
//NEW NODE ROUTINE
///////////////////////////////////////////
trie *getNewNode(){
	trie *temp = new trie;
	temp->eos=0;
	for(int i=0;i<26;i++)
		temp->child[i]=NULL;
	return temp;
}
///////////////////////////////////////////////
// TRIE INSERT ROUTINE
////////////////////////////////////////////
trie *insert(trie *root,char *word){
	int n=strlen(word);
	if(word==NULL)
		return root;
	if(root==NULL)
		root = getNewNode();
	trie *temp=root;
	for(int i=0;i<n;i++){
		int ind = word[i] - 'a';
		if(temp->child[ind]==NULL)
			temp->child[ind]=getNewNode();
		temp=temp->child[ind];
	}
	temp->eos = 1;
	return root;
}
//////////////////////////////////////
// TRIE TRAVERSE ROUTINE
//////////////////////////////////////
long long counti(trie *root,int k){

	if(root==NULL||k<0)
		return 0;
	/*if(k>=1&&root->eos==1)
		return 1;*/
	long long ans = 0;
	for(int i=0;i<26;i++){
		trie *temp = root->child[i];
		if(temp==NULL)
			continue;
		if((int)(s2[i]-'0')==1){
			ans++;
			ans+=counti(temp,k);
		}
		else{
			if(k>=1)
				ans++;
			ans+=counti(temp,k-1);
		}
	}
	return ans;
}
/////////////////////////////////////////
// DRIVER ROUTINE
////////////////////////////////////////
int main(void){

char s[10000],s3[10000];
scanf("%s",s);
trie *root=NULL;
root = insert(root,s);
//cout<<"ok\n";
scanf("%s",s2);
int k;

int l = strlen(s);
//cout<<l<<endl;
for(int i=0;i<l;i++){
	int v=0;
	for(int j=i;j<l;j++){
		s3[v++]=s[j];
	}
	s3[v]='\0';
	root=insert(root,s3);
	//cout<<"ok\n";
}
cin>>k;
cout<<counti(root,k)<<endl;		}