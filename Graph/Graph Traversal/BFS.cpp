//###################	BREADTH-FIRST SEARCH (BFS)	###################

#include<bits/stdc++.h>
using namespace std;

vector<int> visited;				//to keep track of visited vertices
vector<vector<int>> adj;			//adjacency list

void edge(int a, int b)
{
	adj[a].push_back(b);
	//for undirected graph, uncomment below line
	//adj[b].push_back(a);
}

void bfs(int s)
{
	queue<int> q;
	visited[s]=1;
	q.push(s);
	while(!q.empty())
	{
		auto u = q.front();
		q.pop();
		cout<<u<<" ";
		for(auto v: adj[u])
		{
			if(!visited[v])
			{
				visited[v]=1;
				q.push(v);
			}
		}
	}
}

int main()
{
	int n, e;						//no. of vertices and no. of edges
	cin>>n>>e;
	visited.assign(n, 0);
	adj.assign(n, vector<int>());
	int a, b;
	for(int i=0;i<e;i++)
	{
		cin>>a>>b;
		edge(a, b);
	}
	cout<<"Breadth First Traversal:"<<endl;
	for(int i=0;i<n;i++)			//we are looping over all vertices because 
	{								//what if some vertices are not reachable from certain vertex
		if(!visited[i])
			bfs(i);
	}
}