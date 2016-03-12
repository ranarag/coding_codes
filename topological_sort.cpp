#include<bits/stdc++.h>
using namespace std;
stack<int>Stack;
vector< vector<int>  > adj(100);
//vector<int> adj[100];
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

int main(void){
	int n,m;
	//adj = new list<int>[n];
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
	while(!Stack.empty()){
		cout<<Stack.top()<<" ";
		Stack.pop();
	}
	//delete [] adj;
}
