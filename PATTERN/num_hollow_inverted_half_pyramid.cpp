#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int row = n - 1; row >= 0; row--) {
        for (int col = 1; col <= row + 1; col++) {
            if (col == 1 || col == row + 1 || row == n - 1) {
                cout << col;
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
