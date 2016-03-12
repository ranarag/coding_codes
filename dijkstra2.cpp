#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;
int MAX = 100;
vector<pair <int,int> >graph[100];
bool visited[100];
int dist[100];
int V;
void init()
{
	for(int i=0;i<MAX;i++)
	{	
		dist[i] = INT_MAX;
		visited[i] = false;
	}
}
int minDist()
{
	int mini = INT_MAX,minVertex;
	for(int i=0;i<V;i++)
	{
		if(!visited[i]&& dist[i]<mini)
			mini= dist[i],minVertex=i;
	}
	return minVertex;
}
void dijkstra(int source)
{
	init();
	//cout<<"ok\n";
	dist[source] = 0;
	//visited[source] = true;
	for(int i=0;i< V;i++)
	{
		int u = minDist();
		visited[u] = true;
		for(int j = 0;j<graph[u].size();j++)
		{
			int v =graph[u][j].second;
			int w = graph[u][j].first;
			if(!visited[v] && dist[u]!=INT_MAX && (dist[u] + w <dist[v] ))
				dist[v] =dist[u] + w;
		}
	}
	for(int i=0;i<V;i++)
	{
		cout<<"vertex = "<<i<<" dist ="<<dist[i]<<endl;
	}

}

int main(void)
{
	cout<<"Enter no of vertex\n";
	cin>>V;
	cout<<"Enter no of Edges\n";
	int e;
	cin>>e;
	int u,v,w;
	for(int i=0;i<e;i++)
	{
		cin>>u>>v>>w;
		graph[u].push_back(make_pair(w, v));
	}
	//cout<<"ok\n";
	dijkstra(0);

}