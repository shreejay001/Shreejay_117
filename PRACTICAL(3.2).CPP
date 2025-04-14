#include <iostream>
using namespace std;

// Recursive function to calculate sum
int recursiveSum(int arr[], int size) {
    if (size == 0)
        return 0; // base case
    else
        return arr[size - 1] + recursiveSum(arr, size - 1); // recursive call
}

// Iterative function to calculate sum
int iterativeSum(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int size;

    // Get array size from user
    cout << "Enter the number of elements in the array: ";
    cin >> size;

    if (size <= 0) {
        cout << "Array size must be greater than 0.\n";
        return 0;
    }

    // Dynamically allocate memory for the array
    int* arr = new int[size];

    // Input array elements
    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    // Calculate sums
    int recSum = recursiveSum(arr, size);
    int iterSum = iterativeSum(arr, size);

    // Output results
    cout << "\nSum calculated using recursion: " << recSum << endl;
    cout << "Sum calculated using iteration: " << iterSum << endl;
