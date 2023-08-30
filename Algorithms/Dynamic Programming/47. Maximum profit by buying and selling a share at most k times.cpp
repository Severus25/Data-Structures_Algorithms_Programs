// C++ program to find out maximum profit by buying and selling a share atmost k times
// given stock price of n days
#include <bits/stdc++.h>
using namespace std;

int B;
vector<int> A;
int dp[501][201][2];
int solve(int j, int i, int b)
{
	// if the result has already been calculated return that result
	if (dp[i][j][b] != -1)
		return dp[i][j][b];
	// if i has reached the end of the array return 0
	if (i == B)
		return 0;
	// if we have exhausted the number of transaction return 0
	if (j == 0)
		return 0;
	int res;
	// if we are to buy stocks
	if (b == 1)
		res = max(-A[i] + solve(j, i + 1, 0), solve(j, i + 1, 1));
	// if we are to sell stock and complete one transaction
	else
		res = max(A[i] + solve(j - 1, i + 1, 1), solve(j, i + 1, 0));
	// return the result
	return dp[i][j][b] = res;
}
int maxProfit(int K, int N, int C[])
{
	A = vector<int>(N, 0);
	// Copying C to global A
	for (int i = 0; i < N; i++)
		A[i] = C[i];
	// Initializing DP with -1
	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= K; j++)
		{
			dp[i][j][1] = -1;
			dp[i][j][0] = -1;
		}
	// Copying n to global B
	B = N;
	return solve(K, 0, 1);
}

// driver code
int main()
{
	// TEST 1
	int k1 = 3;
	int price1[] = {12, 14, 17, 10, 14, 13, 12, 15};
	int n1 = sizeof(price1) / sizeof(price1[0]);
	cout << "Maximum profit is: "
		<< maxProfit(k1, n1, price1) << endl;
	// TEST 2
	int k2 = 2;
	int price2[] = {10, 22, 5, 75, 65, 80};
	int n2 = sizeof(price2) / sizeof(price2[0]);

	cout << "Maximum profit is: "
		<< maxProfit(k2, n2, price2);
	return 0;
}
