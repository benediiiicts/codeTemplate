#include <bits/stdc++.h>
using namespace std;

map<string, vector<string>> adj;     // Original graph
map<string, vector<string>> inv;     // Transposed graph
stack<string> nodes;                 // Stack to store finish order
set<string> visited;                 // Visited set for DFS
set<string> allNodes;               // All unique nodes
vector<string> scc;                 // One SCC at a time

// 1st DFS
void dfs(string node) {
    visited.insert(node);
    for (auto &neighbor : adj[node]) {
        if (visited.find(neighbor) == visited.end()) {
            dfs(neighbor);
        }
    }
    nodes.push(node); // push when finished
}

// 2nd DFS
void invDfs(string node) {
    visited.insert(node);
    scc.push_back(node);
    for (auto &neighbor : inv[node]) {
        if (visited.find(neighbor) == visited.end()) {
            invDfs(neighbor);
        }
    }
}

//Print the current SCC
void printNames() {
    for (int i = 0; i < scc.size(); i++) {
        if (i > 0) cout << ", ";
        cout << scc[i];
    }
    cout << endl;
}

int main() {
    int n, m;
    string a, b;
    int count = 0;
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        count++;
        // Clear all global structures
        adj.clear();
        inv.clear();
        visited.clear();
        allNodes.clear();
        scc.clear();
        while (!nodes.empty()) nodes.pop();
        cout << "Calling circles for data set " << count << ":" << endl;
        // Read edges and build both graphs
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            adj[a].push_back(b);      // Original graph
            inv[b].push_back(a);      // Transposed graph
            allNodes.insert(a);
            allNodes.insert(b);
        }
        // 1st pass: DFS on original graph to fill the stack
        visited.clear();
        for (auto &node : allNodes) {
            if (visited.find(node) == visited.end()) {
                dfs(node);
            }
        }
        // 2nd pass: DFS on transposed graph in reverse finish order
        visited.clear();
        while (!nodes.empty()) {
            string node = nodes.top(); nodes.pop();
            if (visited.find(node) == visited.end()) {
                scc.clear();
                invDfs(node);
                printNames(); // Print one SCC
            }
        }
    }
    return 0;
}