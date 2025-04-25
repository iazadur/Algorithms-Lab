// Write a C/C++ program to find the Minimum Spanning Tree (MST) of a graph using Kruskal’s
// Algorithm.
// Test your program with the following weighted graph:
// Vertices: A, B, C, D, E
// Edges and Weights:
// • (A - B) : 4
// • (A - C) : 1
// • (B - C) : 2
// • (B - D) : 5
// • (C - D) : 3
// • (C - E) : 6
// • (D - E) : 7

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Edge {
    int src, dest, weight;
};
struct Graph {
    int V, E;
    vector<Edge> edges;
};
int findParent(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return findParent(parent, parent[i]);
}
void unionSets(int parent[], int x, int y) {
    int xset = findParent(parent, x);
    int yset = findParent(parent, y);
    if (xset != yset)
        parent[xset] = yset;
}
bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}
void kruskalMST(Graph& graph) {
    vector<Edge> result;
    int parent[graph.V];
    fill(parent, parent + graph.V, -1);
    sort(graph.edges.begin(), graph.edges.end(), compare);
    for (auto edge : graph.edges) {
        int x = findParent(parent, edge.src);
        int y = findParent(parent, edge.dest);
        if (x != y) {
            result.push_back(edge);
            unionSets(parent, x, y);
        }
    }
    cout << "Edges in the Minimum Spanning Tree:\n";
    for (auto edge : result) {
        cout << "(" << edge.src << " - " << edge.dest << ") : " << edge.weight << endl;
    }
}
int main() {
    Graph graph;
    graph.V = 5; // Number of vertices
    graph.E = 7; // Number of edges
    graph.edges = {
        {0, 1, 4}, // A - B
        {0, 2, 1}, // A - C
        {1, 2, 2}, // B - C
        {1, 3, 5}, // B - D
        {2, 3, 3}, // C - D
        {2, 4, 6}, // C - E
        {3, 4, 7}  // D - E
    };
    kruskalMST(graph);
    return 0;
}
