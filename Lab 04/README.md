# Lab 04: Greedy Algorithms

This lab explores greedy algorithms, which build up a solution piece by piece, always choosing the next piece that offers the most immediate benefit.

## 1. Activity Selection

### Description
The Activity Selection problem involves selecting the maximum number of non-overlapping activities that can be performed by a single person, given the start and finish times of each activity. The person can only work on a single activity at a time.

### Problem Statement
Given n activities with their start times (s₁, s₂, ..., sₙ) and finish times (f₁, f₂, ..., fₙ), select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.

### Greedy Approach
The greedy choice is to always pick the activity with the earliest finish time among the remaining activities that start after the finish time of the last selected activity.

### Algorithm
1. Sort all activities according to their finishing time
2. Initialize the result set with the first activity (earliest finishing)
3. For each remaining activity:
   - If the start time of this activity is greater than or equal to the finish time of the previously selected activity, add this activity to the result and update the previously selected activity

### Time Complexity
- O(n log n) - Dominated by the sorting of activities by finish time
- If the activities are already sorted by finish time: O(n)

### Space Complexity
- O(1) - If we only need to output the count of activities
- O(n) - If we need to store the selected activities

### Implementation Details
The implementation in `Activity-Selection.cpp` includes:
- Function to select maximum non-overlapping activities
- Input handling for activities with their start and finish times
- Output of selected activities and their total count
- Visualization of the activity timeline

### Usage Example
```cpp
// Activities with (start time, finish time)
Activity activities[] = {
    {1, 3}, // A1
    {2, 5}, // A2
    {3, 9}, // A3
    {6, 8}, // A4
    {8, 11} // A5
};
int n = sizeof(activities) / sizeof(activities[0]);
printMaxActivities(activities, n);
// Output: A1, A4, A5 (3 activities)
```

### Applications
- Scheduling problems (class scheduling, meeting room allocation)
- Resource allocation in operating systems
- Event management and planning
- Telecommunications (channel assignment)

## 2. Fractional Knapsack

### Description
The Fractional Knapsack problem is a variation of the knapsack problem where fractions of items can be taken. Given a set of items, each with a weight and a value, determine the number of each item to include in a collection so that the total weight is less than or equal to a given limit and the total value is as large as possible.

### Problem Statement
Given n items, each with a weight wᵢ and a value vᵢ, and a knapsack of capacity W, find the maximum value that can be obtained by taking fractions of the items.

### Greedy Approach
The greedy choice is to always pick the item with the highest value-to-weight ratio and take as much of it as possible.

### Algorithm
1. Calculate the value-to-weight ratio for each item
2. Sort the items by their value-to-weight ratios in descending order
3. Initialize result value to 0
4. For each item in the sorted order:
   - If adding the whole item doesn't exceed the capacity, add it completely and update the capacity
   - Otherwise, add a fraction of the item to fill the remaining capacity and break

### Time Complexity
- O(n log n) - Dominated by the sorting of items by value-to-weight ratio

### Space Complexity
- O(1) - If we only need to output the maximum value
- O(n) - If we need to store the fractions of each item taken

### Implementation Details
The implementation in `Fractional-Knapsack.cpp` includes:
- Item structure with weight, value, and value-to-weight ratio
- Function to solve the fractional knapsack problem
- Detailed output showing the fractions of each item taken
- Error handling for edge cases

### Usage Example
```cpp
// Items with (weight, value)
Item items[] = {
    {10, 60}, // I1
    {20, 100}, // I2
    {30, 120} // I3
};
int n = sizeof(items) / sizeof(items[0]);
int capacity = 50;
float maxValue = fractionalKnapsack(items, n, capacity);
// Output: Maximum value = 240
// (Take all of I1, all of I2, and 2/3 of I3)
```

### Applications
- Resource allocation problems
- Budget allocation in finance
- Loading cargo ships or trucks
- Production planning and inventory management

## Comparison with Dynamic Programming

While greedy algorithms make locally optimal choices at each step, they may not always lead to a globally optimal solution. The standard (0/1) Knapsack problem, unlike the Fractional Knapsack, cannot be solved using a greedy approach and requires dynamic programming.

### When to Use Greedy Algorithms

Greedy algorithms work well when:
1. The problem exhibits the "greedy choice property" (locally optimal choices lead to a globally optimal solution)
2. The problem has "optimal substructure" (optimal solutions to subproblems can be combined to form an optimal solution to the original problem)

The Activity Selection and Fractional Knapsack problems satisfy these properties, which is why greedy algorithms work for them.