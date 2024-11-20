#include <iostream>
using namespace std;

// Function to perform bubble sort
void bubbleSort(int arr[], int n) {
    // Traverse through all elements in the array
    for (int i = 0; i < n-1; i++) {
        // Flag to check if any swapping occurred
        bool swapped = false;

        // Last i elements are already sorted
        for (int j = 0; j < n-i-1; j++) {
            // Swap if the element found is greater than the next element
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }

        // If no two elements were swapped by inner loop, then the array is sorted
        if (!swapped) {
            break;
        }
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};  // Example array
    int n = sizeof(arr)/sizeof(arr[0]);  // Calculate the number of elements in the array

    cout << "Original array: ";
    printArray(arr, n);

    bubbleSort(arr, n);  // Call bubble sort

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
