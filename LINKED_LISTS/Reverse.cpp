#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

// ================= PRINT =================
void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// ================= REVERSE FUNCTION (RECURSIVE) =================
Node* reverse(Node* prev, Node* curr){
    if(curr == NULL)
        return prev;

    Node* nextNode = curr->next;
    curr->next = prev;

    return reverse(curr, nextNode);
}

// ================= REVERSE USING LOOP =================
Node* reverseUsingLoop(Node* head){
    Node* prev = NULL;
    Node* curr = head;

    while(curr != NULL){
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

// ================= MAIN =================
int main(){

    // Creating Linked List: 10 -> 20 -> 30 -> 40
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    cout << "Original List: ";
    print(head);

    // ========== Recursive Reverse ==========
    Node* prev = NULL;
    Node* curr = head;
    head = reverse(prev, curr);

    cout << "Reversed List (Recursive): ";
    print(head);

    // ========== Loop Reverse ==========
    head = reverseUsingLoop(head);
    cout << "Reversed Again (Loop): ";
    print(head);

    return 0;
}
