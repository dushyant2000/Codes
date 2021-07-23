#include<bits/stdc++.h>
using namespace std;

int** dp;

int fun(int a[], int n, int sum)			//memoized approach
{
	if(sum==0) return 1;
	if(n==0 || sum<0) return 0;
	if(dp[n][sum]!=-1) return dp[n][sum];
	return dp[n][sum] = fun(a, n-1, sum) || fun(a, n-1, sum-a[n-1]);
}

int fun_tab(int a[], int n, int sum)		//tabulation approach
{
	int mat[n+1][sum+1];
	int i, j;
	for(i=0;i<n+1;i++) mat[i][0]=1;
	for(j=1;j<sum+1;j++) mat[0][j]=0;
	
	for(i=1;i<n+1;i++)
	{
		for(j=1;j<sum+1;j++)
		{
			if(j<a[i-1]) mat[i][j] = mat[i-1][j];
			else mat[i][j] = mat[i-1][j] || mat[i-1][j-a[i-1]];
		}
	}
	/*for(i=0;i<n+1;i++)
	{
		for(j=0;j<sum+1;j++) cout<<mat[i][j]<<" ";
		cout<<endl;
	}*/
	return mat[n][sum];
}

int main()
{
	int n, sum;
	cin>>n>>sum;
	dp = new int*[n];
	int i, j, a[n], ans, ans_tab;
	for(i=0;i<n;i++) cin>>a[i];
	for(i=0;i<n+1;i++)
	{
		dp[i] = new int[sum+1];
		for(j=0;j<sum+1;j++) dp[i][j]=-1;
	}
	
	ans = fun(a, n, sum);
	if(ans==1) cout<<"TRUE"<<endl;
	else cout<<"FALSE"<<endl;
	
	ans_tab = fun_tab(a, n, sum);
	if(ans_tab==1) cout<<"TRUE"<<endl;
	else cout<<"FALSE"<<endl;
}