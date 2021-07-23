#include<bits/stdc++.h>
using namespace std;

int** dp;

int fun(int n, int m, int** gold)
{
	int i, j, ans=-1;
	for(j=m;j>=1;j--)
	{
		for(i=1;i<=n;i++)
		{
			dp[i][j]=gold[i][j]+max(dp[i-1][j+1], max(dp[i][j+1], dp[i+1][j+1]));
		}
	}
	for(i=1;i<=n;i++)
	{
		ans = max(ans, dp[i][1]);
	}
	return ans;
}

int main()
{
	int n, m;
	cin>>n>>m;
	int **gold = new int*[n+1];
	int i, j;
	for(i=0;i<n+1;i++)
	{
		gold[i]=new int[m+1];
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cin>>gold[i][j];
		}
	}
	dp = new int*[n+2];
	for(i=0;i<n+2;i++)
	{
		dp[i] = new int[m+2];
	}
	cout<<fun(n, m, gold)<<endl;
}