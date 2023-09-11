#include <bits/stdc++.h>
using namespace std;

// Returns minimum cost for sorting arr[]
// using reverse operation. This function
// returns -1 if it is not possible to sort.
int minCost(string arr[], int cost[], int N)
{
	int dp0 = 0; // Minimum cost for the previous string in original order
	int dp1 = cost[0]; // Minimum cost for the previous string in reversed order

	for (int i = 1; i < N; i++)
	{
		int cur0 = INT_MAX; // Minimum cost for the current string in original order
		int cur1 = INT_MAX; // Minimum cost for the current string in reversed order

		// Update dp values only if the current string is lexicographically larger
		if (arr[i] >= arr[i - 1])
			cur0 = min(cur0, dp0);
		if (arr[i] >= string(arr[i - 1].rbegin(), arr[i - 1].rend()))
			cur0 = min(cur0, dp1);

		// Update dp values for reversed strings
		if (string(arr[i].rbegin(), arr[i].rend()) >= arr[i - 1])
			cur1 = min(cur1, dp0 + cost[i]);
		if (string(arr[i].rbegin(), arr[i].rend()) >= string(arr[i - 1].rbegin(), arr[i - 1].rend()))
			cur1 = min(cur1, dp1 + cost[i]);

		dp0 = cur0; // Update the minimum cost for the previous string in original order
		dp1 = cur1; // Update the minimum cost for the previous string in reversed order
	}

	// Get the minimum from both entries of the last index
	int res = min(dp0, dp1);

	return (res == INT_MAX) ? -1 : res;
}

// Driver code to test above methods
int main()
{
	string arr[] = {"aa", "ba", "ac"};
	int cost[] = {1, 3, 1};
	int N = sizeof(arr) / sizeof(arr[0]);

	int res = minCost(arr, cost, N);
	if (res == -1)
		cout << "Sorting not possible\n";
	else
		cout << "Minimum cost to sort strings is " << res;

	return 0;
}
