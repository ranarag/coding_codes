#include<bits/stdc++.h>
using namespace std;
stack<int>Stack;
vector< vector<int>  > adj(100);
vector< vector<int> > bdj(100);
int visited[100];
void init(){
	for(int i=0;i<100;i++)
		visited[i]=0;
}
void topoSort(int v){
	visited[v]=1;
	vector<int>::iterator i;
	for(i=adj[v].begin();i!=adj[v].end();i++){
		if(!visited[*i])
			topoSort(*i);
	
	}
	Stack.push(v);
}
void reversei(int V){
	for(int i=0;i<V;i++){
		vector<int>::iterator j;
		for(j=adj[i].begin();j!=adj[i].end();j++){
			bdj[*j].push_back(i);
		}
	}
}
void printScc(int v){
	visited[v]=1;
	cout<<v<<" ";
	vector<int>::iterator i;
	for(i=bdj[v].begin();i!=bdj[v].end();i++){
		if(!visited[*i])
			printScc(*i);
	
	}
}
int main(void){
int n,m;
	init();
	cin>>n>>m;
	int x,y;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		adj[x].push_back(y);

	}
	for(int i=0;i<n;i++){
		if(!visited[i])
			topoSort(i);
	}
	reversei(n);
	init();
	while(!Stack.empty()){
		int k=Stack.top();
		Stack.pop();
		if(!visited[k]){
			printScc(k);
		cout<<"\n";}
		
	}

}