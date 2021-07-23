#include<bits/stdc++.h>
using namespace std;

int solve(int a[], int n)
{
	int len[n+1], sum[n+1], i, j, ans=0;

	sum[1]=a[1];

	for(i=2;i<=n;i++)
	{
		sum[i]=a[i];
		for(j=1;j<i;j++)
		{
			if(a[i]>a[j] && sum[i]<sum[j]+a[i])
			{
				sum[i]=sum[j]+a[i];
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		ans=max(ans, sum[i]);
	}

	return ans;
}

int main()
{
	int n;
	cin>>n;
	int i, a[n+1];
	for(i=1;i<=n;i++) cin>>a[i];
	cout<<solve(a, n)<<endl;
}