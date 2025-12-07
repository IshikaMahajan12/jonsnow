#include <iostream>
#include <vector>
using namespace std;

void dfsUtil(int node, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[node] = true;
    cout << node << " ";
    for (int neigh : adj[node]) {
        if (!visited[neigh]) dfsUtil(neigh, adj, visited);
    }
}

void dfs(int start, vector<vector<int>> &adj, int n) {
    vector<bool> visited(n, false);
    cout << "DFS Traversal: ";
    dfsUtil(start, adj, visited);
    cout << endl;
}

int main() {
    int n, e;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> e;

    vector<vector<int>> adj(n);
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start;
    cout << "Enter start node: ";
    cin >> start;

    dfs(start, adj, n);
}
