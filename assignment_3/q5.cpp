#include <iostream>
#include <string>
#include <cmath>
using namespace std;

#define MAXLEN 100

int stackArr[MAXLEN];
int top = -1;

void push(int val) {
    if (top < MAXLEN - 1) {
        stackArr[++top] = val;
    }
}

int pop() {
    if (top >= 0) {
        return stackArr[top--];
    }
    return 0;
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int performOperation(int a, int b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return b != 0 ? a / b : 0; // basic check for divide by zero
        case '^': return pow(a, b);
    }
    return 0;
}

int evaluatePostfix(string expr) {
    top = -1;
    for (int i = 0; i < (int)expr.length(); i++) {
        char c = expr[i];
        if (c >= '0' && c <= '9') {
            push(c - '0'); // convert char digit to int
        } else if (isOperator(c)) {
            int val2 = pop();
            int val1 = pop();
            int res = performOperation(val1, val2, c);
            push(res);
        }
    }
    return pop();
}

int main() {
    string postfixExp;
    cout << "Enter postfix expression (digits and operators only): ";
    getline(cin, postfixExp);
    int result = evaluatePostfix(postfixExp);
    cout << "Result: " << result << endl;
    return 0;
}
