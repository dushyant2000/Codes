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

//*************** Fenwick Tree ***************

//Let, f be some reversible function and A be an array of integers of length N.
//Fenwick tree is a data structure which:
//1.calculates the value of function f in the given range [l,r] (i.e. f(Al,Al+1,…,Ar)) in O(logn) time;
//2.updates the value of an element of A in O(logn) time;
//3.requires O(N) memory, or in other words, exactly the same memory required for A;
//4.is easy to use and code, especially, in the case of multidimensional arrays.



//---------- Finding sum in one-dimensional array ----------
int bit[100001]={0};

void build(int a[], int n)
{
	for(int i=1; i<=n; i++)
	{
		update(i, a[i]);
	}
}

void update(int idx, int delta)
{
	while(idx<=100000)
    {
        bit[idx] += delta;
        idx += (idx & (idx-1));
    }
}

int sum(int idx)
{
	int res=0;
	while(idx>0)
	{
		res += bit[idx];
		idx -= (idx & (idx-1));
	}
	return res;
}

int get_sum(int l, int r)
{
	return sum(r) - sum(l-1);
}

//---------- Finding minimum of [0,r] in one-dimensional array ----------

int bit[100001]={0};


void build(int a[], int n)
{
	for(int i=1; i<=n; i++)
	{
		update(i, a[i]);
	}
}

void update(int idx, int delta)
{
	while(idx<=100000)
    {
        bit[idx] = min(bit[idx], delta);
        idx += (idx & (idx-1));
    }
}

int get_min(int idx)
{
	int res = INF;
	while(idx>0)
	{
		res = min(res, bit[idx]);
		idx -= (idx & (idx-1));
	}
	return res;
}


//---------- Finding sum of [0,x][0,y] in two-dimensional array ----------

int bit[1001][1001];

void build(int** a, int n, int m)
{
	for(int i=1; i<=n; i++)
	{
		for(j=1; j<=m; j++)
			update(i, j, a[i][j]);
	}
}

void update(int x, int y, int delta, int n, int m)
{
	for(i=x; i<=n; i+=(i&(i-1)))
    {
    	for(j=y; j<=m; j+=(j&(j-1)))
       		bit[i][j] += delta;
    }
}

int get_sum(int x, int y)
{
	int res = 0;
	for(i=x; i>0; i-=(i&(i-1)))
	{
		for(j=y; j>0; j-=(j&(j-1)))
			res += bit[i][j];
	}
	return res;
}

//+++++++++++++++ Range Operations +++++++++++++++

//1. Point Update and Range Query
//This is just the ordinary Fenwick tree as explained above.

//2. Range Update and Point Query
//Suppose that we want to increment the interval [l,r] by x. 
//We make two point update operations on Fenwick tree which are update(l, x) and update(r+1, -x)

int bit[100001]={0};

void build(int a[], int n)
{
	for(int i=1; i<=n; i++)
	{
		update(i, a[i]);
	}
}

void update(int idx, int delta)
{
	while(idx<=100000)
    {
        bit[idx] += delta;
        idx += (idx & (idx-1));
    }
}

void range_update(int l, int r, int x)
{
	update(l, x);
	update(r+1, -x);
}

int get_sum(int idx)
{
	int res=0;
	while(idx>0)
	{
		res += bit[idx];
		idx -= (idx & (idx-1));
	}
	return res;
}

//3. Range Updates and Range Queries

int bit1[100001], bit2[100001];

void build(int a[], int n)
{
	for(int i=1; i<=n; i++)
	{
		update(bit1, i, a[i]);
		update(bit2, i, a[i]);
	}
}

void update(int bit[], int idx, int delta)
{
	while(idx<=100000)
    {
        bit[idx] += delta;
        idx += (idx & (idx-1));
    }
}

void range_update(int l, int r, int x)
{
	update(bit1, l, x);
	update(bit1, r+1, -x);
	update(bit2, l, x*(l-1));
	update(bit2, r+1, -x*r);
}

int sum(int bit[], int idx)
{
	int res=0;
	while(idx>0)
	{
		res += bit[idx];
		idx -= (idx & (idx-1));
	}
	return res;
}

int prefix_sum(int idx)
{
	return sum(bit1, idx)*idx - sum(bit2, idx);
}

int range_sum(int l, int r)
{
	return prefix_sum(r) - prefix_sum(l-1);
}
