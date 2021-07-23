#include<bits/stdc++.h>
using namespace std;

int dp[1000][1000], mat[1000][1000];

int palindrome(string s, int n, int l, int r)
{
	if(l>n || r<1) return 0;
	if(l>r) dp[l][r]=0;
	if(l==r) dp[l][r]=1;
	if(s[l-1]==s[r-1] && l==r-1) dp[l][r]=1;
	if(dp[l][r]==-1)
	{
		if(s[l-1]==s[r-1]) dp[l][r]=palindrome(s, n, l+1, r-1);
		else dp[l][r]=0;
	}
	dp[l][r-1]=palindrome(s, n, l, r-1);
	dp[l+1][r]=palindrome(s, n, l+1, r);
	return dp[l][r];
}

int solve(string s, int n, int l, int r)
{
	if(l>r) return 0;
	if(dp[l][r]==1) return mat[l][r]=0;
	if(mat[l][r]!=-1) return mat[l][r];
	return mat[l][r]=1+min(solve(s, n, l, r-1), solve(s, n, l+1, r));
}

int main()
{
	string s;
	cin>>s;
	int n=s.size(), i, j, ans;
	memset(dp, -1, sizeof dp);
	memset(mat, -1, sizeof mat);
	ans = palindrome(s, n, 1, n);
	cout<<solve(s, n, 1, n)<<endl;
		for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
}