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
 
const lli N = 2e5+5;
const lli INF = 1e15+9;
const lli mod = 1000000007;

vector<vector<int>> adj;
vector<int> color, mark, parent;
int num_cycle=0;

//###################	Printing all cycles in an undirected graph	###################
//Maintain parent and color array, if for any node color=1 then there is a cycle 
//then we will backtrack the cycle using parent array and mark all the vertices with the cycle number

void dfs_cycle(int s, int p)
{
	if(color[s]==2) return;

	if(color[s]==1)
	{
		num_cycle++;
		int curr = p;
		mark[p]=num_cycle;

		while(curr!=s)
		{
			curr = parent[curr];
			mark[curr] = num_cycle;
		}
		return;
	}

	parent[s]=p;
	color[s]=1;
	for(auto u: adj[s])
	{
		if(u!=p)
			dfs_cycle(u, s);
	}
	color[s]=2;

}

int main()
{
	int n, m;
	cin>>n>>m;
	adj.assign(n+1, vector<int>());
	color.assign(n+1, 0);
	mark.assign(n+1, 0);
	parent.assign(n+1, 0);
	int i, u, v;
	for(i=1; i<=m; i++)
	{
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for(i=1; i<=n; i++)
	{
		if(color[i]==0)
		{
			dfs_cycle(i, 0);
		}
	}

	vector<vector<int>> cycles(num_cycle+1);

	for(i=1; i<=n; i++)
	{
		if(mark[i]!=0)
			cycles[mark[i]].pb(i);
	}

	for(i=1; i<=num_cycle; i++)
	{
		cout<<"Cycle "<<i<<": ";
		for(auto j: cycles[i])
			cout<<j<<" ";
		cout<<endl;
	}
}