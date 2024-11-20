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

    // Function to delete a node at a specified position
    void deleteAtPosition(int position) {
        // If the list is empty
        if (head == nullptr) {
            cout << "List is empty, nothing to delete!" << endl;
            return;
        }

        // If position is invalid (less than 1)
        if (position < 1) {
            cout << "Invalid position!" << endl;
            return;
        }

        Node* temp = head;
        int currentPos = 1;

        // Traverse to the node at the specified position
        while (temp != nullptr && currentPos < position) {
            temp = temp->next;
            currentPos++;
        }

        // If the position is greater than the number of nodes
        if (temp == nullptr) {
            cout << "Position out of range!" << endl;
            return;
        }

        // If the node to be deleted is the head node
        if (temp == head) {
            head = temp->next;  // Move head to the next node
            if (head != nullptr) {
                head->prev = nullptr;  // If the list is not empty, set the new head's prev to nullptr
            }
            delete temp;  // Delete the old head node
            return;
        }

        // If the node to be deleted is in the middle or the last node
        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;  // Set the next node's prev to the current node's prev
        }
        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;  // Set the previous node's next to the current node's next
        }

        delete temp;  // Delete the node
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

// Main function to test deletion at a specified position
int main() {
    DoublyLinkedList list;

    // Inserting nodes at the end
    list.insertAtEnd(10);  // Insert 10 at the end
    list.insertAtEnd(20);  // Insert 20 at the end
    list.insertAtEnd(30);  // Insert 30 at the end
    list.insertAtEnd(40);  // Insert 40 at the end

    // Display the doubly linked list
    cout << "Doubly Linked List before deletion at specified position: ";
    list.display();

    // Deleting the node at position 2
    list.deleteAtPosition(2);

    // Display the doubly linked list after deletion at position 2
    cout << "Doubly Linked List after deletion at position 2: ";
    list.display();

    // Deleting the node at position 1 (start)
    list.deleteAtPosition(1);

    // Display the doubly linked list after deletion at position 1
    cout << "Doubly Linked List after deletion at position 1: ";
    list.display();

    // Deleting the node at position 3 (invalid)
    list.deleteAtPosition(3);

    return 0;
}
