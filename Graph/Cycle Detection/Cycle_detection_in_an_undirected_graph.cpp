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

//###################	Cycle detection in an undirected graph	###################
//(DFS) If for any vertex visited[neighbour(except parent)]==1 then there is a cycle
//(DSU) Take union of every edge, if for any edge find(u)=find(v) then ther is a cycle
// DSU can't be used to detect cycle in a directed graph
// DFS can be used to detect cycle in a directed graph, but we need to maintain three values for each vertex - unvisited, visiting, visited

vector<vector<int>> adj;
vector<int> visited;

class DSU
{
	public:
		int *rank, *parent, n;		//rank stores the deapth of the tree/set
		DSU(int n)			//parent stores the representative of the tree(root node)/set
		{
			rank = new int[n+1];
			parent = new int[n+1];
			this->n = n;
			make_set();
		}
		
		void make_set()				//initialization
		{
			for(int i=1;i<=n;i++)
			{
				parent[i]=i;
				rank[i]=1;
			}
		}

		int find(int x)				//finds a parent pointer to given element
		{
			if(parent[x]==x)
				return x;
			return parent[x] = find(parent[x]);
		}

		bool merge(int x, int y)		//performs union operation b/w a set containing x and a set containing y
		{
			x = find(x);
			y = find(y);

			if(x==y)
				return false;
			if(rank[x]<rank[y])			//bcz we want to minimize the deapth of the tree
			{
				swap(x, y);
			}
			parent[y]=x;
			rank[x]+=rank[y];
			return true;
		}
};

bool cycle_detection_BFS(int s, int e)
{
	visited[s]=1;
	bool res=false;
	for(auto i: adj[s])
	{
		if(!visited[i])
			res |= cycle_detection_BFS(i, s);
		else if(visited[i] && i!=e)
			res |= true;
	}
	return res;
}

int main()
{
	int n, m;
	cin>>n>>m;
	adj.assign(n+1, vector<int>());
	visited.assign(n+1, 0);
	int i, u, v;
	bool ans=false;
	DSU dsu(n);
	for(i=1; i<=m; i++)
	{
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
		ans |= !dsu.merge(u, v);
	}
	if(ans) cout<<"There is a cycle in the graph"<<endl;
	else cout<<"There is no cycle in the graph"<<endl;
	ans=false;
	for(i=1; i<=n; i++)
	{
		if(!visited[i])
			ans = ans | cycle_detection_BFS(i, -1);
	}
	if(ans) cout<<"There is a cycle in the graph"<<endl;
	else cout<<"There is no cycle in the graph"<<endl;
}


