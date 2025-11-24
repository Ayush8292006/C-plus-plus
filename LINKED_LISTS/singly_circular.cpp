#include<iostream>
using namespace std;

// Node structure for Circular Singly Linked List
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }

    ~Node() {
        cout << "Deleted node with data: " << data << endl;
    }
};

// ================= PRINT =================
void print(Node* tail) {
    if(tail == nullptr){
        cout << "List Empty" << endl;
        return;
    }

    Node* temp = tail->next; // head
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while(temp != tail->next);
    cout << endl;
}

// ================= FIND LENGTH =================
int findLength(Node* tail){
    if(tail == nullptr) return 0;

    int len = 0;
    Node* temp = tail->next;
    do {
        len++;
        temp = temp->next;
    } while(temp != tail->next);

    return len;
}

// ================= INSERT AT HEAD =================
void insertAtHead(Node* &tail, int data) {
    Node* newNode = new Node(data);

    if(tail == nullptr){
        tail = newNode;
        newNode->next = newNode;
        return;
    }

    newNode->next = tail->next;
    tail->next = newNode;
}

// ================= INSERT AT TAIL =================
void insertAtTail(Node* &tail, int data){
    Node* newNode = new Node(data);

    if(tail == nullptr){
        tail = newNode;
        newNode->next = newNode;
        return;
    }

    newNode->next = tail->next;
    tail->next = newNode;
    tail = newNode;
}

// ================= INSERT AT POSITION =================
void insertAtPosition(int data, int position, Node* &tail){
    if(position <= 1){
        insertAtHead(tail, data);
        return;
    }

    int len = findLength(tail);

    if(position > len){
        insertAtTail(tail, data);
        return;
    }

    Node* prev = tail->next;
    for(int i = 1; i < position - 1; i++){
        prev = prev->next;
    }

    Node* newNode = new Node(data);
    newNode->next = prev->next;
    prev->next = newNode;
}

// ================= DELETE FIRST =================
void deleteFirst(Node* &tail){
    if(tail == nullptr){
        cout << "List Empty" << endl;
        return;
    }

    Node* head = tail->next;

    if(head == tail){
        delete head;
        tail = nullptr;
        return;
    }

    tail->next = head->next;
    head->next = nullptr;
    delete head;
}

// ================= DELETE LAST =================
void deleteLast(Node* &tail){
    if(tail == nullptr){
        cout << "List Empty" << endl;
        return;
    }

    if(tail->next == tail){
        delete tail;
        tail = nullptr;
        return;
    }

    Node* prev = tail->next;
    while(prev->next != tail){
        prev = prev->next;
    }

    prev->next = tail->next;
    delete tail;
    tail = prev;
}

// ================= DELETE MIDDLE =================
void deleteMiddle(int position, Node* &tail){
    int len = findLength(tail);

    if(position <= 1 || position >= len){
        cout << "Use deleteFirst or deleteLast!" << endl;
        return;
    }

    Node* prev = tail->next;
    for(int i = 1; i < position - 1; i++){
        prev = prev->next;
    }

    Node* curr = prev->next;
    prev->next = curr->next;
    curr->next = nullptr;
    delete curr;
}

// ================= DELETE COMPLETE =================
void deleteComplete(Node* &tail){
    if(tail == nullptr) return;

    Node* head = tail->next;
    Node* temp = head;

    do {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    } while(temp != head);

    tail = nullptr;
    cout << "Entire Circular Linked List Deleted..." << endl;
}

// ================= MAIN =================
int main(){

    Node* tail = nullptr;

    insertAtHead(tail, 10);
    insertAtHead(tail, 20);
    insertAtHead(tail, 30);

    insertAtTail(tail, 40);
    insertAtTail(tail, 50);

    cout << "Original List: ";
    print(tail);

    insertAtPosition(25, 2, tail);
    cout << "After inserting 25 at position 2: ";
    print(tail);

    deleteFirst(tail);
    cout << "After deleting first: ";
    print(tail);

    deleteLast(tail);
    cout << "After deleting last: ";
    print(tail);

    deleteMiddle(2, tail);
    cout << "After deleting middle: ";
    print(tail);

    deleteComplete(tail);

    return 0;
}
