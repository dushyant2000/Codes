#include<bits/stdc++.h>
#define inf 1000000
using namespace std;

int dp[1000][1000];

int solve(pair<int, int> a[], int n, int i, int j)  //memoized approach
{
	if(i==j) return 0;
	if(dp[i][j]!=-1) return dp[i][j];
	dp[i][j] = inf;
	for(int k=i+1;k<=j;k++)
	{
		dp[i][j] = min(dp[i][j], solve(a, n, i, k-1)+solve(a, n, k, j)+
			(a[i].first*a[k].first*a[j].second));
	}
	return dp[i][j];
}

int solve_tab(pair<int, int> a[], int n)	//tabulation approach
{
	int mat[n][n], i, j, k, l;

	for(i=0;i<n;i++)	mat[i][i]=0;

	for(l=2;l<=n;l++)
	{
		for(i=0;i<=n-l;i++)
		{
			j=i+l-1;
			mat[i][j]=inf;
			for(k=i+1;k<=j;k++)
			{
				mat[i][j] = min(mat[i][j], mat[i][k-1]+mat[k][j]+
					(a[i].first*a[k].first*a[j].second));
			}
		}
	}

	return mat[0][n-1];
}

int main()
{
	int n;
	cin>>n;
	int i;
	pair<int, int> a[n];
	for(i=0;i<n;i++) cin>>a[i].first>>a[i].second;
	memset(dp, -1, sizeof dp); 
	cout<<solve(a, n, 0, n-1)<<endl;
	cout<<solve_tab(a, n)<<endl;
}