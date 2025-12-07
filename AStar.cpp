#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

struct Node {
    int vertex, g, h;
    bool operator<(const Node &other) const {
        return (g+h) > (other.g+other.h); // f = g + h
    }
};

void aStar(int start, int goal, vector<vector<pair<int,int>>> &adj, vector<int> &heuristic) {
    priority_queue<Node> pq;
    vector<int> dist(adj.size(), INT_MAX);
    dist[start] = 0;
    pq.push({start, 0, heuristic[start]});

    cout << "A* Path: ";
    while (!pq.empty()) {
        Node node = pq.top(); pq.pop();
        cout << node.vertex << " ";
        if (node.vertex == goal) break;
        for (auto &edge : adj[node.vertex]) {
            int neigh = edge.first, cost = edge.second;
            if (dist[neigh] > node.g + cost) {
                dist[neigh] = node.g + cost;
                pq.push({neigh, dist[neigh], heuristic[neigh]});
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
    cout << "Enter edges (u v cost):\n";
    for (int i = 0; i < e; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    vector<int> heuristic(n);
    cout << "Enter heuristic values for nodes: ";
    for (int i = 0; i < n; i++) cin >> heuristic[i];

    int start, goal;
    cout << "Enter start and goal: ";
    cin >> start >> goal;

    aStar(start, goal, adj, heuristic);
}
