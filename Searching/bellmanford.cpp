#include <iostream>  
#include <vector>  
  
using namespace std;  
  
struct Edge {  
    int source, destination, weight;  
};  

void bellmanFord(vector<Edge>& edges, int V, int source) {  
    vector<int> distance(V, INT_MAX);  
    distance[source] = 0;  
    for (int i = 1; i <= V - 1; ++i) {  
        for (const Edge& edge : edges) {  
            int u = edge.source;  
            int v = edge.destination;  
            int w = edge.weight;  
            if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {  
                distance[v] = distance[u] + w;  
            }  
        }  
    }
    for (const Edge& edge : edges) {  
        int u = edge.source;  
        int v = edge.destination;  
        int w = edge.weight;  
        if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {  
            cout << "Graph contains a negative weight cycle!" << endl;  
            return;  
        }  
    }  
    cout << "Shortest distances from source vertex " << source << ":" << endl;  
    for (int i = 0; i < V; ++i) {  
        cout << "Vertex " << i << ": " << distance[i] << endl;  
    }  
}  
  
int main() {  
    int V, E;  
    cout << "Enter the number of vertices and edges: ";  
    cin >> V >> E;  
    vector<Edge> edges;  
    cout << "Enter the edges in the format (source, destination, weight):" << endl;  
    for (int i = 0; i < E; ++i) {  
        int source, destination, weight;  
        cin >> source >> destination >> weight;  
        edges.push_back({source, destination, weight});  
    }  
    int source;  
    cout << "Enter the source vertex: ";  
    cin >> source;  
    bellmanFord(edges, V, source);  
    return 0;  
}  