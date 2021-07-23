#include<bits/stdc++.h>
using namespace std;
 
#define lli long long int
#define lld long double
#define ff first
#define ss second
#define pb push_back
#define sz(x) (x).size()
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define mp make_pair
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a*b)/__gcd(a, b)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
 
const lli N = 5e3+5;
const lli INF = 1e9+9;
const lli mod = 1e9+7;

//*************** Minimum Spanning Tree ***************

//A spanning tree is a set of edges such that any vertex can reach any other by exactly one simple path. 
//The spanning tree with the least weight is called a minimum spanning tree.

//The maximum spanning tree (spanning tree with the sum of weights of edges being maximum) of a graph can be obtained 
//similarly to that of the minimum spanning tree, by changing the signs of the weights of all the edges to their opposite 
//and then applying any of the minimum spanning tree algorithm.

//*************** Prim's Algorithm ***************

//For Dense Graph: O(n^2)

//1. Select node with minimum weight (Select source node first)
//Initially all the nodes are INF except the source node(1).
//2. Mark selected node as visited
//3. Update parent pointer of this node
//4. Relax/Compute all the adjacent edges to this node, 
//bcz this node is no longer in the non-selected set.


vector<vector<int>> adj;
vector<pair<int, int>> min_edge;
vector<int> vis, parent;

void prim(int n)
{
	int i, j, v, total_weight = 0;
	min_edge[1].ff=0;
	
	for(i=1; i<=n; i++)
	{
		v = -1;
		for(j=1; j<=n; j++)
		{
			if(!vis[j] && (v==-1 || min_edge[j].ff < min_edge[v].ff))		//Finding node with min edge weight
				v = j;
		}

		if(min_edge[v].ff == INF)
		{
			cout<<"No MST!"<<endl;
			return;
		}

		vis[v]=1;
		total_weight += min_edge[v].ff;

		parent[v] = min_edge[v].ss;			//Updating parent pointer

		for(j=1; j<=n; j++)
		{											//Relaxing or Updating adjacent edges of this node
			if(adj[v][j] < min_edge[j].ff)			//Now v is in the selected set, we will update min weight edge coming out from vertex j and has another vertex (v) in selected set.
				min_edge[j] = mp(adj[v][j], v);
		} 
	}
	
	for(i=2; i<=n; i++)
	{
		cout<<"Edge: "<<i<<" "<<parent[i]<<" Weight: "<<adj[i][parent[i]]<<endl;
	}
	cout<<endl;
	cout<<"Total Weight: "<<total_weight<<endl;
}

int main()
{
	int n, m;
	cin>>n>>m;
	adj.assign(n+1, vector<lli>(n+1, INF));
	vis.assign(n+1, 0);
	parent.assign(n+1, -1);
	min_edge.assign(n+1, mp(INF, -1));
	int i, u, v, w;
	for(i=1; i<=m; i++)
	{
		cin>>u>>v>>w;
		adj[u][v]=w;
		adj[v][u]=w;
	}
	prim(n);
}


//For Sparse Graph: O(m * logn)

//Here we are using set to find node for which edge weight is minimum.


vector<vector<pair<int, int>>> adj;
vector<pair<int, int>> min_edge;
vector<int> vis, parent;

void prim(int n)
{
	set<pair<int, int>> q;
	q.insert(mp(0, 1));
	int i, j, v, total_weight = 0;
	min_edge[1].ff=0;

	for(i=1; i<=n; i++)
	{
		if(q.empty())
		{
			cout<<"No MST!"<<endl;
			return;
		}
		v = (*q.begin()).ss;
		vis[v]=1;
		total_weight += (*q.begin()).ff;
		q.erase(q.begin());

		parent[v] = min_edge[v].ss;

		for(auto j: adj[v])
		{
			if(!vis[j.ss] && j.ff < min_edge[j.ss].ff)
			{
				q.erase(mp(min_edge[j.ss].ff, j.ss));
				min_edge[j.ss] = mp(j.ff, v);
				q.insert(mp(j.ff, j.ss));
			}
		}
	}

	for(i=2; i<=n; i++)
	{
		cout<<"Edge: "<<i<<" "<<parent[i]<<endl;
	}
	cout<<endl;
	cout<<"Total Weight: "<<total_weight<<endl;

}

int main()
{
	int n, m;
	cin>>n>>m;
	adj.assign(n+1, vector<pair<int, int>> ());
	vis.assign(n+1, 0);
	parent.assign(n+1, -1);
	min_edge.assign(n+1, mp(INF, -1));
	int i, u, v, w;
	for(i=1; i<=m; i++)
	{
		cin>>u>>v>>w;
		adj[u].pb(mp(w, v));
		adj[v].pb(mp(w, u));
	}
	prim(n);

}


/*Sample Input(gfg):
5 7
1 2 2
1 4 6
2 3 3
2 4 8
2 5 5
3 5 7
4 5 9
*/