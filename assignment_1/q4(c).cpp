#include <iostream>
using namespace std;

int main() {
    int A[10][10], B[10][10], C[10][10]={0};
    int r1, c1, r2, c2;
    cout << "Enter rows and columns of 1st matrix ";
    cin >> r1 >> c1;
    cout << "Enter rows and columns of 2nd matrix ";
    cin >> r2 >> c2;

    if (c1 != r2) {
        cout << "Multiplication not possible " << endl;
        return 0;
    }

    cout << "Enter elements of 1st matrix\n";
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            cin >> A[i][j];

    cout << "Enter elements of 2nd matrix\n";
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            cin >> B[i][j];

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "Answer = \n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
