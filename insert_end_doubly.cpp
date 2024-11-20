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

    // Function to insert a node at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);  // Create a new node

        // If the list is empty, make the new node the head
        if (head == nullptr) {
            head = newNode;
            return;
        }

        // Otherwise, traverse to the last node
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        // Update the links for the new node
        temp->next = newNode;  // Set the last node's next to the new node
        newNode->prev = temp;  // Set the new node's prev to the last node
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

// Main function to test insertion at the end
int main() {
    DoublyLinkedList list;

    // Inserting nodes at the end
    list.insertAtEnd(10);  // Insert 10 at the end
    list.insertAtEnd(20);  // Insert 20 at the end
    list.insertAtEnd(30);  // Insert 30 at the end
    list.insertAtEnd(40);  // Insert 40 at the end

    // Display the doubly linked list
    cout << "Doubly Linked List after insertions at the end: ";
    list.display();

    return 0;
}
