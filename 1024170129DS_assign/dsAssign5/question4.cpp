#include<iostream>
using namespace std;
class node {
    public:
    int data;
    node*next;
    node(int val){
        data =val;
        next=NULL;
    }
};

node* reverseLL(node*head){
    node*prev=NULL;
    node*forward=NULL;
    node*current=head;
     while(current!=NULL){
    forward=current->next;
    current->next=prev;
    prev=current ;
    current=forward;}
    return prev;
}
void print(node*head){
    node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main(){
    node*head=new node(1);
    head->next=new node (2);
    head->next->next= new node(3);
    cout<<" the original ll is "<<endl;
    print(head);
    head=reverseLL(head);
    cout<<" the reverse ll is "<<endl;
    print(head);

    return 0;
}