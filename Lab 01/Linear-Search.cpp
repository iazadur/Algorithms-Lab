#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; 
        }
    }
    return -1;
}


int main() {
    int arr[] = {12, 45, 23, 51, 19, 8, 37, 30};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    cout << "Enter the number to search for: ";
    cin >> target;

    int result = linearSearch(arr, size, target);

    if (result != -1) {
        cout << "Number found at index: " << result << endl;
    } else {
        cout << "Number not found in the array." << endl;
    }

    return 0;
}
