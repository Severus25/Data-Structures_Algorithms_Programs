// A Dynamic Programming based program to find minimum number insertions needed to make a string palindrome
#include <bits/stdc++.h>
using namespace std;


// A DP function to find minimum
// number of insertions
int findMinInsertionsDP(char str[], int n)
{
	// Create a table of size n*n. table[i][j]
	// will store minimum number of insertions
	// needed to convert str[i..j] to a palindrome.
	int table[n][n], l, h, gap;

	// Initialize all table entries as 0
	memset(table, 0, sizeof(table));

	// Fill the table
	for (gap = 1; gap < n; ++gap)
		for (l = 0, h = gap; h < n; ++l, ++h)
			table[l][h] = (str[l] == str[h])?
						table[l + 1][h - 1] :
						(min(table[l][h - 1],
							table[l + 1][h]) + 1);

	// Return minimum number of insertions
	// for str[0..n-1]
	return table[0][n - 1];
}

// Driver Code
int main()
{
	char str[] = "geeks";
	cout << findMinInsertionsDP(str, strlen(str));
	return 0;
}
