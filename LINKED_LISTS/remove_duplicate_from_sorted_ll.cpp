#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
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

void removeDuplicate(Node* &head){
    if(head==NULL){
        cout<<"LL is empty"<<endl;
        return;
    }

    if(head->next == NULL){
       cout<<"Single node in LL"<<endl;
       return; 
    }

    Node* curr=head;
    while(curr!=NULL){
        if((curr->next!=NULL) && (curr->data == curr->next->data)){
            // equal
            Node* temp=curr->next;
            curr->next = curr->next->next;
            //delete node
            temp->next=NULL;
            delete temp;

        }
        else{
            // not equal

            curr = curr->next;
        }
    }
}

int main(){

    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(2);
    Node* fourth = new Node(3);
    Node* fifth = new Node(4);
    Node* sixth = new Node(4);

    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    fifth->next=sixth;

    cout<<"Input LL is: ";
    print(head);

    removeDuplicate(head);

    cout<<"After removing: ";
    print(head);

    return 0;
}
