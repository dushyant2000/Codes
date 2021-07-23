#include<bits/stdc++.h>
using namespace std;

bool find(string s)
{
	string dict[] = {"mobile","samsung","sam","sung","man","mango",
				"icecream","and","go","i","like","ice","cream"}; 
	int n=sizeof(dict)/sizeof(dict[0]);
	for(int i=0;i<n;i++)
	{
		if(dict[i].compare(s)==0) return true;
	}
	return false;
}

bool solve(string s)
{
	int n=s.size();
	if(n==0) return true;
	for(int i=1;i<=n;i++)
	{
		if(find(s.substr(0, i)) && solve(s.substr(i, n-i))) return true;
	}
	return false;
}

int main()
{
	string s;
	cin>>s;
	if(solve(s)) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}