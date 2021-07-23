#include<bits/stdc++.h>
using namespace std;

void solve(string s, int n)
{
	int i, j, dp[n+1][n+1];
	for(i=0;i<=n;i++) dp[i][0]=0;
	for(j=0;j<=n;j++) dp[0][j]=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(s[i-1]==s[j-1] && i!=j) dp[i][j]=1+dp[i-1][j-1];
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	string str;
	i=n, j=n;
	while(i>0 && j>0)
	{
		if(dp[i][j]==dp[i-1][j-1]+1)
		{
			str.push_back(s[i-1]);
			i--;
			j--;
		}
		else if(dp[i][j]==dp[i-1][j]) i--;
		else j--;
	}
	reverse(str.begin(), str.end());
	cout<<str<<endl;
}


int main()
{
	string s;
	cin>>s;
	solve(s, s.size());
}