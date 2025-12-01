#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
public:
    Node *head;
    LinkedList() {
        head = NULL;
    }

    void insert(int val) {
        Node *n = new Node(val);
        if (head == NULL) {
            head = n;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL && temp->next != head)
            temp = temp->next;
        temp->next = n;
    }

    
    void makeCircular() {
        if (head == NULL) return;
        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = head;
    }

    bool isCircular() {
        if (head == NULL)
            return false;

        Node *temp = head->next;
        while (temp != NULL && temp != head)
            temp = temp->next;

        if (temp == head)
            return true;
        return false;
    }

    void display() {
        Node *temp = head;
        cout << "Linked List: ";
        while (temp && temp->next != head) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        if (temp) cout << temp->data;
        cout << endl;
    }
};

int main() {
    LinkedList list;
    list.insert(2);
    list.insert(4);
    list.insert(6);
    list.insert(7);
    list.insert(5);

    
    list.makeCircular();

    list.display();

    if (list.isCircular())
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}

