# Algorithms Lab

This repository contains implementations of fundamental algorithms covered in the Algorithms Lab course. Each lab focuses on different algorithmic paradigms and techniques, with practical implementations in C++.

## Repository Structure

The repository is organized into five labs, each exploring different categories of algorithms:

1. [**Lab 01: Searching Algorithms**](./Lab%2001/README.md)
   - Linear Search
   - Binary Search

2. [**Lab 02: Sorting Algorithms**](./Lab%2002/README.md)
   - Bubble Sort
   - Insertion Sort
   - Selection Sort

3. [**Lab 03: Divide and Conquer Algorithms**](./Lab%2003/README.md)
   - Merge Sort
   - Quick Sort

4. [**Lab 04: Greedy Algorithms**](./Lab%2004/README.md)
   - Activity Selection
   - Fractional Knapsack

5. [**Lab 05: Minimum Spanning Tree Algorithms**](./Lab%2005/README.md)
   - Kruskal's Algorithm
   - Prim's Algorithm

## How to Compile and Run

You can compile and run any program in this repository using the following commands:

### Method 1: Manual Compilation
```bash
# Navigate to the lab directory
cd "Lab 01"

# Compile a specific program
g++ -g Linear-Search.cpp -o Linear-Search

# Run the program
./Linear-Search
```

### Method 2: Using VS Code Tasks
1. Open the file you want to run in VS Code
2. Press `Ctrl+Shift+B` to build the program
3. Press `F5` to run with debugging, or use the Terminal → Run Task menu and select "run"

## Algorithm Complexity Summary

| Algorithm | Time Complexity (Best) | Time Complexity (Average) | Time Complexity (Worst) | Space Complexity |
|-----------|------------------------|---------------------------|-------------------------|------------------|
| Linear Search | O(1) | O(n) | O(n) | O(1) |
| Binary Search | O(1) | O(log n) | O(log n) | O(1) |
| Bubble Sort | O(n) | O(n²) | O(n²) | O(1) |
| Insertion Sort | O(n) | O(n²) | O(n²) | O(1) |
| Selection Sort | O(n²) | O(n²) | O(n²) | O(1) |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | O(log n) |
| Activity Selection | O(n log n) | O(n log n) | O(n log n) | O(1) |
| Fractional Knapsack | O(n log n) | O(n log n) | O(n log n) | O(1) |
| Kruskal's Algorithm | O(E log E) | O(E log E) | O(E log E) | O(V + E) |
| Prim's Algorithm | O(E log V) | O(E log V) | O(E log V) | O(V) |

## Algorithm Comparison and Selection Guide

### Searching Algorithms
- **Linear Search**: Use for unsorted arrays or small datasets
- **Binary Search**: Use for sorted arrays, especially large ones

### Sorting Algorithms
- **Bubble Sort**: Simple but inefficient, useful for educational purposes
- **Insertion Sort**: Efficient for small or nearly sorted arrays
- **Selection Sort**: Performs better than bubble sort when memory writes are expensive

### Divide and Conquer Algorithms
- **Merge Sort**: Stable sort with guaranteed O(n log n) performance, good for linked lists
- **Quick Sort**: Usually faster in practice for arrays, but has worse worst-case time complexity

### Greedy Algorithms
- **Activity Selection**: Optimal for scheduling non-overlapping activities
- **Fractional Knapsack**: Optimal for maximizing value when items can be divided

### Minimum Spanning Tree Algorithms
- **Kruskal's Algorithm**: Efficient for sparse graphs
- **Prim's Algorithm**: Efficient for dense graphs

## Further Resources

For more information on algorithms and data structures, check out these resources:

- [Introduction to Algorithms by Cormen, Leiserson, Rivest, and Stein](https://mitpress.mit.edu/books/introduction-algorithms-third-edition)
- [Algorithms by Robert Sedgewick and Kevin Wayne](https://algs4.cs.princeton.edu/home/)
- [GeeksforGeeks Algorithm Tutorials](https://www.geeksforgeeks.org/fundamentals-of-algorithms/)
- [Visualgo - Algorithm Visualization](https://visualgo.net/en)

## Contributors

- [Your Name]

## License

This project is licensed under the MIT License - see the LICENSE file for details.