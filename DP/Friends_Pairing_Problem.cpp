#include<bits/stdc++.h>
using namespace std;

int fun(int n)
{
	int i, f[n+1];
	f[0]=1;
	f[1]=1;
	for(i=2;i<=n;i++)
	{
		f[i]=f[i-1]+(i-1)*f[i-2];
	}
	return f[n];
}

int main()
{
	int n;
	cin>>n;
	cout<<fun(n)<<endl;
}