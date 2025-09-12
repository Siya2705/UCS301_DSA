#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

void push(int x) {
    int sz = q.size();
    q.push(x);
    for(int i = 0; i < sz; i++) {
        q.push(q.front());
        q.pop();
    }
}

void pop() {
    if(q.empty()) {
        cout << "Stack empty\n";
        return;
    }
    cout << "Popped " << q.front() << "\n";
    q.pop();
}

int top() {
    if(q.empty()) {
        cout << "Stack empty\n";
        return -1;
    }
    return q.front();
}

bool empty() {
    return q.empty();
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
