#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

ll solve(ll n, ll k)
{
	ll dp[n+1], i;
	dp[1]=k;
	dp[2]=k*k;
	for(i=3;i<=k;i++)
	{
		dp[i] = ((k-1) * (dp[i-1]+dp[i-2]))%mod;
	}
	return dp[n];
}

int main()
{
	ll n, k;
	cin>>n>>k;
	cout<<solve(n, k)<<endl;
}