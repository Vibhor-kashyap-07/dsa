#include <iostream>
using namespace std;

void insertAtPosition(int arr[], int &n, int value, int position) {
    if (position < 1 || position > n + 1) {
        cout << "Invalid position!" << endl;
        return;
    }

    for (int i = n; i >= position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position - 1] = value;
    n++;
}

void deleteAtPosition(int arr[], int &n, int position) {
    if (position < 1 || position > n) {
        cout << "Invalid position!" << endl;
        return;
    }

    for (int i = position - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    n--;
}

void displayArray(int arr[], int n) {
    if (n == 0) {
        cout << "Array is empty!" << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[100]; 
    int n = 0; 

    insertAtPosition(arr, n, 10, 1);  
    insertAtPosition(arr, n, 20, 2);  
    insertAtPosition(arr, n, 15, 2); 

    cout << "Array after insertions: ";
    displayArray(arr, n);

    deleteAtPosition(arr, n, 2);  

    cout << "Array after deletion: ";
    displayArray(arr, n);

    return 0;
}
