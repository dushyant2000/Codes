#include<bits/stdc++.h>
using namespace std;

int solve(int** cost, int m, int n, int x, int y)
{
	int dp[m+1][n+1], i, j;
	for(i=0;i<=m;i++)
	{
		for(j=0;j<=n;j++)
		{
			if(i==0 || j==0) dp[i][j]=0;
			else if(i==1) dp[i][j] = cost[i-1][j-1] + dp[i][j-1];
			else if(j==1) dp[i][j] = cost[i-1][j-1] + dp[i-1][j];
			else
			{
				dp[i][j] = cost[i-1][j-1] + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
			}
		}
	}
	return dp[x+1][y+1];
}

int main()
{
	int m, n;
	cin>>m>>n;
	int** cost;
	cost = new int*[m];
	int i, j, x, y;
	for(i=0;i<m;i++) 
	{
		cost[i]=new int[n];
		for(j=0;j<n;j++) cin>>cost[i][j];
	}
	cin>>x>>y;
	cout<<solve(cost, m, n, x, y)<<endl;
}