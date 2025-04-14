#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

//bipartite using BFS
bool isBipartite(map<int, vector<int>>& adj, int n) {
    vector<int> color(n, -1);  // -1 means uncolored
    queue<int> q;

    // Check all connected components
    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            color[i] = 0;  // Start with color 0
            q.push(i);
            while (!q.empty()) {
                int u = q.front(); q.pop();

                for (int v : adj[u]) {
                    if (color[v] == -1) {
                        color[v] = 1 - color[u];  // Alternate color
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        return false;  // Conflict found
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    int n, l;
    while (true) {
        cin >> n;
        if (n == 0) break;
        cin >> l;
        map<int, vector<int>> adj;
        for (int i = 0; i < l; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);  // Undirected graph
        }
        if (isBipartite(adj, n))
            cout << "BICOLORABLE." << endl;
        else
            cout << "NOT BICOLORABLE." << endl;
    }
    return 0;
}
