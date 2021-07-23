#include<bits/stdc++.h>
using namespace std;

int dim[1000000][9], dp[1000000];

class BOX
{
public:
	int h,w,d;
};

bool cmp(BOX &a, BOX &b)
{
	if(a.d==b.d) return a.w<b.w;
	return a.d<b.d;
}

int box_stacking(BOX box[], int n)
{
	if(n==1) return dp[n]=box[n-1].h;
	if(dp[n]!=-1) return dp[n];
	dp[n]=box[n-1].h;
	for(int i=1;i<n;i++)
	{
		if(box[n-1].w>box[i-1].w && box[n-1].d>box[i-1].d)
		{
			dp[n] = max(dp[n], box[n-1].h+box_stacking(box, i));
		}
	}
	return dp[n];
}

int solve(int n)
{
	BOX box[3*n];
	int i, j=0, ans=0;
	for(i=0;i<n;i++)
	{
		box[j].h = dim[i][0];
		box[j].w = max(dim[i][1], dim[i][2]);
		box[j].d = min(dim[i][1], dim[i][2]);
		j++;

		box[j].h = dim[i][1];
		box[j].w = max(dim[i][0], dim[i][2]);
		box[j].d = min(dim[i][0], dim[i][2]);
		j++;

		box[j].h = dim[i][2];
		box[j].w = max(dim[i][1], dim[i][0]);
		box[j].d = min(dim[i][1], dim[i][0]);
		j++;		
	}
	n = 3*n;
	sort(box, box+n, cmp);
	box_stacking(box, n);
	for(i=1;i<=n;i++) ans=max(ans, dp[i]);
	return ans;
}

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>dim[i][0]>>dim[i][1]>>dim[i][2];
	}
	memset(dp, -1, sizeof dp);
	cout<<solve(n)<<endl;
}