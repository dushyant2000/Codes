#include<bits/stdc++.h>
using namespace std;

int dp[1000][1000];

int solve(string s, int n, int l, int r)
{
	if(l>n || r<1 || l>r) return 0;
	if(l==r) return 1;
	if(dp[l][r]!=-1) return dp[l][r];
	if(s[l-1]==s[r-1])	return dp[l][r] = solve(s, n, l+1, r-1)+2;
	return dp[l][r] = max(solve(s, n, l, r-1), solve(s, n, l+1, r));
}

int main()
{
	string s;
	cin>>s;
	int n=s.size();
	memset(dp, -1, sizeof dp);
	cout<<"Length of the longest palindromic subsequence - ";
	cout<<solve(s, n, 1, n)<<endl;
}