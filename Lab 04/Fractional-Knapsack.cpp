// 2. Fractional Knapsack
// Write a C/C++ program to solve the Fractional Knapsack Problem using a Greedy Algorithm.
// Given n items with specific weights and values, determine the maximum value that can be
// accommodated in a knapsack of a given capacity.
// Test your program with the following data:
// Knapsack Capacity: 50
// Items:
// Item Weight Value
// I1 10 60
// I2 20 100
// I3 30 120

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Item {
    int weight;
    int value;
    double ratio; // value/weight
};
bool compare(Item a, Item b) {
    return a.ratio > b.ratio; // Sort in descending order of value/weight ratio
}
double fractionalKnapsack(int capacity, vector<Item>& items) {
    sort(items.begin(), items.end(), compare);
    double totalValue = 0.0;
    for (auto& item : items) {
        if (capacity <= 0) break; // No more capacity in the knapsack
        if (item.weight <= capacity) {
            totalValue += item.value; // Take the whole item
            capacity -= item.weight;
        } else {
            totalValue += item.ratio * capacity; // Take the fraction of the item
            capacity = 0; // Knapsack is full
        }
    }
    return totalValue;
}

int main() {
    int capacity = 50;
    vector<Item> items = {
        {10, 60, 0.0},
        {20, 100, 0.0},
        {30, 120, 0.0}
    };
    for (auto& item : items) {
        item.ratio = (double)item.value / item.weight; // Calculate value/weight ratio
    }
    double maxValue = fractionalKnapsack(capacity, items);
    cout << "Maximum value in the knapsack: " << maxValue << endl;
    return 0;
}
