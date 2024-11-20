#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void insertAtPosition(int value, int position) {
        if (position < 1) {
            cout << "Position must be >= 1" << endl;
            return;
        }

        Node* newNode = new Node(value);

        if (position == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 1; temp != nullptr && i < position - 1; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Position is out of range." << endl;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
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
    LinkedList list;

    list.insertAtPosition(10, 1); 
    list.insertAtPosition(20, 2); 
    list.insertAtPosition(15, 2); 
    list.insertAtPosition(25, 4); 

   
    cout << "Linked List after insertions at specific positions: ";
    list.display();

    return 0;
}
