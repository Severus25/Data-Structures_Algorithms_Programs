// CPP program to find number of ways to make stable
// tower of given height.
#include <bits/stdc++.h>
using namespace std;
#define N 100

int possibleWays(int n, int m, int k)
{
	int dp[N][N];
	int presum[N][N];
	memset(dp, 0, sizeof dp);
	memset(presum, 0, sizeof presum);

	// Initializing 0th row to 0.
	for (int i = 1; i < n + 1; i++) {
		dp[0][i] = 0;
		presum[0][i] = 1;
	}

	// Initializing 0th column to 0.
	for (int i = 0; i < m + 1; i++)
		presum[i][0] = dp[i][0] = 1;

	// For each row from 1 to m
	for (int i = 1; i < m + 1; i++) {

		// For each column from 1 to n.
		for (int j = 1; j < n + 1; j++) {

			// Initializing dp[i][j] to presum of (i - 1, j).
			dp[i][j] = presum[i - 1][j];
			if (j > k) {
				dp[i][j] -= presum[i - 1][j - k - 1];
			}
		}

		// Calculating presum for each i, 1 <= i <= n.
		for (int j = 1; j < n + 1; j++)
			presum[i][j] = dp[i][j] + presum[i][j - 1];
	}

	return dp[m][n];
}

// Driver Program
int main()
{
	int n = 3, m = 3, k = 2;
	cout << possibleWays(n, m, k) << endl;
	return 0;
}
