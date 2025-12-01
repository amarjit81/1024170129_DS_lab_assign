#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

Node* deleteKey(Node* head, int key, int &count) {
    
    while (head != NULL && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }

    
    Node* curr = head;
    Node* prev = NULL;

    while (curr != NULL) {
        if (curr->data == key) {
            count++;
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }

    return head;
}


void printList(Node* head) {
    while (head != NULL) {
        cout << head->data;
        if (head->next) cout << "->";
        head = head->next;
    }
    cout << endl;
}

int main() {
    
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);
    head->next->next->next->next->next = new Node(3);
    head->next->next->next->next->next->next = new Node(1);

    int key = 1;
    int count = 0;

    cout << "Original List: ";
    printList(head);

    head = deleteKey(head, key, count);

    cout << "Count: " << count << endl;
    cout << "Updated Linked List: ";
    printList(head);

    return 0;
}
