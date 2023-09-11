#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Graph {
public:
    int V;
    vector<vector<int>> adj;

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v, int weight) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void eulerianCircuit() {
        int oddDegreeCount = 0;
        for (int i = 0; i < V; i++) {
            if (adj[i].size() % 2 != 0) {
                oddDegreeCount++;
            }
        }

        if (oddDegreeCount > 2) {
            cout << "No Eulerian Circuit exists in this graph." << endl;
            return;
        }

        int startVertex = 0;
        for (int i = 0; i < V; i++) {
            if (adj[i].size() % 2 != 0) {
                startVertex = i;
                break;
            }
        }

        stack<int> st;
        vector<int> circuit;

        st.push(startVertex);
        while (!st.empty()) {
            int u = st.top();
            if (adj[u].empty()) {
                circuit.push_back(u);
                st.pop();
            } else {
                int v = adj[u].back();
                adj[u].pop_back();
                for (int i = 0; i < adj[v].size(); i++) {
                    if (adj[v][i] == u) {
                        adj[v].erase(adj[v].begin() + i);
                        break;
                    }
                }
                st.push(v);
            }
        }

        cout << "Eulerian Circuit: ";
        for (int i = circuit.size() - 1; i >= 0; i--) {
            cout << circuit[i];
            if (i != 0) cout << " -> ";
        }
        cout << endl;
    }
};

int main() {
    Graph g(7); // Change the number of vertices and edges as needed

    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(2, 4, 1);
    g.addEdge(3, 4, 1);
    g.addEdge(3, 5, 1);
    g.addEdge(4, 5, 1);
    g.addEdge(4, 6, 1);
    g.addEdge(5, 6, 1);

    g.eulerianCircuit();

    return 0;
}
