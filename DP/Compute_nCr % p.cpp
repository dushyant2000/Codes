#include<bits/stdc++.h>
using namespace std;

int** dp;
int comb(int n, int r, int p)
{
	if(n<r) return dp[n][r]=0;
	if(r==0 || n==r) return dp[n][r]=1;
	if(dp[n][r]!=-1) return dp[n][r];
	return dp[n][r] = (comb(n-1, r, p)%p + comb(n-1, r-1, p)%p)%p;
}

int main()
{
	int n, r, p;
	cin>>n>>r>>p;
	dp = new int*[n+1];
	int i, j;
	for(i=0;i<n+1;i++)
	{
		dp[i] = new int[r+1];
		for(j=0;j<r+1;j++) dp[i][j]=-1;
	}
	cout<<comb(n, r, p)<<endl;
}