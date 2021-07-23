#include<bits/stdc++.h>
using namespace std;

void floyd_warshall(int** g, int V, int E)
{
	int i, j, k, dist[V][V];

	for(i=0;i<V;i++)
	{
		for(j=0;j<V;j++)	dist[i][j] = g[i][j];
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<V;j++)
		{
			for(k=0;k<V;k++)
			{
				if(dist[i][j]<dist[i][k]+dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	cout<<"Distance matirx:-"<<endl;

	for(i=0;i<V;i++)
	{
		for(j=0;j<n;j++)
		{
			if(dist[i][j]==inf) cout<<"inf ";
			else cout<<dist[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	int V, E;
	cin>>V>>E;

	int** g;
	g = new int*[V];
	for(i=0;i<V;i++) g[i] = new int[V];
	memset(g, inf, sizeof g);

	for(i=0;i<V;i++) g[i][i]=0;

	for(i=0;i<E;i++)
	{
		cin>>u>>v>>w;
		g[u][v]=w;
	}

	floyd_warshall(g, V, E);
}