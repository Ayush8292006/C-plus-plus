#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

// ================= PRINT =================
void print(Node* head){
    if(head == NULL){
        cout << "List Empty" << endl;
        return;
    }

    Node* temp = head;
    do{
        cout << temp->data << " ";
        temp = temp->next;
    }while(temp != head);

    cout << endl;
}

// ================= GET LENGTH =================
int getLength(Node* head){
    if(head == NULL) return 0;

    int len = 0;
    Node* temp = head;
    do{
        len++;
        temp = temp->next;
    }while(temp != head);

    return len;
}

// ================= INSERT AT HEAD =================
void insertAtHead(Node* &head, Node* &tail, int data){
    Node* newNode = new Node(data);

    if(head == NULL){
        head = tail = newNode;
        head->next = head;
        head->prev = head;
        return;
    }

    newNode->next = head;
    newNode->prev = tail;
    head->prev = newNode;
    tail->next = newNode;
    head = newNode;
}

// ================= INSERT AT TAIL =================
void insertAtTail(Node* &head, Node* &tail, int data){
    Node* newNode = new Node(data);

    if(head == NULL){
        head = tail = newNode;
        head->next = head;
        head->prev = head;
        return;
    }

    newNode->prev = tail;
    newNode->next = head;
    tail->next = newNode;
    head->prev = newNode;
    tail = newNode;
}

// ================= INSERT AT POSITION =================
void insertAtPosition(Node* &head, Node* &tail, int data, int position){

    if(head == NULL || position == 1){
        insertAtHead(head, tail, data);
        return;
    }

    int len = getLength(head);

    if(position > len){
        insertAtTail(head, tail, data);
        return;
    }

    Node* prevNode = head;
    int i = 1;

    while(i < position-1){
        prevNode = prevNode->next;
        i++;
    }

    Node* curr = prevNode->next;
    Node* newNode = new Node(data);

    newNode->next = curr;
    newNode->prev = prevNode;
    prevNode->next = newNode;
    curr->prev = newNode;
}

// ================= DELETE FROM POSITION =================
void deleteFromPos(Node* &head, Node* &tail, int position){

    if(head == NULL){
        cout<<"Linked List is empty"<<endl;
        return;
    }

    int len = getLength(head);

    if(position <= 0 || position > len){
        cout<<"Invalid Position"<<endl;
        return;
    }

    // Single node
    if(head == tail){
        delete head;
        head = tail = NULL;
        return;
    }

    if(position == 1){
        Node* temp = head;
        head = head->next;

        head->prev = tail;
        tail->next = head;

        temp->next = NULL;
        temp->prev = NULL;
        delete temp;
        return;
    }

    if(position == len){
        Node* temp = tail;
        tail = tail->prev;

        tail->next = head;
        head->prev = tail;

        temp->next = NULL;
        temp->prev = NULL;
        delete temp;
        return;
    }

    Node* left = head;
    int i = 1;

    while(i < position-1){
        left = left->next;
        i++;
    }

    Node* curr = left->next;
    Node* right = curr->next;

    left->next = right;
    right->prev = left;

    curr->next = NULL;
    curr->prev = NULL;
    delete curr;
}

// ================= MAIN =================
int main(){

    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 50);

    cout << "Initial Circular Doubly List: ";
    print(head);

    cout << "Length: " << getLength(head) << endl;

    insertAtPosition(head, tail, 25, 3);
    cout << "After insertAtPosition(25,3): ";
    print(head);

    deleteFromPos(head, tail, 3);
    cout << "After deleteFromPos(3): ";
    print(head);

    return 0;
}
