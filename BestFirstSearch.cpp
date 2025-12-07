#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    int vertex, heuristic;
    bool operator<(const Node &other) const {
        return heuristic > other.heuristic; // min-heap
    }
};

void bestFirstSearch(int start, int goal, vector<vector<pair<int,int>>> &adj) {
    priority_queue<Node> pq;
    vector<bool> visited(adj.size(), false);

    pq.push({start, 0});
    visited[start] = true;

    cout << "Best First Search Path: ";
    while (!pq.empty()) {
        int node = pq.top().vertex;
        cout << node << " ";
        pq.pop();
        if (node == goal) break;
        for (auto &edge : adj[node]) {
            int neigh = edge.first, h = edge.second;
            if (!visited[neigh]) {
                visited[neigh] = true;
                pq.push({neigh, h});
            }
        }
    }
    cout << endl;
}

int main() {
    int n, e;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> e;

    vector<vector<pair<int,int>>> adj(n);
    cout << "Enter edges (u v heuristic):\n";
    for (int i = 0; i < e; i++) {
        int u, v, h;
        cin >> u >> v >> h;
        adj[u].push_back({v, h});
        adj[v].push_back({u, h});
    }

    int start, goal;
    cout << "Enter start and goal node: ";
    cin >> start >> goal;

    bestFirstSearch(start, goal, adj);
}
