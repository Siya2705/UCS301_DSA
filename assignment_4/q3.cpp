#include <iostream>
using namespace std;

#define MAXSIZE 100

int q[MAXSIZE];
int front = 0, rear = -1;

void enqueue(int val) {
    q[++rear] = val;
}

int dequeue() {
    return q[front++];
}

bool isEmpty() {
    return front > rear;
}

void interleave(int arr[], int n) {
    int half = n / 2;
    int temp[MAXSIZE];
    int idx = 0;

    for (int i = 0; i < half; i++) {
        temp[i] = arr[i];
    }

    int i = 0, j = half;
    idx = 0;

    while (i < half && j < n) {
        arr[idx++] = temp[i++];
        arr[idx++] = arr[j++];
    }

    if (n % 2 != 0) {
        arr[idx++] = arr[n - 1];
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> q[i];
    }
    front = 0;
    rear = n - 1;

    interleave(q, n);

    cout << "Interleaved queue: ";
    for (int i = 0; i < n; i++) {
        cout << q[i] << " ";
    }
    cout << endl;
    return 0;
}
