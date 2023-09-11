#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

class Graph {
	int vertices;
	int adjacency_matrix[MAX][MAX];

public:
	Graph(int vertices)
	{
		this->vertices = vertices;
		memset(adjacency_matrix, 0,
			sizeof(adjacency_matrix));
	}
	void insert(int source, int destination)
	{
		adjacency_matrix[destination - 1] = 1;
	}

	bool is_sink(int i)
	{
		for (int j = 0; j < vertices; j++) {
			if (adjacency_matrix[i][j] == 1)
				return false;
			if (adjacency_matrix[j][i] == 0 && j != i)
				return false;
		}
		return true;
	}

	int eliminate()
	{
		int i = 0, j = 0;
		while (i < vertices && j < vertices) {
			if (adjacency_matrix[i][j] == 1)
				i = i + 1;
			else
				j = j + 1;
		}

		if (i > vertices)
			return -1;
		else if (!is_sink(i))
			return -1;
		else
			return i;
	}
};

int main()
{
	int number_of_vertices = 6, number_of_edges = 5;
	Graph g(number_of_vertices);
	g.insert(1, 6);
	g.insert(2, 3);
	g.insert(2, 4);
	g.insert(4, 3);
	g.insert(5, 3);

	int vertex = g.eliminate();

	if (vertex >= 0)
		cout << "Sink found at vertex " << (vertex + 1)
			<< endl;
	else
		cout << "No Sink" << endl;

	return 0;
}
