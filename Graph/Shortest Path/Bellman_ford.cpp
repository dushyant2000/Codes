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
 
const lli N = 1e5+5;
const lli INF = 1e6+9;
const lli mod = 1000000007;

//###################	Bellman-Ford	###################

vector<vector<pair<int, int>>> adj;		//adjacency list storing neighbour vertices and weights of the edges
vector<int> d;

int shortest_path(int s, int n)
{
	int flag=0;					//to check if there is any negative weight cycle
	d[s]=0;

	for(int i=1;i<n;i++)
	{
		for(int u=1;u<=n;u++)
		{
			for(auto j: adj[u])
			{
				int v = j.ff;
				int w = j.ss;

				if(d[v]>d[u]+w)				//RELAX(u, v, w)
				{
					d[v]=d[u]+w;
				}
			}
		}
	}

	for(int u=1;u<=n;u++)
	{
		for(auto j: adj[u])
		{
			int v = j.ff;
			int w = j.ss;
			
			if(d[v]>d[u]+w)					//If it is still not minimum means there is a negative weight cycle
			{
				flag=-1;
			}
		}
	}
	return flag;
}


int main()
{
	int n, m;
	cin>>n>>m;

	d.assign(n+1, INF);
	adj.assign(n+1, vector<pair<int, int>>());

	int i, u, v, w;
	for(i=1; i<=m; i++)
	{
		cin>>u>>v>>w;
		adj[u].pb(mp(v, w));
		adj[v].pb(mp(u, w));
	}

	int flag=0, s=1;
	flag = shortest_path(s, n);
	
	if(flag==-1)
	{
		cout<<"There is a negative weight cycle."<<endl;
		return 0;
	}

	cout<<"Vertex\t"<<"Distance from source vertex "<<s<<endl;
	for(i=1;i<=n;i++)
	{
		cout<<i<<"\t"<<d[i]<<endl;
	}
}