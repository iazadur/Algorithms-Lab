
#include <iostream>
using namespace std;
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1; 
        }
    }
    return -1; 
}
int main() {
    int arr[] = {5, 12, 18, 21, 29, 33, 45, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    cout << "Enter the number to search for: ";
    cin >> target;

    int result = binarySearch(arr, size, target);

    if (result != -1) {
        cout << "Number found at index: " << result << endl;
    } else {
        cout << "Number not found in the array." << endl;
    }

    return 0;
}