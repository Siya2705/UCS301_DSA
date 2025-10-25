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

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }

    void makeCircular() {
        if (head == nullptr) return;
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = head;
    }

    bool isCircular() {
        if (head == nullptr)
            return false;

        Node* temp = head->next;
        while (temp != nullptr && temp != head)
            temp = temp->next;

        return (temp == head);
    }
};

int main() {
    LinkedList list;

    list.insertAtEnd(2);
    list.insertAtEnd(4);
    list.insertAtEnd(6);
    list.insertAtEnd(7);
    list.insertAtEnd(5);

    list.makeCircular();

    if (list.isCircular())
        cout << "Output: True" << endl;
    else
        cout << "Output: False" << endl;

    return 0;
}
