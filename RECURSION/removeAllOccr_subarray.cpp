#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    // Recursive helper function to remove all occurrences
    void removeOCCRE(string &s, string &part) {
        int found = s.find(part);        // find index of 'part' in 's'

        if (found == string::npos) {     // base case: if not found, stop recursion
            return;
        }

        // divide string into two parts and remove the found substring
        string left_part = s.substr(0, found);
        string right_part = s.substr(found + part.size());

        // merge the remaining parts
        s = left_part + right_part;

        // recursive call until all occurrences are gone
        removeOCCRE(s, part);
    }

    // Wrapper function
    string removeOccurrences(string s, string part) {
        removeOCCRE(s, part);
        return s;
    }
};

int main() {
    Solution sol;

    string s, part;
    cout << "Enter the main string: ";
    cin >> s;
    cout << "Enter the substring to remove: ";
    cin >> part;

    string result = sol.removeOccurrences(s, part);
    cout << "Result after removal: " << result << endl;

    return 0;
}
