#include<bits/stdc++.h>
using namespace std;

int** dp;

int solve(int a[], int n, int sum, int curr)
{
	if(sum==curr) return 1;
	if(n==0 && sum!=curr) return 0;
	if(dp[n][sum]!=-1) return dp[n][sum];
	if(a[n-1]>sum) return dp[n][sum] = solve(a, n-1, sum, curr);
	return dp[n][sum] = solve(a, n-1, sum, curr) || solve(a, n-1, sum-a[n-1], curr+a[n-1]);
}

int main()
{
	int n;
	cin>>n;
	int i, j, a[n], sum=0, curr=0;
	for(i=0;i<n;i++) cin>>a[i], sum+=a[i];
	
	dp = new int*[n+1];
	for(i=0; i<n+1; i++)	dp[i] = new int[sum+1];
	memset(dp, -1, sizeof dp);
	
	if(sum%2==1) cout<<"FALSE"<<endl;
	else if(solve(a, n, sum, curr)==1) cout<<"TRUE"<<endl;
	else cout<<"FALSE"<<endl;
	
	/*for(i=1;i<=n;i++)
	{
		for(j=0;j<=sum;j++)	cout<<dp[i][j]<<" ";
		cout<<endl;
	}*/
}