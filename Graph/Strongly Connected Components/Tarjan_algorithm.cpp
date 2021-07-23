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

//###################	Tarjan Algorithm	###################
//Disc: This is the time when a node is visited 1st time while DFS traversal.
//Low: Low value of a node tells the topmost reachable ancestor (with min. possible Disc value) via the subtree of that node. 
//So for any node, Low value equal to its Disc value anyway (A node is ancestor of itself). 
//Then we look into its subtree and see if there is any node which can take us to any of its ancestor. 
//If there are multiple back edges in subtree which take us to different ancestors, then we take the one with minimum Disc value (i.e. the topmost one). 
// If we can find the head (low[v]=disc[v]) of such subtrees, we can print/store all the nodes in that subtree (including head) and that will be one SCC.
//There is no back edge from one SCC to another (There can be cross edges, but cross edges will not be used while processing the graph).
//Time complexity O(V+E) - Only 1 BFS run
//Space complexity O(V)

vector<vector<int>> adj;
vector<int> disc, low;
vector<bool> stack_member;
stack<int> Stack;
int t=0;

void tarjan(int s)
{
	disc[s]=t;
	low[s]=t;
	t++;

	Stack.push(s);
	stack_member[s]=true;

	for(auto u: adj[s])
	{
		if(disc[u]==-1)
		{
			tarjan(u);
			low[s] = min(low[s], low[u]);
		}
		else if(stack_member[u])
			low[s] = min(low[s], disc[u]);
	}

	int v;
	if(low[s]==disc[s])
	{
		while(Stack.top()!=s)
		{
			v = Stack.top();
			cout<<v<<" ";
			Stack.pop();
			stack_member[v]=false;
		}
		v = Stack.top();
		Stack.pop();
		cout<<v<<endl;
		stack_member[v]=false;
	}
}


int main()
{
	int n, m;
	cin>>n>>m;
	adj.assign(n+1, vector<int>());
	disc.assign(n+1, -1);
	low.assign(n+1, -1);
	stack_member.assign(n+1, false);
	int i, u, v;
	for(i=1; i<=m; i++)
	{
		cin>>u>>v;
		adj[u].pb(v);
	}
	cout<<"Strongly Connected Componenets in the graph: "<<endl;
	for(i=1; i<=n; i++)
	{
		if(disc[i]==-1)
			tarjan(i);
	}
}