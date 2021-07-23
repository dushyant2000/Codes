#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<double, int> a, pair<double, int> b)
{
	return a.first>b.first;
}

int solve(int val[], int w[], int n, int W)
{
	double dp[n+1][W+1];
	int i, j;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=W;j++)
		{
			if(i==0 || j==0) dp[i][j]=0;
			else if(j<w[i-1]) dp[i][j] = max(dp[i-1][j], dp[i-1][0]+((j*1.0/w[i-1])*val[i-1]));
			else dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i-1]]+val[i-1]);
		}
	}
	return dp[n][W];
}


int main()
{
	int n;
	cin>>n;
	int i, val[n], w[n], W;
	for(i=0;i<n;i++) cin>>val[i];
	for(i=0;i<n;i++) cin>>w[i];
	cin>>W;
	vector<pair<double, int>> vec;
	for(i=0;i<n;i++) vec.push_back({val[i]*1.0/w[i], i});
	sort(vec.begin(), vec.end(), cmp);
	double sum=0;
	for(i=0;i<n;i++)
	{
		if(W>=w[vec[i].second])
		{
			sum+=val[vec[i].second];
			W-=w[vec[i].second];
		}
		else
		{
			sum+=(W*1.0/w[vec[i].second])*val[vec[i].second];
			break;
		}
	}
	cout<<sum<<endl;
	cout<<solve(val, w, n, W)<<endl;
}