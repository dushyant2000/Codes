#include<bits/stdc++.h>
using namespace std;

int dp[n]={};

int catalan(int n)
{
	if(n<=1) return 1;
	if(dp[n]!=0) return dp[n];
	for(i=0;i<n;i++)
	{
		res += (catalan(i)*catalan(n-i-1));
	}
	return dp[n]=res;
}


int main()
{
	int n;
	cin>>n;
	cout<<catalan(n)<<endl;
}