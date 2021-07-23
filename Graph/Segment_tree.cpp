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
 
const lli N = 2e3+2;
const lli INF = 1e9+9;
const lli mod = 998244353;

//-------------------- Sum Query Segment Tree --------------------
int seg[4*N];
void build_seg(int a[], int v, int tl, int tr)
{
	if(tl==tr)
	{
		seg[v]=a[tl];
	}
	else
	{
		int tm = (tl+tr)/2;
		build_seg(a, 2*v, tl, tm);
		build_seg(a, 2*v+1, tm+1, tr);
		seg[v] = seg[2*v] + seg[2*v+1];
	}
}

void update_seg(int v, int tl, int tr, int pos, int x)
{
	if(tl==tr)	
	{
		seg[v]=x;
	}
	else
	{
		int tm = (tl+tr)/2;
		if(pos<=tm) update_seg(2*v, tl, tm, pos, x);
		else update_seg(2*v+1, tm+1, tr, pos, x);
		seg[v] = seg[2*v] + seg[2*v+1];
	}
}

int sum_query_seg(int v, int tl, int tr, int l, int r)
{
	if(l>r) return 0;
	if(l==tl && r==tr) return seg[v];
	int tm = (tl+tr)/2;
	return sum_query_seg(2*v, tl, tm, l, min(r, tm)) + 
				sum_query_seg(2*v+1, tm+1, tr, max(tm+1, l), r);
}


//-------------------- Max Query Segment Tree --------------------
int seg[4*N];
void build_seg(int a[], int v, int tl, int tr)
{
	if(tl==tr) seg[v]=a[tl];
	else
	{
		int tm = (tl+tr)/2;
		build_seg(a, 2*v, tl, tm);
		build_seg(a, 2*v+1, tm+1, tr);
		seg[v] = max(seg[2*v], seg[2*v+1]);
	}
}

void update_seg(int v, int tl, int tr, int pos, int x)
{
	if(tl==tr) seg[v]=x;
	else
	{
		int tm = (tl+tr)/2;
		if(pos<=tm) update_seg(2*v, tl, tm, pos, x);
		else update_seg(2*v+1, tm+1, tr, pos, x);
		seg[v] = max(seg[2*v], seg[2*v+1]);
	}
}

int max_query_seg(int v, int tl, int tr, int l, int r)
{
	if(l>r) return -INF;
	if(tl==l && tr==r) return seg[v];
	int tm = (tl+tr)/2;
	return max(max_query_seg(2*v, tl, tm, l, min(r, tm)), 
		max_query_seg(2*v+1, tm+1, tr, max(tm+1, l), r));
}


//-------------------- Min Query Segment Tree --------------------
int seg[4*N];
void build_seg(int a[], int v, int tl, int tr)
{
	if(tl==tr) seg[v]=a[tl];
	else
	{
		int tm = (tl+tr)/2;
		build_seg(a, 2*v, tl, tm);
		build_seg(a, 2*v+1, tm+1, tr);
		seg[v] = min(seg[2*v], seg[2*v+1]);
	}
}

void update_seg(int v, int tl, int tr, int pos, int x)
{
	if(tl==tr) seg[v]=x;
	else
	{
		int tm = (tl+tr)/2;
		if(pos<=tm) update_seg(2*v, tl, tm, pos, x);
		else update_seg(2*v+1, tm+1, tr, pos, x);
		seg[v] = min(seg[2*v], seg[2*v+1]);
	}
}

int min_query_seg(int v, int tl, int tr, int l, int r)
{
	if(l>r) return INF;
	if(tl==l && tr==r) return seg[v];
	int tm = (tl+tr)/2;
	return min(min_query_seg(2*v, tl, tm, l, min(r, tm)), 
		min_query_seg(2*v+1, tm+1, tr, max(tm+1, l), r));
}


//-------------------- {Max, Frequency} Query Segment Tree --------------------
//Finding the maximum and the number of times it appears

pair<int, int> seg[4*N];

pair<int, int> combine(pair<int, int> a, pair<int, int> b)
{
	if(a.ff > b.ff) return a;
	if(b.ff > a.ff) return b;
	return mp(a.ff, a.ss+b.ss);
}

void build_seg(int a[], int v, int tl, int tr)
{
	if(tl==tr) seg[v] = mp(a[tl], 1);
	else
	{
		int tm = (tl+tr)/2;
		build_seg(a, 2*v, tl, tm);
		build_seg(a, 2*v+1, tm+1, tr);
		seg[v] = combine(seg[2*v], seg[2*v+1]);
	}
}

void update_seg(int v, int tl, int tr, int pos, int x)
{
	if(tl==tr) seg[v] = mp(x, 1);
	else
	{
		int tm = (tl+tr)/2;
		if(pos<=tm) update_seg(2*v, tl, tm, pos, x);
		else update_seg(2*v+1, tm+1, tr, pos, x);
		seg[v] = combine(seg[2*v], seg[2*v+1]);
	}
}

pair<int, int> max_query_seg(int v, int tl, int tr, int l, int r)
{
	if(l>r) return mp(-INF, 0);
	if(tl==l && tr==r) return seg[v];
	int tm = (tl+tr)/2;
	return max(max_query_seg(2*v, tl, tm, l, min(r, tm)), 
		max_query_seg(2*v+1, tm+1, tr, max(tm+1, l), r));
}


//-------------------- GCD Query Segment Tree --------------------

int seg[4*N];

void build_seg(int a[], int v, int tl, int tr)
{
	if(tl==tr) seg[v] = a[tl];
	else
	{
		int tm = (tl+tr)/2;
		build_seg(a, 2*v, tl, tm);
		build_seg(a, 2*v+1, tm+1, tr);
		seg[v] = gcd(seg[2*v], seg[2*v+1]);
	}
}

void update_seg(int v, int tl, int tr, int pos, int x)
{
	if(tl==tr) seg[v] = x;
	else
	{
		int tm = (tl+tr)/2;
		if(pos<=tm) update_seg(2*v, tl, tm, pos, x);
		else update_seg(2*v+1, tm+1, tr, pos, x);
		seg[v] = gcd(seg[2*v], seg[2*v+1]);
	}
}

int get_gcd(int v, int tl, int tr, int l, int r)
{
	if(l>r) return 0;
	if(tl==l && tr==r) return seg[v];
	int tm = (tl+tr)/2;
	return gcd(get_gcd(2*v, tl, tm, l, min(tm, r)), 
				get_gcd(2*v+1, tm+1, tr, max(tm+1, l), r));
}

//-------------------- LCM Query Segment Tree --------------------

int seg[4*N];

void build_seg(int a[], int v, int tl, int tr)
{
	if(tl==tr) seg[v] = a[tl];
	else
	{
		int tm = (tl+tr)/2;
		build_seg(a, 2*v, tl, tm);
		build_seg(a, 2*v+1, tm+1, tr);
		seg[v] = lcm(seg[2*v], seg[2*v+1]);
	}
}

void update_seg(int v, int tl, int tr, int pos, int x)
{
	if(tl==tr) seg[v] = x;
	else
	{
		int tm = (tl+tr)/2;
		if(pos<=tm) update_seg(2*v, tl, tm, pos, x);
		else update_seg(2*v+1, tm+1, tr, pos, x);
		seg[v] = lcm(seg[2*v], seg[2*v+1]);
	}
}

int get_lcm(int v, int tl, int tr, int l, int r)
{
	if(l>r) return 1;
	if(tl==l && tr==r) return seg[v];
	int tm = (tl+tr)/2;
	return lcm(get_lcm(2*v, tl, tm, l, min(tm, r)), 
				get_lcm(2*v+1, tm+1, tr, max(tm+1, l), r));
}


//---------- Counting the number of zeros, searching for the k-th zero ----------

int seg[4*N];

void build_seg(int a[], int v, int tl, int tr)
{
	if(tl==tr) seg[v] = (a[v]==0);
	else
	{
		int tm = (tl+tr)/2;
		build_seg(a, 2*v, tl, tm);
		build_seg(a, 2*v+1, tm+1, tr);
		seg[v] = seg[2*v] + seg[2*v+1];
	}
}

void update_seg(int v, int tl, int tr, int pos, int x)
{
	if(tl==tr) seg[v] = (x==0);
	else
	{
		int tm = (tl+tr)/2;
		if(pos<=tm) update_seg(2*v, tl, tm, pos, x);
		else update_seg(2*v+1, tm+1, tr, pos, x);
		seg[v] = seg[2*v] + seg[2*v+1];
	}
}

int get_count_zero(int v, int tl, int tr, int l, int r)
{
	if(l>r) return 0;
	if(tl==l && tr==r) return seg[v];
	int tm = (tl+tr)/2;
	return get_count_zero(2*v, tl, tm, l, min(tm, r)) + 
			get_count_zero(2*v+1, tm+1, tr, max(tm+1, l), r);
}

int find_kth_zero(int v, int tl, int tr, int k)
{
	if(k>seg[v]) return 0;
	if(tl==tr) return tl;
	int tm = (tl+tr)/2;
	if(seg[2*v]>=k)
		return find_kth_zero(2*v, tl ,tm, k);
	else 
		return find_kth_zero(2*v+1, tm+1, tr, k-seg[2*v]);
}

//---------- Searching for an array prefix with a given amount ----------
//for a given value x we have to quickly find smallest index i 
//such that the sum of the first i elements of the array a[] is greater or equal to x

int seg[4*N];

void build_seg(int a[], int v, int tl, int tr)
{
	if(tl==tr) seg[v] = a[v];
	else
	{
		int tm = (tl+tr)/2;
		build_seg(a, 2*v, tl, tm);
		build_seg(a, 2*v+1, tm+1, tr);
		seg[v] = seg[2*v] + seg[2*v+1];
	}
}

void update_seg(int v, int tl, int tr, int pos, int x)
{
	if(tl==tr) seg[v] = x;
	else
	{
		int tm = (tl+tr)/2;
		if(pos<=tm) update_seg(2*v, tl, tm, pos, x);
		else update_seg(2*v+1, tm+1, tr, ps, x);
		seg[v] = seg[2*v] + seg[2*v+1];
	}
}

int get_pref_index(int v, int tl, int tr, int x)
{
	if(x>seg[v]) return -1;
	if(tl==tr) return tl;
	int tm = (tl+tr)/2;
	if(seg[2*v]>=x)
		return get_pref_index(2*v, tl, tm, x);
	else
		return get_pref_index(2*v+1, tm+1, tr, x-seg[2*v]);
}

//---------- Searching for the first element greater than a given amount ----------
//for a given value x and a range a[l…r] find the smallest i in the range a[l…r], 
//such that a[i] is greater than x.

int seg[4*N];

void build_seg(int a[], int v, int tl, int tr)
{
	if(tl==tr) seg[v] = a[v];
	else
	{
		int tm = (tl+tr)/2;
		build_seg(a, 2*v, tl, tm);
		build_seg(a, 2*v+1, tm+1, tr);
		seg[v] = seg[2*v] + seg[2*v+1];
	}
}

void update_seg(int v, int tl, int tr, int pos, int x)
{
	if(tl==tr) seg[v] = x;
	else
	{
		int tm = (tl+tr)/2;
		if(pos<=tm) update_seg(2*v, tl, tm, pos, x);
		else update_seg(2*v+1, tm+1, tr, ps, x);
		seg[v] = seg[2*v] + seg[2*v+1];
	}
}

int get_seg_index(int v, int tl, int tr, int l, int r, int x)
{
	if(tl>r || tr<l) return -1;
	
}