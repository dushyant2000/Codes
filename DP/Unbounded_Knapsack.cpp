#include<bits/stdc++.h>
using namespace std;

int solve(int val[], int w[], int n, int W)
{
	int dp[n+1][W+1], i, j;

	for(i=0;i<=n;i++)
	{
		for(j=0;j<=W;j++)
		{
			if(i==0 || j==0) dp[i][j]=0;
			else if(j<w[i-1]) dp[i][j]=dp[i-1][j];
			else dp[i][j] = max(dp[i-1][j], dp[i][j-w[i-1]]+val[i-1]);
		}
	}

	return dp[n][W];
}


int main()
{
	int n;
	cin>>n;
	int i, val[n], w[n], W;
	for(i=0;i<n;i++) cin>>val[i];
	for(i=0;i<n;i++) cin>>w[i];
	cin>>W;
	cout<<solve(val, w, n, W)<<endl;
}