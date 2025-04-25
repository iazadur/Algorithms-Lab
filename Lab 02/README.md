# Lab 02: Sorting Algorithms

This lab focuses on implementing and analyzing elementary sorting algorithms.

## 1. Bubble Sort

### Description
Bubble Sort is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. The pass through the list is repeated until no swaps are needed, indicating the list is sorted.

### Algorithm
1. Iterate through the array from index 0 to n-1
2. For each iteration, compare adjacent elements (arr[j] and arr[j+1])
3. If arr[j] > arr[j+1], swap them
4. Repeat steps 1-3 until no more swaps are performed in a complete pass

### Time Complexity
- **Best Case**: O(n) - When the array is already sorted (with optimization)
- **Average Case**: O(n²)
- **Worst Case**: O(n²) - When the array is sorted in reverse order

### Space Complexity
- O(1) - Sorts in-place, requiring only a constant amount of extra space

### Implementation Details
The implementation in `Bubble-Sort.cpp` includes:
- Standard bubble sort implementation
- Optimized bubble sort that stops early if no swaps are made in a pass
- Test cases with arrays of different sizes and patterns

### Usage Example
```cpp
int arr[] = {34, 12, 25, 9, 76, 30};
int n = sizeof(arr) / sizeof(arr[0]);
bubbleSort(arr, n);
// After sorting: {9, 12, 25, 30, 34, 76}
```

### Advantages
- Simple implementation
- Easy to understand
- Minimal space requirements
- Stable sorting algorithm (maintains relative order of equal elements)

### Disadvantages
- Very inefficient for large arrays
- Performs poorly compared to more advanced algorithms
- Quadratic time complexity makes it unsuitable for real-world applications with large datasets

## 2. Insertion Sort

### Description
Insertion Sort builds the final sorted array one item at a time. It takes an element from the unsorted part and places it in its correct position in the sorted part of the array.

### Algorithm
1. Start from the second element (index 1) to the last element
2. For each element, compare it with all elements in the sorted portion (elements before current element)
3. Shift all elements greater than the current element one position to the right
4. Insert the current element in the correct position
5. Repeat for all elements in the array

### Time Complexity
- **Best Case**: O(n) - When the array is already sorted
- **Average Case**: O(n²)
- **Worst Case**: O(n²) - When the array is sorted in reverse order

### Space Complexity
- O(1) - In-place sorting algorithm

### Implementation Details
The implementation in `Insertion-Sort.cpp` includes:
- Standard insertion sort implementation
- Optimized approach with binary search to find insertion point
- Performance comparison with other sorting algorithms

### Usage Example
```cpp
int arr[] = {22, 11, 55, 9, 3, 40, 60};
int n = sizeof(arr) / sizeof(arr[0]);
insertionSort(arr, n);
// After sorting: {3, 9, 11, 22, 40, 55, 60}
```

### Advantages
- Efficient for small data sets
- Stable sorting algorithm
- Adaptive (efficient for partially sorted arrays)
- In-place algorithm with low overhead
- Can sort the array as it receives the data (online algorithm)

### Disadvantages
- Inefficient for large data sets compared to advanced algorithms like merge sort
- Requires many element shifts for insertions

## 3. Selection Sort

### Description
Selection Sort works by repeatedly finding the minimum element from the unsorted part of the array and putting it at the beginning of the unsorted part.

### Algorithm
1. Divide the array into two parts: sorted (initially empty) and unsorted (initially the entire array)
2. Find the minimum element in the unsorted part
3. Swap it with the first element of the unsorted part
4. Expand the sorted part to include the newly placed element
5. Repeat until the unsorted part is empty

### Time Complexity
- **Best Case**: O(n²) - No early termination optimizations in standard implementation
- **Average Case**: O(n²)
- **Worst Case**: O(n²)

### Space Complexity
- O(1) - In-place sorting algorithm

### Implementation Details
The implementation in `Selection-Sort.cpp` includes:
- Standard selection sort implementation
- Performance measurement across different input sizes
- Comparisons with other sorting algorithms

### Usage Example
```cpp
int arr[] = {29, 10, 14, 37, 13, 88, 23};
int n = sizeof(arr) / sizeof(arr[0]);
selectionSort(arr, n);
// After sorting: {10, 13, 14, 23, 29, 37, 88}
```

### Advantages
- Simple implementation
- Performs well on small arrays
- Minimal memory usage (in-place algorithm)
- Makes the minimum possible number of swaps (n-1 in the worst case)

### Disadvantages
- O(n²) time complexity makes it inefficient for large arrays
- Always performs O(n²) comparisons even if the array is already sorted
- Not stable in the standard implementation (relative order of equal elements may change)

## Comparison of Sorting Algorithms

| Algorithm | Best Case | Average Case | Worst Case | Space | Stable | Adaptive |
|-----------|-----------|--------------|------------|-------|--------|----------|
| Bubble Sort | O(n) | O(n²) | O(n²) | O(1) | Yes | Yes |
| Insertion Sort | O(n) | O(n²) | O(n²) | O(1) | Yes | Yes |
| Selection Sort | O(n²) | O(n²) | O(n²) | O(1) | No | No |

### When to Use Each Algorithm

- **Bubble Sort**: Rarely used in practice due to inefficiency, but useful for educational purposes or when simplicity is more important than efficiency.
- **Insertion Sort**: Good for small arrays or nearly sorted arrays. Often used as part of more complex algorithms (like in the final step of quicksort for small partitions).
- **Selection Sort**: Generally outperformed by insertion sort in practice, but has the advantage of making fewer writes to memory (useful when write operations are costly).