#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() {
        head = nullptr;
    }

void insertAtStart(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        newNode->next = head; 
        head->prev = newNode;  
        head = newNode;       
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;       
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;

    list.insertAtStart(10); 
    list.insertAtStart(20); 
    list.insertAtStart(30); 

    cout << "Doubly Linked List after insertions at the start: ";
    list.display();

    return 0;
}
