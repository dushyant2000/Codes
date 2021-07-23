#include<bits/stdc++.h>
using namespace std;

int solve(string x, string y, int m, int n)
{
	int dp[m+1][n+1];

	int i, j;
	for(i=0;i<=m;i++) dp[i][0]=0;
	for(j=0;j<=n;j++) dp[0][j]=0;

	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(x[i-1]==y[j-1]) dp[i][j]=1+dp[i-1][j-1];
			else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
		}
	}
	return dp[m][n];
}


int main()
{
	string x, y;
	cin>>x>>y;
	int m=x.size(), n=y.size();
	cout<<"Length of LCS - "<<solve(x, y, m, n)<<endl;
}