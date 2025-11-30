#include<iostream>
using namespace std;

class Stack {
public:
    int *arr;
    int size;
    int top1;
    int top2;

    Stack(int size) {
        arr = new int[size];
        this->size = size;
        top1 = -1;
        top2 = size;
    }

    // PUSH in Stack 1
    void push1(int data) {
        if(top2 - top1 == 1) {
            cout << "Stack overflow in stack1" << endl;
        }
        else {
            top1++;
            arr[top1] = data;
        }
    }

    // POP from Stack 1
    void pop1() {
        if(top1 == -1) {
            cout << "Underflow in stack1" << endl;
        }
        else {
            top1--;
        }
    }

    // GET TOP of Stack 1
    int getTop1() {
        if(top1 == -1) {
            cout << "Stack1 is empty" << endl;
            return -1;
        }
        return arr[top1];
    }

    // PUSH in Stack 2
    void push2(int data) {
        if(top2 - top1 == 1) {
            cout << "Stack overflow in stack2" << endl;
        }
        else {
            top2--;
            arr[top2] = data;
        }
    }

    // POP from Stack 2
    void pop2() {
        if(top2 == size) {
            cout << "Underflow in stack2" << endl;
        }
        else {
            top2++;
        }
    }

    // GET TOP of Stack 2
    int getTop2() {
        if(top2 == size) {
            cout << "Stack2 is empty" << endl;
            return -1;
        }
        return arr[top2];
    }
};

int main() {
    Stack s(10);

    // Stack1 pushes
    s.push1(10);
    s.push1(20);
    s.push1(30);

    // Stack2 pushes
    s.push2(100);
    s.push2(200);
    s.push2(300);

    cout << "Top of Stack1: " << s.getTop1() << endl;
    cout << "Top of Stack2: " << s.getTop2() << endl;

    // Pop from both stacks
    s.pop1();
    s.pop2();

    cout << "After popping:" << endl;
    cout << "Top of Stack1: " << s.getTop1() << endl;
    cout << "Top of Stack2: " << s.getTop2() << endl;

    return 0;
}
