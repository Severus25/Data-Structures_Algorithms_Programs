// C++ program to generate a graph for a
// given fixed degrees
#include <bits/stdc++.h>
using namespace std;

// A function to print the adjacency matrix.
void printMat(int degseq[], int n)
{
	// n is number of vertices
	int mat[n][n];
	memset(mat, 0, sizeof(mat));

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {

			// For each pair of vertex decrement
			// the degree of both vertex.
			if (degseq[i] > 0 && degseq[j] > 0) {
				degseq[i]--;
				degseq[j]--;
				mat[i][j] = 1;
				mat[j][i] = 1;
			}
		}
	}

	// Print the result in specified format
	cout << "\n" << setw(3) << "	 ";
	for (int i = 0; i < n; i++)
		cout << setw(3) << "(" << i << ")";
	cout << "\n\n";
	for (int i = 0; i < n; i++) {
		cout << setw(4) << "(" << i << ")";
		for (int j = 0; j < n; j++)
			cout << setw(5) << mat[i][j];
		cout << "\n";
	}
}

// driver program to test above function
int main()
{
	int degseq[] = { 2, 2, 1, 1, 1 };
	int n = sizeof(degseq) / sizeof(degseq[0]);
	printMat(degseq, n);
	return 0;
}
