#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<char, vector<vector<char>>> graph;
map<char, int> heuristic;

int solveAOStar(char node) {
    if (graph.find(node) == graph.end()) return heuristic[node];
    int minCost = 1e9;
    for (auto &group : graph[node]) {
        int sum = 0;
        for (char child : group) sum += solveAOStar(child);
        minCost = min(minCost, sum);
    }
    heuristic[node] = minCost;
    return heuristic[node];
}

int main() {
    // Example graph
    graph['A'] = {{'B','C'}, {'D'}};
    graph['B'] = {{'E'}, {'F'}};
    heuristic['C'] = 2; heuristic['D'] = 4;
    heuristic['E'] = 1; heuristic['F'] = 3;

    cout << "AO* solution cost from A: " << solveAOStar('A') << endl;`
}
