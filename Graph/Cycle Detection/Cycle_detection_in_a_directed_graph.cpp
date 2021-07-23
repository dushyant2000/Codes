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

//###################	Cycle detection in a directed graph	###################
//color=0 means unvisited
//color=1 means visiting
//color=2 means visited
//If adjacent node of any vertex has color=1 then there is a cycle

vector<vector<int>> adj;
vector<int> color;

bool cycle_detection(int s)
{
	color[s]=1;
	bool res=false;
	for(auto i: adj[s])
	{
		if(color[i]==0)
			res |= cycle_detection(i);
		else if(color[i]==1)
			res |= true;
	}
	color[s]=2;
	return res;
}

int main()
{
	int n, m;
	cin>>n>>m;
	adj.assign(n+1, vector<int>());
	color.assign(n+1, 0);
	int i, u, v;
	for(i=1; i<=m; i++)
	{
		cin>>u>>v;
		adj[u].pb(v);
	}
	bool ans=false;
	for(i=1; i<=n; i++)
	{
		if(color[i]==0)
		{
			ans |= cycle_detection(i);
		}
	}
	if(ans) cout<<"There is a cycle in the graph."<<endl;
	else cout<<"There is no cycle in the graph."<<endl;
}