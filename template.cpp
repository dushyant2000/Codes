//-----------------------Template-------------------------
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
#define lli long long int
#define lld long double
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define sz(x) (x).size()
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define mp make_pair
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a*b)/__gcd(a, b)
#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;
using namespace __gnu_pbds;
 typedef tree<lli, null_type, less_equal<lli>, rb_tree_tag,
 tree_order_statistics_node_update>
 ordered_set;
 
// *s.find_by_order(p)          returns the value of pth largest starting from 0 
// s.order_of_key(p)            returns no. of items that are strictly < p 
// s.erase(s.upper_bound(p))    p is an element in a multiset and this deletes only one occurance of p
 
const lli N = 3e5+2;
const lli INF = 1e9+9;
const lli mod = 998244353;

lli fac[N];

lli mult(lli a, lli b, lli p)
{
    return (a%p * b%p)%p;
}

lli power(lli x, lli y, lli p)
{
    if(x == 0 || y < 0) 
        return 0;
    if (y == 0)
        return 1;
    lli z = power(x, y/2, p);
    if (y % 2 == 0)
        return mult(z, z, p);
    else
        return mult(x, mult(z, z, p), p);
}

lli inv(lli y, lli p)
{
    return power(y, p-2, p);
}

lli nCr(lli n, lli r, lli p)
{
    if(r>n) return 0;
    if(r==0 || r==n) return 1;
    return (fac[n]%p * inv(fac[n-r], p)%p * inv(fac[r], p)%p)%p;
}

void dec(int n)
{
    std::cout << std::fixed << std::showpoint;
    std::cout << std::setprecision(n);
}

class DSU
{
    public:
        int *size, *parent, n;      
        DSU(int n)                  
        {
            size = new int[n+1];
            parent = new int[n+1];
            this->n = n;
            make_set();
        }
        
        void make_set()             
        {
            for(int i=1;i<=n;i++)
            {
                parent[i]=i;
                size[i]=1;
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
            if(size[x]<size[y])         
            {
                swap(x, y);
            }
            parent[y]=x;
            size[x]+=size[y];
            return true;
        }
};


void solve()
{
   
}

int main()
{
    fast;
    lli t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
}
