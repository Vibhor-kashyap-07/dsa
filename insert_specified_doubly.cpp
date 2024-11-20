#include <iostream>
using namespace std;

// Node structure for doubly linked list
struct Node {
    int data;
    Node* next;
    Node* prev;

    // Constructor to initialize a node
    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

// Doubly Linked List class
class DoublyLinkedList {
public:
    Node* head;

    // Constructor to initialize the list with no nodes (empty list)
    DoublyLinkedList() {
        head = nullptr;
    }

    // Function to insert a node at a specified position
    void insertAtPosition(int value, int position) {
        // If the position is invalid
        if (position < 1) {
            cout << "Invalid position!" << endl;
            return;
        }

        Node* newNode = new Node(value);  // Create a new node

        // If inserting at the beginning (position 1)
        if (position == 1) {
            newNode->next = head;   // New node's next will be the current head
            if (head != nullptr) {
                head->prev = newNode;  // If list is not empty, set current head's prev to the new node
            }
            head = newNode;          // Move head to the new node
            return;
        }

        // Traverse to the position where the node should be inserted
        Node* temp = head;
        int currentPos = 1;

        while (temp != nullptr && currentPos < position - 1) {
            temp = temp->next;
            currentPos++;
        }

        // If the position is greater than the number of nodes, we cannot insert
        if (temp == nullptr) {
            cout << "Position out of range!" << endl;
            return;
        }

        // Insert the new node after the temp node
        newNode->next = temp->next;   // New node's next will be temp's next node
        newNode->prev = temp;         // New node's prev will be temp
        if (temp->next != nullptr) {
            temp->next->prev = newNode;  // If new node is not inserted at the end, set its next node's prev
        }
        temp->next = newNode;         // Set temp's next to the new node
    }

    // Function to display the doubly linked list
    void display() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";  // Print the data of the node
            temp = temp->next;          // Move to the next node
        }
        cout << endl;
    }
};

// Main function to test insertion at a specified position
int main() {
    DoublyLinkedList list;

    // Inserting nodes at specified positions
    list.insertAtPosition(10, 1);  // Insert 10 at position 1 (start)
    list.insertAtPosition(20, 2);  // Insert 20 at position 2
    list.insertAtPosition(15, 2);  // Insert 15 at position 2
    list.insertAtPosition(25, 5);  // Insert 25 at position 5 (end)

    // Display the doubly linked list
    cout << "Doubly Linked List after insertions: ";
    list.display();

    return 0;
}
