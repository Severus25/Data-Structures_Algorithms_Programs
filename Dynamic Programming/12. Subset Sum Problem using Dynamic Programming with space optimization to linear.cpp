// A Dynamic Programming solution for subset sum problem with space optimization
#include <bits/stdc++.h>
using namespace std;

// Returns true if there is a subset of set[]
// with sum equal to given sum
bool isSubsetSum(int set[], int n, int sum) {
	vector<bool> prev(sum + 1);
	// If sum is 0, then answer is true
	for (int i = 0; i <= n; i++)
		prev[0] = true;

	// If sum is not 0 and set is empty,
	// then answer is false
	for (int i = 1; i <= sum; i++)
		prev[i] = false;

	// curr array to store the current row result generated
	// with help of prev array
	vector<bool> curr(sum + 1);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (j < set[i - 1])
				curr[j] = prev[j];
			if (j >= set[i - 1])
				curr[j] = prev[j] || prev[j - set[i - 1]];
		}
		// now curr becomes prev for i+1 th element
		prev = curr;
	}

	return prev[sum];
}

// Driver code
int main() {
	int set[] = { 3, 34, 4, 12, 5, 2 };
	int sum = 9;
	int n = sizeof(set) / sizeof(set[0]);
	if (isSubsetSum(set, n, sum) == true)
		cout << "Found a subset with given sum";
	else
		cout << "No subset with given sum";
	return 0;
}

