#include<iostream>
#include<stack>
using namespace std;

void insertSorted(stack<int> &s, int target){
    // Insert when stack empty OR top <= target (correct position)
    if(s.empty() || s.top() <= target){
        s.push(target);
        return;
    }

    // Remove top and recurse
    int topElement = s.top();
    s.pop();

    insertSorted(s, target);

    // Backtrack: restore element
    s.push(topElement);
}

// Helper function to print stack bottom → top
void printBottomToTop(stack<int> s){
    if(s.empty()) return;

    int x = s.top();
    s.pop();
    printBottomToTop(s);
    cout << x << " ";
}

int main(){
    stack<int> s;

    s.push(1);
    s.push(3);
    s.push(5);

    insertSorted(s, 4);

    cout << "Stack in increasing order (bottom to top): ";
    printBottomToTop(s);
}
