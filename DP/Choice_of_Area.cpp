#include<bits/stdc++.h>
using namespace std;
   
int util(int, int, pair<int, int>, pair<int, int>, pair<int, int>, int, map<pair<int,int>,int>);
int solve(int a, int b, pair<int, int> x, pair<int, int> y, pair<int, int> z)
{
  	if(a<=0 || b<=0) return 0;
   	map<pair<int, int>, int> dp;
   	
   	return max(util(a+x.first, b+x.second, x, y, z, 1, dp),
   			max(util(a+y.first, b+y.second, x, y, z, 2, dp), 
   			util(a+z.first, b+z.second, x, y, z, 3, dp))); 
}

int util(int a, int b, pair<int, int> x, pair<int, int> y, pair<int, int> z, int last, map<pair<int,int>,int> dp)
{
   	if(a<=0 || b<=0) return 0;
   	if(dp.find({a,b})!=dp.end())
   		return dp[{a,b}];
   	int val;
   	switch(last)
   	{
   		case 1:
   			val = 1 + max(util(a+y.first, b+y.second, x, y, z, 2, dp),
   						util(a+z.first, b+z.second, x, y, z, 3, dp));
   			break;
   		case 2:
   			val = 1 + max(util(a+x.first, b+x.second, x, y, z, 1, dp),
  						util(a+z.first, b+z.second, x, y, z, 3, dp));
   			break;
   		case 3:
   			val = 1 + max(util(a+x.first, b+x.second, x, y, z, 1, dp),
  						util(a+y.first, b+y.second, x, y, z, 2, dp));
   			break;
   	}
   	dp[{a, b}]=val;
   	return val;
}
    
int main()
{
  	int a, b;
   	cin>>a>>b;
   	pair<int, int> x, y, z;
  	cin>>x.first>>x.second;
   	cin>>y.first>>y.second;
   	cin>>z.first>>z.second;
   	cout<<solve(a, b, x, y, z)<<endl;
}