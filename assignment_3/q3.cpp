#include <iostream>
using namespace std;

#define MAXLEN 100

char stackArr[MAXLEN];
int top = -1;

void push(char c) {
    if (top < MAXLEN - 1) {
        stackArr[++top] = c;
    }
}

char pop() {
    if (top >= 0) {
        return stackArr[top--];
    }
    return '\0'; // empty stack
}

bool isEmpty() {
    return top == -1;
}

bool isBalanced(string expr) {
    top = -1;  // reset stack
    for (int i = 0; i < (int)expr.length(); i++) {
        char ch = expr[i];
        if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            if (isEmpty()) return false;
            pop();
        }
    }
    return isEmpty();
}

int main() {
    string expression;
    cout << "Enter expression: ";
    getline(cin, expression);

    if (isBalanced(expression)) {
        cout << "Parentheses are balanced.\n";
    } else {
        cout << "Parentheses are not balanced.\n";
    }

    return 0;
}
