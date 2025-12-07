#include<iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

class CSP {
    map<string, vector<string>> adjList;   // adjacency list for regions
    vector<string> colors;                 // available colors
    map<string, string> assignment;        // region -> assigned color

public:
    CSP(vector<string> colorOptions) {
        colors = colorOptions;
    }

    void addRegion(string region, vector<string> neighbors) {
        adjList[region] = neighbors;
    }

    bool isSafe(string region, string color) {
        for (auto neighbor : adjList[region]) {
            if (assignment[neighbor] == color) {
                return false;
            }
        }
        return true;
    }

    bool solveCSP(vector<string> regions, int index = 0) {
        if (index == regions.size()) return true;

        string region = regions[index];
        for (auto color : colors) {
            if (isSafe(region, color)) {
                assignment[region] = color;
                if (solveCSP(regions, index + 1)) return true;
                assignment[region] = ""; // backtrack
            }
        }
        return false;
    }

    void printAssignment() {
        for (auto pair : assignment) {
            cout << pair.first << " -> " << pair.second << endl;
        }
    }
};
int main() {
    // Available colors
    vector<string> colors = {"Red", "Green", "Blue"};
    CSP csp(colors);

    // Define regions and neighbors (simple map)
    csp.addRegion("A", {"B", "C"});
    csp.addRegion("B", {"A", "C", "D"});
    csp.addRegion("C", {"A", "B", "D"});
    csp.addRegion("D", {"B", "C"});

    vector<string> regions = {"A", "B", "C", "D"};

    if (csp.solveCSP(regions)) {
        cout << "Solution found:\n";
        csp.printAssignment();
    } else {
        cout << "No solution exists.\n";
    }

    return 0;
}
