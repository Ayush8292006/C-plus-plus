#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// ================= PRINT =================
void print(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// ================= FIND MIDDLE =================
Node* getMiddle(Node* &head){
    if(head == NULL){
        cout << "Linked list is empty" << endl;
        return NULL;
    }

    if(head->next == NULL){
        // only 1 node in ll
        return head;
    }

   // LL have greater than 1 node

   Node* slow = head;
   Node* fast = head;

   while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
   }

   return slow;
}

// ================= MAIN =================
int main(){

    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = NULL;

    cout << "Linked List: ";
    print(head);

    Node* middle = getMiddle(head);

    if(middle != NULL)
        cout << "Middle Node: " << middle->data << endl;

    return 0;
}
