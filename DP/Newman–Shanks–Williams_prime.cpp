#include<bits/stdc++.h>
using namespace std;

int solve(int n)
{
	int i, dp[n+1];
	dp[0]=1;
	dp[1]=1;
	for(i=2;i<=n;i++)
	{
		dp[i] = 2*dp[i-1] + dp[i-2];
	}
	return dp[n];
}

int main()
{
	int n;
	cin>>n;
	cout<<solve(n)<<endl;
}