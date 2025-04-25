// 2. Prim's Algorithm
// Write a C/C++ program to find the Minimum Spanning Tree (MST) of a graph using Prim’s
// Algorithm.
// Test your program with the following weighted graph:
// Vertices: P, Q, R, S, T
// Edges and Weights:
// • (P - Q) : 2
// • (P - R) : 3
// • (Q - R) : 1
// • (Q - S) : 4
// • (R - S) : 2
// • (R - T) : 5
// • (S - T) : 3

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <limits.h>
using namespace std;
#define NUM_VERTICES 5 // Number of vertices in the graph
#define INF INT_MAX
typedef pair<int, int> iPair; // Pair of (weight, vertex)
class Graph {
    int V; // Number of vertices
    vector<pair<int, iPair>> edges; // Edges in the graph
public:
    Graph(int V) {
        this->V = V;
    }
    void addEdge(int u, int v, int w) {
        edges.push_back(make_pair(w, make_pair(u, v)));
    }
    void primMST();
};
void Graph::primMST() {
    vector<iPair> result; // Store the resultant MST
    vector<int> key(V, INF); // Initialize all
    vector<bool> inMST(V, false); // Track vertices included in MST
    vector<int> parent(V, -1); // Store the parent of each vertex
    key[0] = 0; // Start from the first vertex

    for (int i = 0; i < V - 1; i++) {
        int minKey = INF, minIndex;
        for (int v = 0; v < V; v++) {
            if (!inMST[v] && key[v] < minKey) {
                minKey = key[v];
                minIndex = v;
            }
        }
        inMST[minIndex] = true; // Include the vertex in MST
        for (auto edge : edges) {
            int u = edge.second.first;
            int v = edge.second.second;
            int weight = edge.first;
            if (u == minIndex && !inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = minIndex;
            }
        }
    }
    cout << "Edges in the Minimum Spanning Tree:\n";
    for (int i = 1; i < V; i++) {
        cout << "(" << parent[i] << " - " << i << ") : " << key[i] << endl;
    }
}
int main() {
    Graph g(NUM_VERTICES);
    g.addEdge(0, 1, 2); // P - Q
    g.addEdge(0, 2, 3); // P - R
    g.addEdge(1, 2, 1); // Q - R
    g.addEdge(1, 3, 4); // Q - S
    g.addEdge(2, 3, 2); // R - S
    g.addEdge(2, 4, 5); // R - T
    g.addEdge(3, 4, 3); // S - T

    g.primMST();
    return 0;
}
