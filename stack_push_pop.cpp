#include <iostream>
#include <stack>
using namespace std;

int main() {
    // Create a stack of integers
    stack<int> s;

    // Pushing elements onto the stack
    s.push(10);  // Push 10 onto the stack
    s.push(20);  // Push 20 onto the stack
    s.push(30);  // Push 30 onto the stack
    s.push(40);  // Push 40 onto the stack

    // Display the top element of the stack
    cout << "Top element of stack: " << s.top() << endl; // It will show 40

    // Popping elements from the stack
    cout << "Popping elements from the stack:" << endl;
    while (!s.empty()) {
        cout << s.top() << " ";  // Print the top element
        s.pop();  // Remove the top element
    }

    cout << endl;

    return 0;
}
