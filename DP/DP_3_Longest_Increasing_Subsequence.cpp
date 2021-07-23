#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int i, j, arr[n];
	for(i=0;i<n;i++) cin>>arr[i];
	int dp[n], x=0, ans=0;
	dp[0]=1;
	for(i=0;i<n;i++)
	{
		dp[i]=1, x=0;
		for(j=0;j<i;j++)
		{
			if(arr[j]<arr[i])
			{
				x=max(x, dp[j]);
			}
		}
		dp[i]=x+1;
	}
	for(i=0;i<n;i++) ans=max(ans, dp[i]);
	cout<<ans<<endl;
}