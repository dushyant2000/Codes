#include<bits/stdc++.h>
#define inf 100000
using namespace std;

int cost[1000][1000], dp[1000], mp[1000]; 

int solve(int a[], int n)
{
	if(n==0) return 0;
	if(dp[n]!=-1) return dp[n];
	dp[n]=inf;
	for(int i=1;i<=n;i++)
	{
		int val = solve(a, i-1);
		if(val!=n && cost[i][n]!=inf && (val+cost[i][n])<dp[n])
		{
			dp[n] = val+cost[i][n];
			mp[n]=i;
		}
	}
	return dp[n];
}

int printSolution(int mp[], int n) 
{ 
	int k; 
	if (mp[n] == 1) 
		k = 1; 
	else
		k = printSolution (mp, mp[n]-1) + 1; 
	cout<<"Line number "<<k<<": From word no. "<<mp[n]<<" to "<<n<<endl; 
	return k; 
} 

int main()
{
	int n, m;
	cin>>n>>m;
	int i, j, a[n+1], sum=0;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=n;i++)
	{
		sum=0;
		for(j=i;j<=n;j++)
		{
			if(i==j) sum+=a[j];
			else sum+=(a[j]+1);

			if(sum==m || (j==n && sum<=m)) cost[i][j]=0;
			else if(sum>m) cost[i][j]=inf;
			else cost[i][j]=((m-sum)*(m-sum));
		}
	}
	memset(dp, -1, sizeof dp);
	solve(a, n);
	printSolution(mp, n);
}