#include<bits/stdc++.h>
using namespace std;


int solve(int n, int** a, int** t, int e[], int x[])
{
	int t1[n+1], t2[n+1], i;

	t1[1]=a[1][1]+e[1];
	t2[1]=a[2][1]+e[2];

	for(i=2;i<=n;i++)
	{
		t1[i] = min(t1[i-1]+a[1][i], t2[i-1]+a[1][i]+t[2][i]);
		t2[i] = min(t2[i-1]+a[2][i], t1[i-1]+a[2][i]+t[1][i]);
	}
	return min(t1[n]+x[1], t2[n]+x[2]);
}

int main()
{
	int n;
	cin>>n;
	int i, j, e[3], x[3];
	int** a;
	int** t;
	a = new int*[3];
	t = new int*[3];
	for(i=0;i<3;i++)
	{
		a[i]=new int[n+1];
		t[i]=new int[n+1];
	}
	for(i=1;i<=2;i++)
	{
		for(j=1;j<=n;j++) cin>>a[i][j];
	}
	for(i=1;i<=2;i++)
	{
		for(j=1;j<=n;j++) cin>>t[i][j];
	}
	for(i=1;i<=2;i++) cin>>e[i];
	for(i=1;i<=2;i++) cin>>x[i];
	cout<<solve(n, a, t, e, x)<<endl;
}