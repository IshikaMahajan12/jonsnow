#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<string, vector<string>> adj = {
    {"A", {"B","C"}},
    {"B", {"A","C","D"}},
    {"C", {"A","B","D"}},
    {"D", {"B","C"}}
};

map<string,string> color;
vector<string> colors = {"Red","Green","Blue"};

bool isSafe(string node, string col) {
    for (auto neigh : adj[node]) {
        if (color[neigh] == col) return false;
    }
    return true;
}

bool assignColor(vector<string> nodes, int idx) {
    if (idx == nodes.size()) return true;
    string node = nodes[idx];
    for (auto col : colors) {
        if (isSafe(node, col)) {
            color[node] = col;
            if (assignColor(nodes, idx+1)) return true;
            color[node] = "";
        }
    }
    return false;
}

int main() {
    vector<string> nodes = {"A","B","C","D"};
    if (assignColor(nodes, 0)) {
        cout << "Color Assignment:\n";
        for (auto &p : color) cout << p.first << " -> " << p.second << endl;
    } else {
        cout << "No solution found\n";
    }
}
