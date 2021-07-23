#include<bits/stdc++.h>
#define m 4
#define n 4
using namespace std;

void find_path(int dp[m][n], int mat[m][n], int i, int j)
{
	list<pair<int, int>> path;
	path.push_front({i, j});
	while(dp[i][j]!=0)
	{
		if(i>0 && dp[i][j]-1==dp[i-1][j])
		{
			path.push_front({i-1, j});
			i--;
		}
		else if(j>0 && dp[i][j]-1==dp[i][j-1])
		{
			path.push_front({i, j-1});
			j--;
		}
	}

	cout << "Snake sequence is:"; 
    for (auto it = path.begin(); it != path.end(); it++) 
        cout << endl << mat[it->first][it->second] << " ("
             << it->first << ", " << it->second << ")" ; 
}

void solve(int mat[m][n])
{
	int dp[m][n];

	memset(dp, 0, sizeof dp);

	int i, j, max_len=0, maxi=0, maxj=0;

	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==0 && j==0) continue;
			if(i>0 && abs(mat[i-1][j]-mat[i][j])==1)
			{
				dp[i][j] = max(dp[i][j], dp[i-1][j]+1);
				if(max_len<dp[i][j])
				{
					max_len=dp[i][j];
					maxi=i;
					maxj=j;
				}
			}
			if(j>0 && abs(mat[i][j-1]-mat[i][j])==1)
			{
				dp[i][j] = max(dp[i][j], dp[i][j-1]+1);
				if(max_len<dp[i][j])
				{
					max_len=dp[i][j];
					maxi=i;
					maxj=j;
				}
			}
		}
	}

	cout<<"Max length of snake sequence: "<<max_len<<endl;

	find_path(dp, mat, maxi, maxj);
}

int main()
{
	int mat[m][n] = 
    { 
        {9, 6, 5, 2}, 
        {8, 7, 6, 5}, 
        {7, 3, 1, 6}, 
        {1, 1, 1, 7}, 
    };

    solve(mat);
}