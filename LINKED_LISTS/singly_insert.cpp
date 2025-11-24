#include<iostream>
using namespace std;

// Node structure for Singly Linked List
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }

    // ✅ DESTRUCTOR
    ~Node() {
        if(next != nullptr){
            delete next;
            next = nullptr;
        }
        cout << "Deleted node with data: " << data << endl;
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

// ================= INSERT AT HEAD =================
void insertAtHead(Node* &head, Node* &tail, int data) {
    if(head == nullptr){
        head = tail = new Node(data);
        return;
    }
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

// ================= INSERT AT TAIL =================
void insertAtTail(Node* &head, Node* &tail, int data){
    if(head == nullptr){
        head = tail = new Node(data);
        return;
    }
    Node* newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}

// ================= FIND LENGTH =================
int findLength(Node* head){
    int len = 0;
    while(head != nullptr){
        len++;
        head = head->next;
    }
    return len;
}

// ================= INSERT AT ANY POSITION =================
void insertAtPosition(int data, int position, Node* &head, Node* &tail){

    if(position <= 1){
        insertAtHead(head, tail, data);
        return;
    }

    int len = findLength(head);

    if(position > len){
        insertAtTail(head, tail, data);
        return;
    }

    Node* prev = head;
    for(int i = 1; i < position - 1; i++){
        prev = prev->next;
    }

    Node* newNode = new Node(data);
    newNode->next = prev->next;
    prev->next = newNode;
}

// ================= DELETE FIRST =================
void deleteFirst(Node* &head, Node* &tail){
    if(head == nullptr){
        cout << "List Empty" << endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    temp->next = nullptr;
    delete temp;

    if(head == nullptr)
        tail = nullptr;
}

// ================= DELETE LAST =================
void deleteLast(Node* &head, Node* &tail){
    if(head == nullptr){
        cout << "List Empty" << endl;
        return;
    }

    if(head == tail){
        delete head;
        head = tail = nullptr;
        return;
    }

    Node* prev = head;
    while(prev->next != tail){
        prev = prev->next;
    }

    delete tail;
    prev->next = nullptr;
    tail = prev;
}

// ================= DELETE MIDDLE =================
void deleteMiddle(int position, Node* &head, Node* &tail){
    int len = findLength(head);

    if(position <= 1 || position >= len){
        cout << "Use deleteFirst or deleteLast for this position!" << endl;
        return;
    }

    Node* prev = head;
    for(int i = 1; i < position - 1; i++){
        prev = prev->next;
    }

    Node* curr = prev->next;
    prev->next = curr->next;
    curr->next = nullptr;
    delete curr;
}

// ================= DELETE COMPLETE =================
void deleteComplete(Node* &head, Node* &tail){
    if(head == nullptr) return;

    delete head;   // destructor deletes all
    head = nullptr;
    tail = nullptr;

    cout << "Entire Linked List Deleted......" << endl;
}

// ================= MAIN =================
int main() {

    Node* head = nullptr;
    Node* tail = nullptr;

    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
     print(head);
    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 50);

    cout << "Original List: ";
    print(head);

    insertAtPosition(25, 2, head, tail);
    cout << "After inserting 25 at position 2: ";
    print(head);

    deleteFirst(head, tail);
    cout << "After deleting first: ";
    print(head);

    deleteLast(head, tail);
    cout << "After deleting last: ";
    print(head);

    deleteMiddle(2, head, tail);
    cout << "After deleting middle: ";
    print(head);

    deleteComplete(head, tail);

    return 0;
}
