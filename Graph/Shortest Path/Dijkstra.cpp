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
 
const lli N = 1e3+5;
const lli INF = 1e6+9;
const lli mod = 1000000007;

//###################	Dijkstra's Algorithm	###################
//Time complexity - O(VlogV + E) for Fibonacci Heap
//					O(V^2) for Priority Queue

vector<vector<pair<int, int>>> adj;
vector<int> d, parent;

void shortest_path(int s, int n)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	
	d[s]=0;
	q.push({d[s], s});

	while(!q.empty())
	{
		int u = q.top().ss;
		q.pop();
		
		for(auto i: adj[u])
		{
			int v = i.ff, w = i.ss;
			if(d[v] > d[u]+w)
			{
				d[v] = d[u]+w;
				parent[v] = u;
				q.push({d[v], v});
			}
		}
	}
}


int main()
{
	int n, m;
	cin>>n>>m;
	adj.assign(n+1, vector<pair<int, int>>());
	d.assign(n+1, INF);
	int i, u, v, w;
	for(i=1; i<=m; i++)
	{
		cin>>u>>v>>w;
		adj[u].pb(mp(v, w));
		adj[v].pb(mp(u, w));
	}

	int s=2;
	shortest_path(s, n);
	cout<<"Vertex\t"<<"Distance from source vertex "<<s<<endl;
	for(i=1; i<=n; i++)
	{
		cout<<i<<"\t"<<d[i]<<endl;
	}
}
