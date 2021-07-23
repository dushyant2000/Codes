#include<bits/stdc++.h>
using namespace std;

void sieve(int n)
{
	int prime[n+1], p, i;
	for(i=0;i<=n;i++) prime[i]=1;
	for(p=2; p*p<=n; p++)
	{
		if(prime[p]==1)
		{
			for(i=p*p; i<=n; i+=p)
			{
				prime[i]=0;
			}
		}
	}
	for(p=2;p<=n;p++) 
	{
		if(prime[p]==1) cout<<p<<" ";
	}
	cout<<endl;
}

int main()
{
	int n;
	cin>>n;
	sieve(n);
}