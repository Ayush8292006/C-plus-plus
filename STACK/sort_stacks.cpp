#include<iostream>
#include<stack>
using namespace std;

void insertSorted(stack<int> &s, int target){
    // base case: insert when stack empty OR correct position found
    if(s.empty() || s.top() >= target){
        s.push(target);
        return;
    }

    int topElement = s.top();
    s.pop();

    insertSorted(s, target);

    // backtrack
    s.push(topElement);
}

void sortStack(stack<int> &s){
    // base
    if(s.empty()){
        return;
    }

    int topElement =s.top();
    s.pop();
    sortStack(s);

    insertSorted(s,topElement);
}



int main(){
    stack<int> s;
    s.push(7);
    s.push(11);
    s.push(3);
    s.push(5);
    s.push(9);

    sortStack(s); 

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout<<endl;
    return 0;
} 