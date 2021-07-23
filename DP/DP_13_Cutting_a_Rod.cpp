#include<bits/stdc++.h>
using namespace std;

int* dp;
int solve(int a[], int n)
{
	if(n<=0) return 0;

	if(dp[n]!=-1) return dp[n];

	int i, val=0;
	for(i=0;i<n;i++)
	{
		val=max(val, a[i]+solve(a, n-i-1));
	}
	return dp[n]=val;
}

int solve_tab(int a[], int n)
{
	int arr[n+1];
	arr[0]=0;
	int i, j, val=0;
	for(i=1;i<=n;i++)
	{
		val=0;
		for(j=0;j<i;j++)
		{
			val = max(val, a[j]+arr[i-j-1]);
		}
		arr[i]=val;
	}
	return arr[n];
}

int main()
{
	int n;
	cin>>n;
	int i, a[n];
	dp = new int[n+1];
	for(i=0;i<n+1;i++) dp[i]=-1;
	for(i=0;i<n;i++) cin>>a[i];
	cout<<solve(a, n)<<endl;
	cout<<solve_tab(a, n)<<endl;
}