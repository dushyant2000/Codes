#include<bits/stdc++.h>
using namespace std;

int dp[1000][1000];

int solve(int m, int n, int sum)
{
	if(sum<0) return 0;
	if(n==0)
	{
		if(sum==0) return dp[n][sum]=1;
		else return 0;
	}
	if(dp[n][sum]!=-1) return dp[n][sum];
	dp[n][sum]=0;
	for(int i=1;i<=m;i++)
	{
		if(sum>=i)	dp[n][sum]+=solve(m, n-1, sum-i);
	}
	return dp[n][sum];
}



int main()
{
	int m, n, sum;
	cin>>m>>n>>sum;
	memset(dp, -1, sizeof dp);
	cout<<solve(m, n, sum)<<endl;
}