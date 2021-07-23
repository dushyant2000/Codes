#include<bits/stdc++.h>
using namespace std;

int solve(string x, string y, int m, int n)
{
	int dp[m+1][n+1], i, j;

	for(i=0;i<=m;i++)
	{
		for(j=0;j<=n;j++)
		{
			if(i==0) dp[i][j]=j;
			else if(j==0) dp[i][j]=i;
			else if(x[i-1]==y[j-1]) dp[i][j]=dp[i-1][j-1];
			else dp[i][j] = 1+min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]));
		}
	}
	return dp[m][n];
}

int main()
{
	string x, y;
	cin>>x>>y;
	cout<<solve(x, y, x.size(), y.size())<<endl;
}