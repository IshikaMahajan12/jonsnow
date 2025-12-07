#include "CSP_Implementation.cpp"
using namespace std;

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
