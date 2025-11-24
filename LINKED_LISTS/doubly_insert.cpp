#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(){
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }

    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int getLength(Node* head){
    int len = 0;
    Node* temp = head;

    while(temp != NULL){
        len++;
        temp = temp->next;  
    }
    return len;
}

// ================= INSERT AT HEAD =================
void insertAtHead(Node* &head, Node* &tail,int data){
    if(head == NULL){
        Node* newNode = new Node(data);  
        head = newNode;
        tail = newNode;
    }
    else{
        Node* newNode = new Node(data);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// ================= INSERT AT TAIL =================
void insertAtTail(Node* &head, Node* &tail, int data){
    if(head == NULL){
        Node* newNode = new Node(data);   
        head = newNode;
        tail = newNode;
    }
    else{
        Node* newNode = new Node(data);   
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// ================= INSERT AT POSITION =================
void insertAtPosition(Node* &head, Node* &tail, int data, int position){

    if(head == NULL){
        Node* newNode = new Node(data);   
        head = newNode;
        tail = newNode;
        return;
    }

    if(position == 1){
        insertAtHead(head, tail, data);
        return;
    }

    int len = getLength(head);

    if(position > len){
        insertAtTail(head, tail, data);
        return;
    }

    // insertion in middle
    int i = 1;
    Node* prevNode = head;

    while(i < position-1){
        prevNode = prevNode->next;
        i++;
    }

    Node* curr = prevNode->next;
    Node* newNode = new Node(data);

    prevNode->next = newNode;
    newNode->prev = prevNode;
    newNode->next = curr;
    curr->prev = newNode;
}

// ================= DELETE FROM POSITION =================
void deleteFromPos(Node* &head, Node* &tail,int position){

    if(head == NULL){
        cout<<"Linked List is empty"<<endl;
        return;
    }

    int len = getLength(head);

    if(position > len || position <= 0){
        cout<<"Please enter a valid position"<<endl;
        return;
    }

    if(head->next == NULL){
        // single node
        Node* temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
        return;
    }

    if(position == 1){
        // want to delete first node
        Node* temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
        return;
    }

    if(position == len){
        // delete last node
        Node* temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        temp->prev = NULL;
        delete temp;
        return;
    }

    // delete from middle
    int i = 1;
   Node* left = head;
   while(i<position-1){
    left=left->next;
    i++;
   }

   Node* curr = left->next;
   Node* right = curr->next;

   left->next=right;
   right->prev=left;

    curr->next = NULL;
    curr->prev = NULL;
    delete curr;
}

int main(){

    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    first->next = second;
    second->prev = first;

    second->next = third;
    third->prev = second;

    Node* head = first;
    Node* tail = third;

    cout << "Initial List: ";
    print(head);

    cout << "Length: " << getLength(head) << endl;

    insertAtHead(head, tail, 5);
    cout << "After insertAtHead(5): ";
    print(head);

    insertAtTail(head, tail, 40);
    cout << "After insertAtTail(40): ";
    print(head);

    insertAtPosition(head, tail, 25, 4);
    cout << "After insertAtPosition(25, 4): ";
    print(head);

    // ✅ test delete from position
    deleteFromPos(head, tail, 4);
    cout << "After deleteFromPos(4): ";
    print(head);

    return 0;
}
