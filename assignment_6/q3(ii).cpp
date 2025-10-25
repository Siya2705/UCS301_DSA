#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class CircularLinkedList {
    Node* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }

    int getSize() {
        if (head == nullptr)
            return 0;
        int count = 0;
        Node* temp = head;
        do {
            count++;
            temp = temp->next;
        } while (temp != head);
        return count;
    }
};

int main() {
    CircularLinkedList cll;
    cll.insertAtEnd(5);
    cll.insertAtEnd(15);
    cll.insertAtEnd(25);
    cll.insertAtEnd(35);

    cout << "Size of Circular Linked List: " << cll.getSize() << endl;
    return 0;
}
