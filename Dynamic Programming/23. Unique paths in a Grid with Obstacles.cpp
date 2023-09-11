// The 2D DP Approach
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
int path(vector<vector<int> >& dp,
		vector<vector<int> >& grid, int i, int j)
{
	if (i < n && j < m && grid[i][j] == 1)
		return 0;
	if (i == n - 1 && j == m - 1)
		return 1;
	if (i >= n || j >= m)
		return 0;
	if (dp[i][j] != -1)
		return dp[i][j];
	int left = path(dp, grid, i + 1, j);
	int right = path(dp, grid, i, j + 1);
	return dp[i][j] = left + right;
}
int uniquePathsWithObstacles(vector<vector<int> >& grid)
{
	n = grid.size();
	m = grid[0].size();
	if (n == 1 && m == 1 && grid[0][0] == 0)
		return 1;
	if (n == 1 && m == 1 && grid[0][0] == 1)
		return 0;
	vector<vector<int> > dp(n, vector<int>(m, -1));

	path(dp, grid, 0, 0);
	
	if (dp[0][0] == -1)
		return 0;
	return dp[0][0];
}
// Driver Code
signed main()
{
	vector<vector<int> > v{ { 0, 0, 0 },
							{ 0, 1, 0 },
							{ 0, 0, 0 } };
	cout << uniquePathsWithObstacles(v) << " \n";
	return 0;
}
