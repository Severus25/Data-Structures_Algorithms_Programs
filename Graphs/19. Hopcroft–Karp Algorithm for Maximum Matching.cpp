#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int NIL = 0;
const int INF = INT_MAX;

class HopcroftKarp {
private:
    int n, m;
    vector<vector<int>> graph;
    vector<int> match;
    vector<int> dist;

    bool bfs() {
        queue<int> q;
        dist.assign(n + 1, INF);

        for (int u = 1; u <= n; ++u) {
            if (match[u] == NIL) {
                dist[u] = 0;
                q.push(u);
            }
        }

        dist[NIL] = INF;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (u != NIL) {
                for (int v : graph[u]) {
                    if (dist[match[v]] == INF) {
                        dist[match[v]] = dist[u] + 1;
                        q.push(match[v]);
                    }
                }
            }
        }

        return (dist[NIL] != INF);
    }
    bool dfs(int u) {
        if (u == NIL)
            return true;

        for (int v : graph[u]) {
            if (dist[match[v]] == dist[u] + 1 && dfs(match[v])) {
                match[u] = v;
                match[v] = u;
                return true;
            }
        }
        dist[u] = INF;
        return false;
    }
public:
    HopcroftKarp(int n, int m) {
        this->n = n;
        this->m = m;
        graph.resize(n + 1);
        match.assign(n + 1, NIL);
    }

    void addEdge(int u, int v) {
        graph[u].push_back(v);
    }

    int maxMatching() {
        int matching = 0;
        while (bfs()) {
            for (int u = 1; u <= n; ++u) {
                if (match[u] == NIL && dfs(u))
                    matching++;
            }
        }
        return matching;
    }
};

int main() {
    int n, m, e;
    cout << "Enter the number of vertices in set U: ";
    cin >> n;
    cout << "Enter the number of vertices in set V: ";
    cin >> m;
    cout << "Enter the number of edges: ";
    cin >> e;

    HopcroftKarp hk(n, m);

    cout << "Enter the edges in the format (u v):\n";
    for (int i = 0; i < e; ++i) {
        int u, v;
        cin >> u >> v;
        hk.addEdge(u, v);
    }
    int maxMatching = hk.maxMatching();
    cout << "Maximum Matching Size: " << maxMatching << endl;
    return 0;
}
