//###################	DEAPTH-FIRST SEARCH (DFS)	###################

#include<bits/stdc++.h>
using namespace std;

vector<int> visited;					//to keep track of visited vertices
vector<vector<int>> adj;				//adjacency list

void DFS_visit(int);

void add_edge(int a, int b)
{
	adj[a].push_back(b);
	//for undirected graph, uncomment the below line
	//adj[b].push_back(a);
}

void DFS(int v)
{
	for(int i=0;i<v;i++)	//looping to handle a corner case of a disconnected graph
	{
		if(!visited[i])
		{
			DFS_visit(i);
		}
	}
}

void DFS_visit(int s)
{
	visited[s]=1;
	cout<<s<<" ";
	for(auto i:adj[s])
	{
		if(!visited[i])
		{
			visited[i]=1;
			DFS_visit(i);
		}
	}
}

int main()
{
	int v,e;							//no. of vertices and no. of edges
	cin>>v>>e;
	int i, a, b;
	visited.assign(v, 0);
	adj.assign(v, vector<int>());
	for(i=0;i<e;i++)
	{
		cin>>a>>b;
		add_edge(a, b);
	}
	cout<<"Depth First Traversal:"<<endl;
	DFS(v);
}