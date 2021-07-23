#include<bits/stdc++.h>
using namespace std;

bool fun(int a[], int n, int m)
{
	if(n>m) return true;

	bool DP[m];
	memset(DP, false, m);

	int i, j;
	for(i=0;i<n;i++)
	{
		if(DP[0]) return true;

		bool temp[m];
		memset(temp, false, m);
		
		for(j=0;j<m;j++)
		{
			if(DP[j]==true)
			{
				if(DP[(j+a[i])%m]==false)
				{
					temp[(j+a[i])%m]=true;
				}
			}
		}
		for(j=0;j<m;j++)
		{
			if(temp[j]==true)	DP[j]=true;
		}
		DP[(a[i])%m]=true;
	}
	return DP[0];
}

int main()
{
	int n, m;
	cin>>n>>m;
	int i, a[n];
	for(i=0;i<n;i++) cin>>a[i];
	fun(a, n, m)? cout<<"YES"<<endl: cout<<"NO"<<endl;
}