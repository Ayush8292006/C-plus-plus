#include<iostream>
using namespace std;

// ================= NODE CLASS =================
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// ================= PRINT LINKED LIST =================
void print(Node* head){
    while(head != nullptr){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// ================= GET LENGTH OF LL =================
int getLength(Node* head){
    int len = 0;
    while(head != nullptr){
        len++;
        head = head->next;
    }
    return len;
}

// ================= REVERSE K NODES =================
Node* reverseKNodes(Node* head, int k){
    if(head == nullptr){
        cout << "Empty list" << endl;
        return nullptr;
    }

    int len = getLength(head);

    // If k is greater than length, don't reverse
    if(k > len){
        cout << "Enter valid value for k" << endl;
        return head;
    }

    // STEP 1: Reverse first k nodes
    Node* prev = nullptr;
    Node* curr = head;
    Node* forward = nullptr;
    int count = 0;

    while(curr != nullptr && count < k){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    // STEP 2: Recursive call for remaining list
    if(forward != nullptr){
        head->next = reverseKNodes(forward, k);
    }

    // STEP 3: Return new head
    return prev;
}

// ================= MAIN FUNCTION =================
int main(){
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);
    Node* sixth = new Node(60);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;

    cout << "Original Linked List: ";
    print(head);

    int k = 3;
    head = reverseKNodes(head, k);

    cout << "After reversing in groups of " << k << ": ";
    print(head);

    return 0;
}
