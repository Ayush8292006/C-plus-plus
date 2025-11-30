#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// ================= PRINT =================
void print(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// ================= REVERSE FUNCTION =================
Node* reverse(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    while(curr != NULL){
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

// ================= ADD TWO LINKED LISTS =================
Node* solve(Node* &head1, Node* &head2){
    // Step 1: Reverse both linked lists
    head1 = reverse(head1);
    head2 = reverse(head2);

    Node* ansHead = NULL;
    Node* ansTail = NULL;
    int carry = 0;

    // Step 2: Add the numbers
    while(head1 != NULL || head2 != NULL || carry != 0){
        int sum = carry;
        if(head1 != NULL){
            sum += head1->data;
            head1 = head1->next;
        }
        if(head2 != NULL){
            sum += head2->data;
            head2 = head2->next;
        }

        int digit = sum % 10;
        carry = sum / 10;

        Node* newNode = new Node(digit);

        if(ansHead == NULL){
            // first node insert
            ansHead = newNode;
            ansTail = newNode;
        } else{
            ansTail->next = newNode;
            ansTail = newNode;
        }
    }

    // Step 3: Reverse the result to get the final sum
    ansHead = reverse(ansHead);

    return ansHead;
}

int main(){

    // First number: 2 -> 4 (represents 24)
    Node* head1 = new Node(9);
    Node* second1 = new Node(9);
    Node* third1 = new Node(9);
    head1->next = second1;
    second1->next = third1;

    // Second number: 2 -> 3 -> 4 (represents 234)
    Node* head2 = new Node(9);
    Node* second2 = new Node(9);
    Node* third2 = new Node(9);
    head2->next = second2;
    second2->next = third2;

    Node* ans = solve(head1, head2);

    cout << "Sum of linked lists: ";
    print(ans); // Expected output: 2 5 8

    return 0;
}
