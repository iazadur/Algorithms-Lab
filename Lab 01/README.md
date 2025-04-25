# Lab 01: Searching Algorithms

This lab covers the implementation of fundamental searching algorithms.

## 1. Linear Search

### Description
Linear search (also called sequential search) is a simple searching algorithm that finds the position of a target value within a list by checking each element sequentially until a match is found or the entire list has been searched.

### Algorithm
1. Start from the leftmost element of the array and compare each element with the target value
2. If the element matches the target value, return its position
3. If the element does not match, continue to the next element
4. If no match is found after checking all elements, return -1 (not found)

### Time Complexity
- **Best Case**: O(1) - When the target is at the first position
- **Average Case**: O(n/2) - When the target is in the middle (simplified to O(n))
- **Worst Case**: O(n) - When the target is at the last position or not present

### Space Complexity
- O(1) - Only requires a constant amount of space regardless of input size

### Implementation Details
The implementation in `Linear-Search.cpp` includes:
- A function to perform linear search on an array of integers
- Test cases with various array sizes and target values
- Output showing whether the target was found and its position

### Usage Example
```cpp
int arr[] = {5, 2, 8, 12, 3};
int n = sizeof(arr) / sizeof(arr[0]);
int target = 8;
int result = linearSearch(arr, n, target);
// Result would be 2 (index of value 8)
```

### Advantages
- Simple to implement
- Works on unsorted arrays
- No pre-processing required
- Effective for small arrays

### Disadvantages
- Inefficient for large arrays
- Much slower than binary search for sorted arrays

## 2. Binary Search

### Description
Binary search is a divide and conquer algorithm that finds the position of a target value within a sorted array. It compares the target value to the middle element of the array; if they are equal, the position is returned. If the target is less than the middle element, the search continues in the lower half of the array. If the target is greater than the middle element, the search continues in the upper half of the array.

### Algorithm
1. Sort the array if it's not already sorted
2. Set left pointer to the start and right pointer to the end of the array
3. Find the middle element of the current range
4. If the middle element is equal to the target, return its position
5. If the target is less than the middle element, search the left half
6. If the target is greater than the middle element, search the right half
7. Repeat steps 3-6 until the target is found or the search range is empty
8. If the target is not found, return -1

### Time Complexity
- **Best Case**: O(1) - When the target is at the middle position
- **Average Case**: O(log n)
- **Worst Case**: O(log n)

### Space Complexity
- **Iterative Implementation**: O(1) - No additional space required
- **Recursive Implementation**: O(log n) - Stack space for recursion calls

### Implementation Details
The implementation in `Binary-Search.cpp` includes:
- Both recursive and iterative implementations of binary search
- Test cases with sorted arrays of various sizes
- Comparison of execution time between linear and binary search

### Usage Example
```cpp
int arr[] = {2, 3, 5, 8, 12};  // Must be sorted
int n = sizeof(arr) / sizeof(arr[0]);
int target = 8;
int result = binarySearch(arr, 0, n-1, target);
// Result would be 3 (index of value 8)
```

### Advantages
- Very efficient for large sorted arrays
- Logarithmic time complexity makes it suitable for large datasets
- Predictable performance

### Disadvantages
- Only works on sorted arrays
- Sorting may add overhead if the array is not already sorted
- Not as efficient as linear search for very small arrays

## Comparison
| Feature | Linear Search | Binary Search |
|---------|--------------|---------------|
| Time Complexity | O(n) | O(log n) |
| Sorted Array Required | No | Yes |
| Implementation | Simple | Moderate |
| Best For | Small arrays, unsorted data | Large sorted arrays |