#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    void helper(vector<int>& v, int n, int &ans, int currNum) {
        // base case
        if (currNum == n + 1) {
            ans++;
            return;
        }

        for (int i = 1; i <= n; i++) {
            if (v[i] == 0 && (i % currNum == 0 || currNum % i == 0)) {
                v[i] = currNum;                      // place
                helper(v, n, ans, currNum + 1);      // recurse
                v[i] = 0;                            // backtrack
            }
        }
    }

    int countArrangement(int n) {
        vector<int> v(n + 1, 0);
        int ans = 0;
        helper(v, n, ans, 1);
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    Solution s;
    cout << "Beautiful arrangements count = " << s.countArrangement(n) << endl;

    return 0;
}
