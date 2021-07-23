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

//###################	Floyd Warshall Algorithm	###################

vector<vector<pair<int, int>>> adj;
int weight[N][N], dist[N][N];

void shortest_path(int n)
{
	int i, j, k;
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=n; j++) dist[i][j]=weight[i][j];
	}

	for(k=1; k<=n; k++)
	{
		for(i=1; i<=n; i++)
		{
			for(j=1; j<=n; j++)
			{
				if(dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

}

int main()
{
	int n, m;
	cin>>n>>m;
	int i, j, u, v, w;
	adj.assign(n+1, vector<pair<int,int>>());
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=n; j++)
		{
			if(i!=j) weight[i][j]=INF;
			else weight[i][j]=0;
		}
	}
	for(i=1; i<=m; i++)
	{
		cin>>u>>v>>w;
		adj[u].pb(mp(v, w));
		weight[u][v]=w;
	}
	shortest_path(n);
	cout<<"Shortest distances between every pair of vertices: "<<endl;
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=n; j++)
		{
			if(dist[i][j]>=INF) cout<<"INF ";
			else cout<<dist[i][j]<<" ";
		}
		cout<<endl;
	}
}
