#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addRE(string num1, int p1, string num2, int p2, int carry = 0) {
        // base case
        if (p1 < 0 && p2 < 0) {
            if (carry != 0) {
                return string(1, carry + '0');
            }
            return "";
        }

        // current digits
        int n1 = (p1 >= 0 ? num1[p1] : '0') - '0';
        int n2 = (p2 >= 0 ? num2[p2] : '0') - '0';
        int csum = n1 + n2 + carry;
        int digit = csum % 10;
        carry = csum / 10;

        // recursive call
        string ans = addRE(num1, p1 - 1, num2, p2 - 1, carry);
        ans.push_back(digit + '0');

        return ans;
    }

    string addStrings(string num1, string num2) {
        string ans = addRE(num1, num1.size() - 1, num2, num2.size() - 1);
        return ans;
    }
};

int main() {
    Solution s;
    string num1, num2;
    cin >> num1 >> num2;
    cout << s.addStrings(num1, num2) << endl;
}
