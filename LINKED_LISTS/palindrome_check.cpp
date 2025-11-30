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

Node* reverse(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

bool checkPallindrome(Node* head){
    if(head== NULL || head->next==NULL){
        return true;
    }

    //  Step 1: Find middle
    Node* slow=head;
    Node* fast=head->next;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    //  Step 2: Reverse second half
    Node* secondHalf = reverse(slow);

    //  Step 3: Compare both halves
    Node* temp1=head;
    Node* temp2=secondHalf;

    while(temp2!=NULL){
        if(temp1->data != temp2->data){
            return false;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return true;
}

int main(){

    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(20);
    Node* fifth = new Node(10);

    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;

    bool isPallindrome = checkPallindrome(head);

    if(isPallindrome){
        cout<<"LL is palindrome"<<endl;
    } else {
        cout<<"Not a palindrome"<<endl;
    }
}
