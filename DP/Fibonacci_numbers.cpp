#include<bits/stdc++.h>
using namespace std;

int main()					//Time optimized and space optimized code
{
	int n;
	cin>>n;
	int i, a=1, b=1, c;
	if(n==0 || n==1) {cout<<1<<endl; return 0;}
	for(i=2;i<n;i++)
	{
		c = a+b;
		a=b;
		b=c;
	}
	cout<<c<<endl;
}