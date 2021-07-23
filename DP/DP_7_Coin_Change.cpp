#include<bits/stdc++.h>
using namespace std;

int dp[1000][1000];

int solve(int n, int m, int a[])
{
	if(n<=0 || m<=0) return 0;
	if(dp[n][m]!=-1) return dp[n][m];
	if(a[m]>n) return dp[n][m]=solve(n, m-1, a);
	return dp[n][m] = max(solve(n, m-1, a), solve(n-a[m], m, a)+1);
}


int main()
{
	int n, m;
	cin>>n>>m;
	int i, j, a[m+1];
	for(i=1;i<=m;i++) cin>>a[i];
	memset(dp, -1, sizeof dp);
	cout<<solve(n, m, a)<<endl;
}