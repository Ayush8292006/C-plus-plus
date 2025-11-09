#include <iostream>
using namespace std;

// LEFT TO RIGHT  

// void lastOccLTR(string& s, char x, int i, int& ans) {
//     // base case
//     if (i >= s.size()) {
//         return;
//     }

//     // agar current character x hai, to ans update karo
//     if (s[i] == x) {
//         ans = i;
//     }

//     // next index ke liye recursion
//     lastOccLTR(s, x, i + 1, ans);
// }

// RIGHT TO LEFT

void lastOccRTL(string& s, char x, int i, int& ans) {
    // base case
    if (i < 0) {
        return;
    }

    // agar current character x hai, to ans update karo
    if (s[i] == x) {
        ans = i;
        return;
    }

    // next index ke liye recursion
    lastOccRTL(s, x, i - 1, ans);
}

int main() {
    string s;
    cin >> s;  // input string
    char x;
    cin >> x;  // character to search

    int ans = -1;

    // lastOccLTR(s, x, 0, ans);
     lastOccRTL(s, x, s.size()-1, ans);
    cout << ans;
}
