#include<iostream>
using namespace std;

class Stack{
    public:
    int *arr;
    int top;
    int size;

    Stack(int size){
        arr = new int[size];
        this->size = size;
        top = -1;
    }

    void push(int data){
        if(top < size - 1){
            arr[++top] = data;
        }
        else{
            cout << "Stack Overflow" << endl;
        }
    }

    void pop(){
        if(top == -1){
            cout << "Stack underflow, can't delete" << endl;
        }
        else{
            top--;
        }
    }

    int getTop(){
        if(top == -1){
            cout << "There is no element" << endl;
            return -1;
        }
        return arr[top];
    }

    int getSize(){
        return top + 1;
    }

    bool isEmpty(){
        return top == -1;
    }
};

int main(){
    Stack s(10);

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    while(!s.isEmpty()){
        cout << s.getTop() << " ";
        s.pop();
    }
    cout<<endl;

    cout<<"Size of stack: "<<s.getSize()<<endl;

    // s.pop();
}
