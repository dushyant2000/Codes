#include<bits/stdc++.h>
using namespace std;

int dp[1000][1000];

int solve(string a, string b, string c, int n1, int n2, int n3)
{
	if(n1==0 && n2==0 && n3==0) return 1;
	if(n3==0) return 0;
	if(dp[n1][n2]!=-1) return dp[n1][n2];
	return dp[n1][n2] = (a[n1-1]==c[n3-1] && solve(a, b, c, n1-1, n2, n3-1) || 
		b[n2-1]==c[n3-1] && solve(a, b, c, n1, n2-1, n3-1));
}

int main()
{
	string a, b, c;
	cin>>a>>b>>c;
	memset(dp ,-1, sizeof dp);
	if(solve(a, b, c, a.size(), b.size(), c.size())) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}