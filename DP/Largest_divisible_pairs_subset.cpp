#include<bits/stdc++.h>
using namespace std;

int fun(int a[], int n)
{
	int dp[n];

	dp[n-1]=1;
	int i, j, m=0, ans=0;
	for(i=n-2;i>=0;i--)
	{
		m=0;
		for(j=i+1;j<n;j++)
		{
			if(a[i]%a[j]==0 || a[j]%a[i]==0)
			{
				m = max(m, dp[j]);
			}
		}
		dp[i]=m+1;
	}
	for(i=0;i<n;i++) ans=max(ans, dp[i]);
	return ans;
}

int main()
{
	int n;
	cin>>n;
	int i, a[n];
	for(i=0;i<n;i++) cin>>a[i];
	sort(a, a+n);
	cout<<fun(a, n)<<endl;
}