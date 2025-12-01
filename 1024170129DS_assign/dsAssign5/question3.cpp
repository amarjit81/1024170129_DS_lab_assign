#include<iostream>
using namespace std;
class node{
    public: 
    int data ;
    node*next;
    node(int val){
        data =val;
    }
};
int getlength(node*head){
    node*temp=head;int count1=0;
    while(temp!=NULL){
      count1++;
      temp=temp->next;

    } return (count1/2);
}

node* findmid(node*head){
    node*temp1=head;
    int count2=1;
    while(count2<=getlength(head)){
        count2++;
        temp1=temp1->next;
    }
    return temp1;
}
int main(){
    node*head=new node(1);
    head->next=new node (2);
    head->next->next=new node(3);
    head->next->next->next=new node(4);
    node*x=findmid(head);
    cout<<" the data of the midlle point is "<<x->data;
    return 0;
}