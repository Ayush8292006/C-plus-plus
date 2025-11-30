#include <iostream>
#include <stack>
using namespace std;

// Insert element at bottom of stack
void insertAtBottom(stack<int> &s, int target) {
    if (s.empty()) {
        s.push(target);
        return;
    }

    int topElement = s.top();
    s.pop();

    // recursive call
    insertAtBottom(s, target);

    // backtracking
    s.push(topElement);
}

// Reverse the stack using recursion
void reverseStack(stack<int> &s) {
    if (s.empty()) return;

    int target = s.top();
    s.pop();

    // reverse the remaining stack
    reverseStack(s);

    // insert current element at bottom
    insertAtBottom(s, target);
}

// Helper function to print stack
void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);

    cout << "Original Stack (top -> bottom): ";
    printStack(s);

    // Reverse stack
    reverseStack(s);

    cout << "Reversed Stack (top -> bottom): ";
    printStack(s);

    return 0;
}
