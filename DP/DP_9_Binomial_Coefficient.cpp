#include<bits/stdc++.h>
using namespace std;

const int N=1000;
int dp[N][N]={};

int binomial(int n, int k)			//memoized version
{
	if(k>n) return dp[n][k]=0;
	if(n==k || k==0) return dp[n][k]=1;
	if(dp[n][k]!=0) return dp[n][k];
	return dp[n][k]=binomial(n-1, k)+binomial(n-1, k-1);
}

int binomial_tab(int n, int k)		//tabulation approach
{
	int i, j;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=min(i, k);j++)
		{
			if(j==0 || n==j) dp[i][j]=1;
			else dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
		}
	}
	return dp[n][k];
}

int binomial_eff(int n, int k)			//Time complexity-O(k)
{
	int i, res=1;
	if(k>n-k) k=n-k;
	for(i=0;i<k;i++)
	{
		res*=(n-i);
		res/=(i+1);
	}
	return res;
}

int main()
{
	int n, k;
	cin>>n>>k;
	cout<<binomial(n, k)<<endl;
	//cout<<binomial_tab(n, k)<<endl;
	//cout<<binomial_eff(n, k)<<endl;
}