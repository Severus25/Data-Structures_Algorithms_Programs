#include <bits/stdc++.h>

using namespace std;

// This code is
int count(int coins[], int n, int sum)
{
	// table[i] will be storing the number of solutions for
	// value i. We need sum+1 rows as the dp is
	// constructed in bottom up manner using the base case
	// (sum = 0)
	int dp[sum + 1];

	// Initialize all table values as 0
	memset(dp, 0, sizeof(dp));

	// Base case (If given value is 0)
	dp[0] = 1;

	// Pick all coins one by one and update the table[]
	// values after the index greater than or equal to the
	// value of the picked coin
	for (int i = 0; i < n; i++)
		for (int j = coins[i]; j <= sum; j++)
			dp[j] += dp[j - coins[i]];
	return dp[sum];
}

// Driver Code
int main()
{
	int coins[] = { 1, 2, 3 };
	int n = sizeof(coins) / sizeof(coins[0]);
	int sum = 5;
	cout << count(coins, n, sum);
	return 0;
}
