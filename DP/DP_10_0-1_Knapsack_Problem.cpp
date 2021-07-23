#include<bits/stdc++.h>
using namespace std;

int dp[1000][1000], mat[1000][1000];

void print_items(int[], int[], int, int);

int knapsack(int val[], int w[], int n, int W)	//memoized approach
{
	if(n==0 || W<=0) return 0;
	if(dp[n][W]!=-1) return dp[n][W];
	if(W<w[n-1]) return dp[n][W] = knapsack(val, w, n-1, W);
	return dp[n][W] = max(knapsack(val, w, n-1, W), knapsack(val, w, n-1, W-w[n-1])+val[n-1]);
}

int knapsack_tab(int val[], int w[], int n, int W)	//tabulation approach
{
	int i, j;

	for(i=0;i<=n;i++) mat[i][0]=0;
	for(j=0;j<=W;j++) mat[0][j]=0;

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=W;j++)
		{
			if(j>=w[i-1]) mat[i][j] = max(mat[i-1][j], mat[i-1][j-w[i-1]]+val[i-1]);
			else mat[i][j] = mat[i-1][j];
		}
	}

	print_items(val, w, n, W);
	cout<<"Total value - ";
	return mat[n][W];
}

void print_items(int val[], int w[], int n, int W)
{
	int i=n, j=W;
	vector<int> vec;
	while(i>0 && j>0)
	{
		if(mat[i][j]!=mat[i-1][j])
		{
			j-=w[i-1];
			vec.push_back(w[i-1]);
		}
		i--;
	}
	cout<<"Weights of the items in the knapsack - ";
	for(i=0;i<vec.size();i++) cout<<vec[i]<<" ";
	cout<<endl;
}

int main()
{
	int n;
	cin>>n;
	int i, val[n], w[n], W;
	for(i=0;i<n;i++) cin>>val[i];
	for(i=0;i<n;i++) cin>>w[i];
	cin>>W;
	memset(dp, -1, sizeof dp);
	cout<<"Total value - "<<knapsack(val, w, n, W)<<endl;
	cout<<knapsack_tab(val, w, n, W)<<endl;
}