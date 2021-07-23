#include<bits/stdc++.h>
#define inf 1000000
using namespace std;

int solve(int n, int k)
{
	int dp[n+1][k+1], i, j, x;

	for(j=1;j<=k;j++) dp[1][j]=j;

	for(i=2;i<=n;i++)
	{
		for(j=0;j<=k;j++)
		{
			if(i==0 || j==0) dp[i][j]=0;
			else if(i>j) dp[i][j]=dp[i-1][j];
			else
			{
				dp[i][j]=inf;
				for(x=1;x<=j;x++)
				{
					dp[i][j] = min(dp[i][j], 1+max(dp[i-1][x-1], dp[i][j-x]));
				}
			}
		}
	}
	return dp[n][k];
}

int main()
{
	int n, k;
	cin>>n>>k;
	cout<<solve(n, k)<<endl;
}