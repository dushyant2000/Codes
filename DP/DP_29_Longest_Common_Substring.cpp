#include<bits/stdc++.h>
using namespace std;

int dp[1000][1000];

int lcs(string x, string y, int n, int m)
{
	if(n==0 || m==0) return dp[n][m]=0;
	if(dp[n][m]!=-1) return dp[n][m];
	if(x[n-1]==y[m-1]) return dp[n][m] = 1 + lcs(x, y, n-1, m-1);
	dp[n][m] = 0;
	lcs(x, y, n, m-1);
	lcs(x, y, n-1, m);
	return dp[n][m];
}

int solve(string x, string y, int n, int m)
{
	int i, j, ans=0;
	memset(dp, -1, sizeof dp);
	lcs(x, y, n, m);
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++) ans = max(ans, dp[i][j]);
	}
	return ans;
}

int main()
{
	string x, y;
	cin>>x>>y;
	int n=x.size(), m=y.size();
	cout<<"Length of the longest Common Substring - ";
	cout<<solve(x, y, n, m)<<endl;
}