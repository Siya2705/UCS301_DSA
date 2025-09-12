#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void firstNonRepeating(string s) {
    queue<char> q;
    vector<int> freq(256, 0);

    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        freq[ch]++;
        q.push(ch);

        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }

        if (!q.empty()) cout << q.front() << " ";
        else cout << "-1 ";
    }
    cout << "\n";
}

int main() {
    string str;
    getline(cin, str);
    firstNonRepeating(str);
    return 0;
}
