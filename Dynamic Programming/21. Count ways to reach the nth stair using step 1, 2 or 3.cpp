// C++ Program to find n-th stair using step size 1 or 2 or 3.
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	int findStepHelper(int n, vector<int>& dp)
	{
		// Base Case
		if (n == 0)
			return 1;
		else if (n < 0)
			return 0;
		// If subproblems are already calculated
		//then return it
		if (dp[n] != -1) {
			return dp[n];
		}

	// store the subproblems in the vector
		return dp[n] = findStepHelper(n - 3, dp)
					+ findStepHelper(n - 2, dp)
					+ findStepHelper(n - 1, dp);
	}

	// Returns count of ways to reach n-th stair
	// using 1 or 2 or 3 steps.
public:
	int findStep(int n)
	{
		vector<int> dp(n + 1, -1);
		return findStepHelper(n, dp);
	}
};

// Driver code
int main()
{
	Solution s;
	int n = 4;

	cout << s.findStep(n);
	return 0;
}
