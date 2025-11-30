#include <iostream>
#include<stack>
using namespace std;


    bool isBalanced(string& s) {
        stack<char> st;
        for(int i = 0; i < s.length(); i++){
            char ch = s[i];

            // opening brackets
            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }
            // closing brackets
            else{
                if(st.empty()) return false;

                char topCh = st.top();
                if((ch == ')' && topCh == '(') ||
                   (ch == '}' && topCh == '{') ||
                   (ch == ']' && topCh == '[')){
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        // stack should be empty if all brackets matched
        return st.empty();
    }

int main() {


    vector<string> tests = {
        "{[()]}",
        "{[(])}",
        "{{[[(())]]}}",
        "((()))",
        "([{}])",
        "([)]",
        "("
    };

    for(string s : tests){
        cout << s << " -> " 
             << (isBalanced(s) ? "Balanced" : "Not Balanced") 
             << endl;
    }

    return 0;
}
