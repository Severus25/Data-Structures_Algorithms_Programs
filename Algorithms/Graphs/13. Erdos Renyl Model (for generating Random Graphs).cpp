#include <iostream>
#include <vector>
#include <random>

using namespace std;

// Function to generate a random graph using the Erdős-Rényi model
vector<vector<bool>> generateRandomGraph(int numNodes, double p) {
    // Initialize a random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);

    // Create an adjacency matrix to represent the graph
    vector<vector<bool>> graph(numNodes, vector<bool>(numNodes, false));

    // Iterate through all pairs of nodes and add an edge with probability p
    for (int i = 0; i < numNodes; ++i) {
        for (int j = i + 1; j < numNodes; ++j) {
            if (dis(gen) < p) {
                graph[i][j] = graph[j][i] = true; // Add an edge
            }
        }
    }

    return graph;
}

int main() {
    int numNodes = 10;   // Number of nodes in the graph
    double p = 0.3;      // Probability of an edge

    vector<vector<bool>> randomGraph = generateRandomGraph(numNodes, p);

    // Print the adjacency matrix of the generated graph
    for (int i = 0; i < numNodes; ++i) {
        for (int j = 0; j < numNodes; ++j) {
            cout << randomGraph[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
