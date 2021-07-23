#include<bits/stdc++.h>
using namespace std;

int solve(int a[], int n)
{
	int inc[n+1], dec[n+1], i, j, ans=0;

	for(i=1;i<=n;i++)
	{
		inc[i]=1;
		for(j=1;j<i;j++)
		{
			if(a[i]>a[j] && inc[i]<inc[j]+1)
				inc[i]=inc[j]+1;
		}
	}

	for(i=n;i>=1;i--)
	{
		dec[i]=1;
		for(j=n;j>i;j--)
		{
			if(a[i]>a[j] && dec[i]<dec[j]+1)
				dec[i]=dec[j]+1;
		}
	}
	for(i=1;i<=n;i++)	ans = max(ans, inc[i]+dec[i]-1);
	return ans;
}

int main()
{
	int n; 
	cin>>n;
	int i, a[n+1];
	for(i=1;i<=n;i++) cin>>a[i];
	cout<<"Length of LBS is - ";
	cout<<solve(a, n)<<endl;
}