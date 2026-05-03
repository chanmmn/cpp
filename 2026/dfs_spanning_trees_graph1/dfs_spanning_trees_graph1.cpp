#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

struct DfsState {
    vector<int> stack;
    vector<bool> visited;
    vector<pair<int, int>> treeEdges;
    vector<int> visitOrder;
};

static string edgeSetToString(const vector<pair<int, int>>& edges, const vector<string>& names) {
    string out;
    for (size_t i = 0; i < edges.size(); ++i) {
        out += "(" + names[edges[i].first] + "-" + names[edges[i].second] + ")";
        if (i + 1 < edges.size()) {
            out += " ";
        }
    }
    return out;
}

static string visitOrderToString(const vector<int>& order, const vector<string>& names) {
    string out;
    for (size_t i = 0; i < order.size(); ++i) {
        out += names[order[i]];
        if (i + 1 < order.size()) {
            out += "->";
        }
    }
    return out;
}

static void enumerateAllDfsTrees(
    const vector<vector<int>>& adjacency,
    const vector<string>& names,
    DfsState state,
    set<vector<pair<int, int>>>& uniqueTrees,
    set<string>& uniqueTraversals
) {
    const int n = static_cast<int>(adjacency.size());

    int visitedCount = 0;
    for (bool seen : state.visited) {
        if (seen) {
            ++visitedCount;
        }
    }

    if (visitedCount == n) {
        vector<pair<int, int>> normalized = state.treeEdges;
        for (auto& e : normalized) {
            if (e.first > e.second) {
                swap(e.first, e.second);
            }
        }
        sort(normalized.begin(), normalized.end());
        uniqueTrees.insert(normalized);
        uniqueTraversals.insert(visitOrderToString(state.visitOrder, names));
        return;
    }

    if (state.stack.empty()) {
        return;
    }

    const int u = state.stack.back();
    vector<int> choices;
    for (int v : adjacency[u]) {
        if (!state.visited[v]) {
            choices.push_back(v);
        }
    }

    if (!choices.empty()) {
        for (int v : choices) {
            DfsState next = state;
            next.stack.push_back(v);
            next.visited[v] = true;
            next.treeEdges.push_back({u, v});
            next.visitOrder.push_back(v);
            enumerateAllDfsTrees(adjacency, names, next, uniqueTrees, uniqueTraversals);
        }
    } else {
        DfsState backtrack = state;
        backtrack.stack.pop_back();
        enumerateAllDfsTrees(adjacency, names, backtrack, uniqueTrees, uniqueTraversals);
    }
}

int main() {
    // Graph extracted from graph1.xlsx adjacency matrix (non-zero = edge, union of both directions).
    // Vertices: A, B, C, D, E
    // Edges: A-B, A-C, A-D, A-E, B-C, C-D, C-E
    const vector<string> names = {"A", "B", "C", "D", "E"};
    vector<vector<int>> adjacency(names.size());

    auto addEdge = [&](int u, int v) {
        adjacency[u].push_back(v);
        adjacency[v].push_back(u);
    };

    addEdge(0, 1);  // A-B
    addEdge(0, 2);  // A-C
    addEdge(0, 3);  // A-D
    addEdge(0, 4);  // A-E
    addEdge(1, 2);  // B-C
    addEdge(2, 3);  // C-D
    addEdge(2, 4);  // C-E

    DfsState start;
    start.stack = {0};      // Start from A
    start.visited = vector<bool>(names.size(), false);
    start.visited[0] = true;
    start.visitOrder = {0};

    set<vector<pair<int, int>>> uniqueTrees;
    set<string> uniqueTraversals;
    enumerateAllDfsTrees(adjacency, names, start, uniqueTrees, uniqueTraversals);

    cout << "All possible DFS traversals from A: " << uniqueTraversals.size() << "\n";
    int t = 1;
    for (const string& traversal : uniqueTraversals) {
        cout << "  Traversal " << t++ << ": " << traversal << "\n";
    }

    cout << "\nUnique DFS spanning trees from A: " << uniqueTrees.size() << "\n";
    int i = 1;
    for (const auto& tree : uniqueTrees) {
        cout << "  Tree " << i++ << ": " << edgeSetToString(tree, names) << "\n";
    }

    return 0;
}
