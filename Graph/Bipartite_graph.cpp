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
 
const int N = 5e3+5;
const lli INF = 1e9+9;
const lli mod = 1e9+7;

//---------- Check whether a graph is bipartite ----------

//A bipartite graph is a graph whose vertices can be divided into two disjoint sets,
//so that every edge connects two vertices from different sets 
//(i.e. there are no edges which connect vertices from the same set). 
//These sets are usually called sides.
//You are given an undirected graph. 
//Check whether it is bipartite, and if it is, output its sides.

//Here alternatively assign side number to adjacent vertices, 
//if neighbour vertex has been visited and both adjacent vertices have same side assigned
//it means the graph is not bipartite.

vector<vector<int>> adj;
vector<int> side;

bool isbipartite(int n)
{
	bool flag=true;
	queue<int> q;
	for(i=1; i<=n; i++)
	{
		if(side[i]==-1)
		{
			q.push(i);
			side[i]=0;
			while(!q.empty())
			{
				auto u = q.front;
				q.pop();
				for(auto v: adj[u])
				{
					if(side[u]==-1)
					{
						side[u] = side[v]^1;
						q.push(v);
					}
					else
					{
						flag &= (side[u]!=side[v]);
					}
				}
			}
		}
	}
	return flag;
}

void solve()
{
	int n, m;
	cin>>n>>m;
	int i, u, v;
	adj.assign(n+1, vector<int>());
	side.assign(n+1, -1);
	for(i=1; i<=m; i++)
	{
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	cout<<(isbipartite(n)?"YES":"NO")<<endl;;
}

int main()
{
    fast;
    lli t=1;
    cin>>t;
    for(lli i=1; i<=t; i++)
    {
        //cout<<"Case #"<<i<<": ";
        solve();
    }
}