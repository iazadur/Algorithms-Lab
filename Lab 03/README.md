# Lab 03: Divide and Conquer Algorithms

This lab explores advanced sorting algorithms that utilize the divide and conquer paradigm.

## 1. Merge Sort

### Description
Merge Sort is an efficient, stable, comparison-based, divide and conquer algorithm. It divides the input array into two halves, recursively sorts them, and then merges the sorted halves to produce a sorted output.

### Algorithm
1. Divide the unsorted array into n subarrays, each containing one element (a single element is considered sorted)
2. Repeatedly merge subarrays to produce new sorted subarrays until there is only one subarray remaining
3. Merging process:
   - Create temporary arrays for left and right subarrays
   - Compare elements from both subarrays and place the smaller one in the result array
   - Copy any remaining elements from either subarray to the result array

### Time Complexity
- **Best Case**: O(n log n)
- **Average Case**: O(n log n)
- **Worst Case**: O(n log n)

### Space Complexity
- O(n) - Requires additional space for the temporary arrays during merging

### Implementation Details
The implementation in `Merge-Sort.cpp` includes:
- Recursive merge sort function to divide the array
- Merge function to combine sorted subarrays
- Analysis of performance with different array sizes
- Visualization of the merging process

### Usage Example
```cpp
int arr[] = {38, 27, 43, 3, 9, 82, 10};
int n = sizeof(arr) / sizeof(arr[0]);
mergeSort(arr, 0, n-1);
// After sorting: {3, 9, 10, 27, 38, 43, 82}
```

### Advantages
- Stable sorting algorithm (preserves the relative order of equal elements)
- Guaranteed O(n log n) time complexity regardless of input distribution
- Well-suited for sorting linked lists with O(1) extra space
- External sorting algorithm (can handle large datasets that don't fit in memory)

### Disadvantages
- Requires O(n) extra space for the temporary arrays
- Not an in-place sorting algorithm in its standard implementation
- Slower for small arrays compared to insertion sort

## 2. Quick Sort

### Description
Quick Sort is a highly efficient, in-place, divide and conquer sorting algorithm. It works by selecting a 'pivot' element from the array and partitioning the other elements into two sub-arrays according to whether they are less than or greater than the pivot.

### Algorithm
1. Choose a pivot element from the array
2. Partition the array:
   - Elements less than the pivot go to the left
   - Elements greater than the pivot go to the right
3. Recursively apply the above steps to the sub-arrays
4. The base case occurs when a sub-array has 0 or 1 elements (already sorted)

### Pivot Selection Strategies
- First or last element (simplest but can lead to worst-case performance for sorted arrays)
- Random element (reduces the chance of worst-case performance)
- Median-of-three (first, middle, last - good practical choice)

### Time Complexity
- **Best Case**: O(n log n) - When the pivot divides the array into nearly equal halves
- **Average Case**: O(n log n)
- **Worst Case**: O(n²) - When the pivot is always the smallest or largest element (e.g., in already sorted arrays)

### Space Complexity
- **Average**: O(log n) - Due to the recursion stack
- **Worst**: O(n) - When recursion depth becomes n

### Implementation Details
The implementation in `Quick-Sort.cpp` includes:
- Standard quicksort implementation with the last element as pivot
- Alternative implementations with different pivot selection strategies
- Techniques to handle worst-case scenarios
- Tail recursion optimization to reduce stack space

### Usage Example
```cpp
int arr[] = {50, 23, 9, 18, 61, 32};
int n = sizeof(arr) / sizeof(arr[0]);
quickSort(arr, 0, n-1);
// After sorting: {9, 18, 23, 32, 50, 61}
```

### Advantages
- In-place sorting (requires little additional space)
- Cache-friendly (good locality of reference)
- Very fast for average cases
- Efficient for large arrays
- Low overhead compared to merge sort

### Disadvantages
- Unstable (doesn't preserve the relative order of equal elements)
- Worst-case time complexity of O(n²)
- Performance depends on pivot selection
- Not suitable for linked lists (requires random access for efficient partitioning)

## Comparison of Divide and Conquer Sorting Algorithms

| Feature | Merge Sort | Quick Sort |
|---------|------------|------------|
| Time Complexity (Best) | O(n log n) | O(n log n) |
| Time Complexity (Average) | O(n log n) | O(n log n) |
| Time Complexity (Worst) | O(n log n) | O(n²) |
| Space Complexity | O(n) | O(log n) on average |
| Stability | Stable | Not stable |
| In-Place | No | Yes |
| Adaptive | No | No (standard version) |
| Cache Efficiency | Moderate | High |
| External Sorting | Yes | No |
| Preferred Use Cases | When stability matters, external sorting, linked lists | When average performance and low memory overhead are important |

### Hybrid Approaches
For practical implementations, many modern sorting libraries use hybrid approaches:
- Quicksort for the main array
- Switch to insertion sort for small subarrays (e.g., < 10-20 elements)
- Use median-of-three or more advanced pivot selection strategies
- Implement techniques like introsort (switches to heapsort when recursion depth exceeds a threshold)