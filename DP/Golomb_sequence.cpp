#include<bits/stdc++.h>
using namespace std;

void solve(int n)
{
	int dp[n+1], i;

	dp[1]=1;
	cout<<dp[1]<<" ";
	for(i=1;i<n;i++)
	{
		dp[i+1] = 1 + dp[i+1-dp[dp[i]]];
		cout<<dp[i+1]<<" ";
	}
	cout<<endl;
}

int main()
{
	int n;
	cin>>n;
	solve(n);
}