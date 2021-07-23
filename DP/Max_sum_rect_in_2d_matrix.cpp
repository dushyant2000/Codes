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

int Solution::solve(vector<vector<int> > &A) {
    int i, j, n=A.size(), m=A[0].size();
    for(j=1; j<m; j++)
    {
        for(i=0; i<n; i++) A[i][j]+=A[i][j-1];
    }
    int l, r, curr_max=0, max_so_far=0, ans=-INF, arr[n+1];
    for(l=0; l<m; l++)
    {
        for(r=l; r<m; r++)
        {
            for(i=0; i<n; i++)
            {
                if(l==0) arr[i] = A[i][r];
                else arr[i] = A[i][r] - A[i][l-1];
            }
            curr_max=arr[0], max_so_far=arr[0];
            for(i=1; i<n; i++)
            {
                curr_max = max(curr_max+arr[i], arr[i]);
                max_so_far = max(max_so_far, curr_max);
            }
            ans = max(ans, max_so_far);
        }
    }
    return ans;
}
