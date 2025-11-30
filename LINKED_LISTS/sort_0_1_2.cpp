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

// ================= METHOD 1: In-place counting =================
void sortZeroOneTwo(Node* &head) {
    if (head == NULL) return;

    int zero = 0, one = 0, two = 0;
    Node* temp = head;

    // Count 0s, 1s, 2s
    while (temp != NULL) {
        if (temp->data == 0) zero++;
        else if (temp->data == 1) one++;
        else two++;
        temp = temp->next;
    }

    // Fill linked list
    temp = head;
    while (zero--) { temp->data = 0; temp = temp->next; }
    while (one--)  { temp->data = 1; temp = temp->next; }
    while (two--)  { temp->data = 2; temp = temp->next; }
}

// ================= METHOD 2: Dummy Node Method =================
Node* sort2(Node* &head) {
    Node* zeroHead = new Node(-1), *zeroTail = zeroHead;
    Node* oneHead  = new Node(-1), *oneTail  = oneHead;
    Node* twoHead  = new Node(-1), *twoTail  = twoHead;

    Node* curr = head;
    while (curr != NULL) {
        Node* temp = curr;
        curr = curr->next;
        temp->next = NULL;

        if (temp->data == 0) {
            zeroTail->next = temp;
            zeroTail = temp;
        } else if (temp->data == 1) {
            oneTail->next = temp;
            oneTail = temp;
        } else {
            twoTail->next = temp;
            twoTail = temp;
        }
    }

    // Remove dummy nodes
    Node* temp;
    temp = oneHead; oneHead = oneHead->next; delete temp;
    temp = twoHead; twoHead = twoHead->next; delete temp;
    temp = zeroHead; zeroHead = zeroHead->next; delete temp;

    // Join lists
    if (oneHead != NULL) {
        zeroTail->next = oneHead;
        oneTail->next = twoHead;
    } else {
        zeroTail->next = twoHead;
    }

    return zeroHead;
}

int main() {
    // Input linked list: 1 -> 2 -> 2 -> 0 -> 0 -> 0
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(0);
    head->next->next->next->next = new Node(0);
    head->next->next->next->next->next = new Node(0);

    cout << "Original LL: ";
    print(head);

    // Method 1: In-place counting
    sortZeroOneTwo(head);
    cout << "After sorting (counting method): ";
    print(head);

    // Reset linked list for method 2
    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(0);
    head->next->next->next->next = new Node(0);
    head->next->next->next->next->next = new Node(0);

    // Method 2: Dummy node method
    head = sort2(head);
    cout << "After sorting (dummy node method): ";
    print(head);

    return 0;
}
