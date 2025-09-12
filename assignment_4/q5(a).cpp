#include <iostream>
#include <queue>
using namespace std;

queue<int> q1, q2;

void push(int x) {
    q2.push(x);
    while(!q1.empty()) {
        q2.push(q1.front());
        q1.pop();
    }
    swap(q1, q2);
}

void pop() {
    if(q1.empty()) {
        cout << "Stack empty\n";
        return;
    }
    cout << "Popped " << q1.front() << "\n";
    q1.pop();
}

int top() {
    if(q1.empty()) {
        cout << "Stack empty\n";
        return -1;
    }
    return q1.front();
}

bool empty() {
    return q1.empty();
}

int main() {
    push(10);
    push(20);
    pop();
    cout << "Top is " << top() << "\n";
    pop();
    pop();
    return 0;
}
