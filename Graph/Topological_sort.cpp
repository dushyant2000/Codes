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

//###################	Topological Sort	###################
//Which means if there is an edge from u to v, then in u will come before v in topological order
//The desired topological ordering is sorting vertices in descending order of their exit times.

vector<vector<int>> adj;
vector<int> visited, vec;

void topological(int s)
{
	visited[s]=1;
	for(auto i: adj[s])
	{
		if(!visited[i])
		{
			topological(i);
		}
	}
	vec.pb(s);
}

int main()
{
	int n, m;							
	cin>>n>>m;
	visited.assign(n+1, 0);
	adj.assign(n+1, vector<int>());
	int i, u, v;
	for(i=0;i<m;i++)
	{
		cin>>u>>v;
		adj[u].pb(v);
	}
	for(i=1; i<=n; i++)
	{
		if(!visited[i])
			topological(i);
	}
	reverse(all(vec));
	for(i=0; i<vec.size(); i++) cout<<vec[i]<<" ";
}