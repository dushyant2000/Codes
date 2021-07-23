#include<bits/stdc++.h>
using namespace std;

int dp[1000000];

int f(pair<int, int> a[], int n)
{
	if(n==1) return dp[n]=1;
	if(dp[n]!=-1) return dp[n];
	dp[n]=1;
	for(int j=1;j<n;j++)
	{
		if(a[n].first > a[j].second)
			dp[n] = max(dp[n], 1+f(a, j));
	}
	return dp[n];
}

int solve(pair<int, int> a[], int n)
{
	f(a, n);
	int i, ans=0;
	for(i=1;i<=n;i++) ans = max(ans, dp[i]);
	return ans;
}

int main()
{
	int n;
	cin>>n;
	pair<int, int> a[n+1];
	int i;
	for(i=1;i<=n;i++)
	{
		cin>>a[i].first>>a[i].second;
	}
	memset(dp, -1, sizeof dp);
	cout<<solve(a, n)<<endl;
}