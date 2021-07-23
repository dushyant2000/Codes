#include<bits/stdc++.h>
using namespace std;

int dp[100000];

int bridge(pair<int, int> city[], int n)
{
	if(n==1) return dp[n]=1;
	if(dp[n]!=-1) return dp[n];
	dp[n]=1;
	for(int j=1;j<n;j++)
	{
		if(city[n].second>city[j].second)
			dp[n] = max(dp[n], 1+bridge(city, j));
	}
	return dp[n];
}

int solve(int a[], int b[], int n)
{
	int i, ans=0;
	pair<int, int> city[n];
	for(i=1;i<=n;i++) city[i]={a[i], b[i]};
	sort(city, city+n);
	bridge(city, n);
	for(i=1;i<=n;i++) ans=max(ans, dp[i]);
	return ans;
}

int main()
{
	int n;
	cin>>n;
	int i, a[n+1], b[n+1];
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=n;i++) cin>>b[i];
	memset(dp, -1, sizeof dp);
	cout<<solve(a, b, n)<<endl;
}