#include<bits/stdc++.h>
#define inf 1000000
using namespace std;

int dp[1000][1000];

int solve(string s, int l, int r)
{
	if(l>r) return dp[l][r]=inf;
	if(l==r) return dp[l][r]=0;
	if(l==r-1)
	{
		if(s[l-1]==s[r-1]) return dp[l][r]=0;
		else return dp[l][r]=1;
	}
	if(dp[l][r]!=-1) return dp[l][r];
	if(s[l-1]==s[r-1]) return dp[l][r]=solve(s, l+1, r-1);
	return dp[l][r] = 1 + min(solve(s, l, r-1), solve(s, l+1, r));
}


int main()
{
	string s;
	cin>>s;
	int n=s.size();
	memset(dp, -1, sizeof dp);
	cout<<"Minimum insertions to form a palindrome - "<<solve(s, 1, n)<<endl;
}