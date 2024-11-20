#include <iostream>
#include <queue>  // Include the queue header
using namespace std;

int main() {
    // Create a queue of integers
    queue<int> q;

    // Enqueue (add elements to the back of the queue)
    q.push(10);  // Add 10 to the queue
    q.push(20);  // Add 20 to the queue
    q.push(30);  // Add 30 to the queue
    q.push(40);  // Add 40 to the queue

    // Display the front and back elements
    cout << "Front element: " << q.front() << endl; // Should print 10
    cout << "Back element: " << q.back() << endl;  // Should print 40

    // Dequeue (remove elements from the front of the queue)
    cout << "Dequeuing elements:" << endl;
    while (!q.empty()) {
        cout << q.front() << " ";  // Print the front element
        q.pop();  // Remove the front element
    }

    cout << endl;
    return 0;
}
