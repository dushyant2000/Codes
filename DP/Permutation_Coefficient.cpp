#include<bits/stdc++.h>
using namespace std;

int** dp;

int perm(int n, int k)					//memoization approach
{
	if(k>n) return dp[n][k]=0;
	if(k==0) return dp[n][k]=1;
	if(dp[n][k]!=-1) return dp[n][k];
	return dp[n][k]=perm(n-1, k)+ k*perm(n-1, k-1);
}

int perm_tab(int n, int k)				//tabulation approach
{
	int i,j;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=min(i, k);j++)
		{
			if(j==0) dp[i][j]=1;
			else dp[i][j]=dp[i-1][j]+j*dp[i-1][j-1];
			dp[i][j+1]=0;
		}
	}
	return dp[n][k];
}

int perm_eff(int n, int k)			//Time complexity-O(n)
{
	int i, fac[n+1];
	fac[0]=1;
	for(i=1;i<=n;i++)
	{
		fac[i]=i*fac[i-1];
	}
	return fac[n]/fac[n-k];
}

int main()
{
	int n, k;
	cin>>n>>k;
	dp = new int*[n+1];
	int i, j;
	for(i=0;i<=n;i++)
	{
		dp[i] = new int[k+1];
		for(j=0;j<=k;j++)
		{
			dp[i][j]=-1;
		}
	}
	cout<<perm(n, k)<<endl;
	//cout<<perm_tab(n, k)<<endl;
	cout<<perm_eff(n, k)<<endl;
}