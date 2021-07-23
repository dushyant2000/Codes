#include<bits/stdc++.h>
using namespace std;
 
#define lli long long int
#define lld long double
#define ff first
#define ss second
#define pb push_back
#define sz(x) (x).size()
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define mp make_pair
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a*b)/__gcd(a, b)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

const int N = 1e3+9;
const int INF = 1e6+9;
const int mod = 998244353;

int main()
{
	string text, patt;
	cin>>text>>patt;

	lli n, m;
	n = text.size();
	m = patt.size();

	lli lps[m], i, j=0;
	lps[0]=0;
	for(i=1; i<m; i++)
	{
		while(j>0 && patt[i]!=patt[j])
		{
			j = lps[j-1];
		}
		if(patt[i]==patt[j]) lps[i]=j+1;
		else lps[i]=0;
	}
	j=0;
	lli flag=0, ans=0;
	for(i=0; i<n; i++)
	{
		while(j>0 && text[i]!=patt[j])
		{
			j = lps[j-1];
		}
		if(text[i]==patt[j]) j=j+1;
		else j=0;
		if(j==m) {flag=1; break;}
	}
	if(flag==1) ans=i-j+1;
	else ans=-1;
	cout<<ans<<endl;
}