// C++ program to count number if sink nodes
#include<bits/stdc++.h>
using namespace std;

// Return the number of Sink NOdes.
int countSink(int n, int m, int edgeFrom[],
						int edgeTo[])
{
	// Array for marking the non-sink node.
	int mark[n];
	memset(mark, 0, sizeof mark);

	// Marking the non-sink node.
	for (int i = 0; i < m; i++)
		mark[edgeFrom[i]] = 1;

	// Counting the sink nodes.
	int count = 0;
	for (int i = 1; i <= n ; i++)
		if (!mark[i])
			count++;

	return count;
}

// Driven Program
int main()
{
	int n = 4, m = 2;
	int edgeFrom[] = { 2, 4 };
	int edgeTo[] = { 3, 3 };

	cout << countSink(n, m, edgeFrom, edgeTo) << endl;

	return 0;
}
