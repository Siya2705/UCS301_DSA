#include <iostream>
using namespace std;

#define MAXLEN 100

char stack[MAXLEN];
int top = -1;

bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top == MAXLEN - 1;
}

void push(char a) {
    if (!isFull()) {
        top++;
        stack[top] = a;
        cout << "Pushed " << stack[top] << endl;
    }
}

void pop() {
    if (!isEmpty()) {
        cout << "Popped " << stack[top] << endl;
        top--;
    }
}

char peek() {
    if (!isEmpty()) {
        return stack[top];
    } else {
        cout << "Stack is empty" << endl;
        return '\0';
    }
}

void display() {
    cout << endl << endl;
    for (int i = 0; i <= top; i++) {
        cout << stack[i];
    }
    cout << endl << endl;
}

int main() {
    string a = "DataStructure";
    for (int i = 0; i < a.length(); i++) {
        push(a[i]);
    }

    char revStack[MAXLEN];
    int revTop = -1;

    while (!isEmpty()) {
        if (revTop < MAXLEN - 1) {
            revTop++;
            revStack[revTop] = peek();
            pop();
        }
    }

    cout << endl << endl;
    for (int i = 0; i <= revTop; i++) {
        cout << revStack[i];
    }
    cout << endl << endl;

    return 0;
}
