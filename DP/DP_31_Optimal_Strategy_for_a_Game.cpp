#include<bits/stdc++.h>
using namespace std;

int dp[1000][1000];

int solve(int a[], int l, int r)
{
	if(l>r) return 0;
	if(l==r) return dp[l][r]=a[l-1];
	if(l==r-1) return dp[l][r]=max(a[l-1], a[r-1]);
	if(dp[l][r]!=-1) return dp[l][r];
	return dp[l][r] = max(a[l-1] + min(solve(a, l+2, r), solve(a, l+1, r-1)),
					a[r-1] + min(solve(a, l+1, r-1), solve(a, l, r-2)));
}

int main()
{
	int n;
	cin>>n;
	int i, a[n];
	memset(dp, -1, sizeof dp);
	for(i=0;i<n;i++) cin>>a[i];
	cout<<solve(a, 1, n)<<endl;
}