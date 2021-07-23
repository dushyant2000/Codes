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

//###################	Kosaraju Algorithm	###################
//Strongly connected components means all the vertices in that component are reachable from every other vertex in that component. 
//While doing DFS, maintain a stack of vertices according to their finish time
//From the first DFS, we are getting a sequence in whcih we have to do the DFS to get strongly connected components
//SSC from the top of the Stack are getting trapped, so from there we can't go to any other unvisited SSC
//Pop the top vertix one-by-one from the stack and do DFS on the reversed edged graph
//DFS from one vertex will be over when it reaches the last vertex in the connected component
//Print all the vertices that are in the same connected component
//Time Complexity O(V+E) - 2 BFS run
//Space Complexity O(V)

vector<vector<int>> adj, adj_reverse;
vector<int> visited;
stack<int> Stack;

void DFS(int s)
{
	visited[s]=1;
	for(auto u: adj[s])
	{
		if(!visited[u])
			DFS(u);
	}
	Stack.push(s);
}

void DFS_reverse(int s)
{
	visited[s]=1;
	cout<<s<<" ";
	for(auto u: adj_reverse[s])
	{
		if(!visited[u])
			DFS_reverse(u);
	}
}

int main()
{
	int n, m;
	cin>>n>>m;
	adj.assign(n+1, vector<int>());
	adj_reverse.assign(n+1, vector<int>());
	visited.assign(n+1, 0);
	int i, u, v;
	for(i=1; i<=m; i++)
	{
		cin>>u>>v;
		adj[u].pb(v);
		adj_reverse[v].pb(u);
	}
	for(i=1; i<=n; i++)
	{
		if(!visited[i])
			DFS(i);
	}
	visited.assign(n+1, 0);
	cout<<"Strongly Connected Componenets in the graph: "<<endl;
	while(!Stack.empty())
	{
		u = Stack.top();
		Stack.pop();
		if(!visited[u])
		{
			DFS_reverse(u);
			cout<<endl;
		}
	}
		
}
