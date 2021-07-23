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
 
const lli N = 5e3+5;
const lli INF = 1e9+9;
const lli mod = 1e9+7;

//*************** Minimum Spanning Tree ***************

//*************** Kruskal's Algorithm ***************

//Simple Implementation: O(M*logM + N^2)

vector<pair<int, pair<int, int>>> edges, result;

void kruskal(int n)
{
	int i, tree_id[n+1], cost = 0;
	for(i=1; i<=n; i++) 
		tree_id[i]=i;

	sort(all(edges));

	for(auto e: edges)
	{
		if(tree_id[e.ss.ff] != tree_id[e.ss.ss])
		{
			cost += e.ff;
			result.pb(e);

			int old_id = tree_id[e.ss.ff], new_id = tree_id[e.ss.ss];
			for(i=1; i<=n; i++)
			{
				if(tree_id[i]==old_id) 
					tree_id[i] = new_id;
			}
		}
	}

	cout<<"MST Edges:"<<endl;
	for(auto e: result)
	{
		cout<<e.ss.ff<<" -> "<<e.ss.ss<<" , "<<e.ff<<endl;
	}
}

int main()
{
	int n, m;
	cin>>n>>m;
	int i, u, v, w;
	for(i=1; i<=m; i++)
	{
		cin>>u>>v>>w;
		edges.pb(mp(w, mp(u, v)));
	}
	kruskal(n);
}


//Implementation using Disjoint Set Union: O(M * logN)

vector<pair<int, pair<int, int>>> edges, result;
vector<int> parent, size;

void make_set(int n)
{
	for(int i=1; i<=n; i++)
	{
		parent[i] = i;
		size[i] = 1;
	}
}

int find(int x)
{
	if(parent[x]==x)
		return x;
	return parent[x] = find(parent[x]);
}

bool merge(int x, int y)
{
	x = find(x);
	y = find(y);

	if(x==y) 
		return false;
	if(size[x] < size[y])
		swap(x, y);
	parent[y] = x;
	size[x] += size[y];
	return true;
}

void kruskal(int n)
{
	int i, cost = 0;
	parent.resize(n+1);
	size.resize(n+1);
	make_set(n);

	sort(all(edges));

	for(auto e: edges)
	{
		if(find(e.ss.ff) != find(e.ss.ss))
		{
			cost += e.ff;
			result.pb(e);

			merge(e.ss.ff, e.ss.ss);
		}
	}

	cout<<"MST Edges:"<<endl;
	for(auto e: result)
	{
		cout<<e.ss.ff<<" -> "<<e.ss.ss<<" , "<<e.ff<<endl;
	}
	cout<<endl;
	cout<<"Total Weight: "<<cost<<endl;
}

int main()
{
	int n, m;
	cin>>n>>m;
	int i, u, v, w;
	for(i=1; i<=m; i++)
	{
		cin>>u>>v>>w;
		edges.pb(mp(w, mp(u, v)));
	}
	kruskal(n);
}

/*Sample Input(gfg):
5 7
1 2 2
1 4 6
2 3 3
2 4 8
2 5 5
3 5 7
4 5 9
*/