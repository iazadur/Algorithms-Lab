# Lab 05: Minimum Spanning Tree Algorithms

This lab explores algorithms for finding minimum spanning trees (MSTs) in weighted, connected graphs.

## What is a Minimum Spanning Tree (MST)?

A Minimum Spanning Tree (MST) is a subset of the edges of a connected, edge-weighted graph that connects all vertices together with the minimum possible total edge weight, without creating any cycles.

Properties of an MST:
- It spans all vertices (includes all vertices of the original graph)
- It is a tree (contains no cycles)
- It has exactly n-1 edges, where n is the number of vertices
- It minimizes the total weight of all the edges

## 1. Kruskal's Algorithm

### Description
Kruskal's Algorithm builds the MST by adding edges in ascending order of weight. It uses a disjoint-set data structure to efficiently check if adding an edge would create a cycle.

### Algorithm
1. Sort all edges in non-decreasing order of their weight
2. Initialize a disjoint-set (Union-Find) data structure with each vertex in its own set
3. For each edge in the sorted order:
   - Check if adding the current edge creates a cycle using the Union-Find data structure
   - If no cycle is formed, include the edge in the MST and merge the sets of the two endpoints
   - Otherwise, discard the edge
4. Continue until n-1 edges are included (or all edges are processed)

### Time Complexity
- O(E log E) or O(E log V) - Dominated by the sorting of edges
  - Where E is the number of edges and V is the number of vertices

### Space Complexity
- O(V + E) - For storing the graph and the disjoint-set data structure

### Implementation Details
The implementation in `Kruskals-Algorithm.cpp` includes:
- Graph representation using an edge list
- Disjoint-set data structure with path compression and union by rank
- MST construction using Kruskal's algorithm
- Output of the selected edges and the total weight of the MST
- Visualization of the resulting tree

### Usage Example
```cpp
// Graph with vertices A, B, C, D, E represented as 0, 1, 2, 3, 4
Edge edges[] = {
    {0, 1, 4}, // A-B with weight 4
    {0, 2, 1}, // A-C with weight 1
    {1, 2, 2}, // B-C with weight 2
    {1, 3, 5}, // B-D with weight 5
    {2, 3, 3}, // C-D with weight 3
    {2, 4, 6}, // C-E with weight 6
    {3, 4, 7}  // D-E with weight 7
};
int V = 5; // Number of vertices
int E = 7; // Number of edges
KruskalMST(edges, V, E);
// Output: MST includes edges A-C, B-C, C-D, C-E with total weight 12
```

### Applications
- Network design (e.g., telephone, electrical, hydraulic, TV cable, computer)
- Approximation algorithms for NP-hard problems like the Traveling Salesman Problem
- Cluster analysis
- Circuit design

## 2. Prim's Algorithm

### Description
Prim's Algorithm grows the MST one vertex at a time, starting from an arbitrary vertex. It adds the minimum weight edge that connects a vertex in the growing tree to a vertex outside the tree.

### Algorithm
1. Initialize a set to keep track of vertices included in the MST
2. Assign a key value to all vertices in the graph:
   - Initialize the key value of the starting vertex to 0
   - Initialize all other key values to infinity
3. While there are vertices not yet included in MST:
   - Pick the vertex u with the minimum key value that is not yet included in MST
   - Include u in the MST
   - Update key values of adjacent vertices of u:
     - For every adjacent vertex v, if the weight of edge u-v is less than the current key value of v, update the key value of v to the weight of u-v

### Time Complexity
- O(V²) - With a basic array implementation
- O(E log V) - With a binary heap or Fibonacci heap implementation
  - Where V is the number of vertices and E is the number of edges

### Space Complexity
- O(V) - For storing the key values, MST set, and parent array

### Implementation Details
The implementation in `Prims-Algorithm.cpp` includes:
- Graph representation using adjacency list/matrix
- Priority queue implementation for efficient vertex selection
- MST construction using Prim's algorithm
- Output of the selected edges and the total weight of the MST

### Usage Example
```cpp
// Graph with vertices P, Q, R, S, T represented as 0, 1, 2, 3, 4
// Adding edges with their weights
Graph g(5);
g.addEdge(0, 1, 2); // P-Q with weight 2
g.addEdge(0, 2, 3); // P-R with weight 3
g.addEdge(1, 2, 1); // Q-R with weight 1
g.addEdge(1, 3, 4); // Q-S with weight 4
g.addEdge(2, 3, 2); // R-S with weight 2
g.addEdge(2, 4, 5); // R-T with weight 5
g.addEdge(3, 4, 3); // S-T with weight 3
g.primMST();
// Output: MST includes edges Q-R, P-Q, R-S, S-T with total weight 8
```

### Applications
- Real-time MST applications where graph changes dynamically
- Network design with a predefined root node
- Image segmentation in computer vision
- Solving maze generation problems

## Comparison: Kruskal's vs. Prim's Algorithm

| Feature | Kruskal's Algorithm | Prim's Algorithm |
|---------|---------------------|------------------|
| Approach | Edge-based (sorts edges) | Vertex-based (grows a single tree) |
| Best for | Sparse graphs (E ≈ V) | Dense graphs (E ≈ V²) |
| Time Complexity | O(E log E) | O(E log V) with binary heap |
| Data Structures | Disjoint-Set (Union-Find) | Priority Queue/Heap |
| Starting Point | No specific starting vertex | Can start from any vertex |
| Implementation Complexity | Relatively simple | More complex with priority queue |
| Handles | Works well with disconnected graphs | Requires connected graphs |

### When to Use Each Algorithm
- **Kruskal's Algorithm**: Better for sparse graphs where E is much less than V². Also, when the edges are already sorted or you're implementing a distributed algorithm.
- **Prim's Algorithm**: Better for dense graphs where E is close to V². Also, when you need to start building the MST from a specific vertex.