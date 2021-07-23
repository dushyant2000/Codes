#include<bits/stdc++.h>
using namespace std;

int dp[1000][1000];

void solve(string s, int n, int l, int r)
{
	if(l>n || r<1 || l>r) return dp[l][r]=0;
	if(l==r) return dp[l][r]=1;
	if(s[l-1]==s[r-1] && l==r-1) return dp[l][r]=1;
	if(dp[l][r]!=-1) return dp[l][r];
	if(s[l-1]==s[r-1]) dp[l][r]=solve(s, n, l+1, r-1);
	else dp[l][r]=0;
	dp[l][r-1]=solve(s, n, l, r-1);
	dp[l+1][r]=solve(s, n, l+1, r);
	return dp[l][r];
}

int main()
{
	string s;
	cin>>s;
	int n=s.size();
	memset(dp, -1, sizeof dp);
	solve(s, n, 1, n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
}