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

// ================= PRINT =================
void print(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// ================= LOOP DETECTION =================
bool checkForLoop(Node* head){
    if(head == NULL){
        cout << "Linked List is empty" << endl;
        return false;
    }

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            return true;
        }
    }
    return false;
}

// ================= FIND STARTING POINT OF LOOP =================
Node* startingPointLoop(Node* head){
    if(head == NULL){
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;
  

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            slow = head;
            break;
        }
    }

    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

// ================= REMOVE LOOP =================
Node* removeLoop(Node* head){
    if(head == NULL){
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;
    

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
          slow = head;
            break;
        }
    }


    slow = head;
    Node* prev = NULL;

    while(slow != fast){
        prev = fast;          
        slow = slow->next;
        fast = fast->next;
    }

    prev->next = NULL;        // break the loop
    return head;
}

// ================= MAIN =================
int main(){
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);
    Node* sixth = new Node(60);
    Node* seventh = new Node(70);
    Node* eighth = new Node(80);
    Node* ninth = new Node(90);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eighth;
    eighth->next = ninth;

    // Creating loop
    ninth->next = fifth;

    if(checkForLoop(head)){
        cout << "Loop is present in Linked List" << endl;

        Node* start = startingPointLoop(head);
        if(start != NULL){
            cout << "Starting point of loop is node with data: "
                 << start->data << endl;
        }

        head = removeLoop(head);

        if(!checkForLoop(head)){
            cout << "Loop successfully removed " << endl;
            cout << "Linked List after removing loop: ";
            print(head);
        }
    } 
    else {
        cout << "No loop in Linked List" << endl;
    }

    return 0;
}
