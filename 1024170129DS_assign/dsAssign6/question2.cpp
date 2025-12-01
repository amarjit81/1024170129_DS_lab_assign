#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class CircularList {
    Node* head;
public:
    CircularList() {
        head = NULL;
    }

    void insert(int val) {
        Node* n = new Node(val);
        if (head == NULL) {
            head = n;
            n->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = n;
            n->next = head;
        }
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        // repeat head node at end
        cout << head->data << endl;
    }
};

int main() {
    CircularList cl;
    cl.insert(20);
    cl.insert(100);
    cl.insert(40);
    cl.insert(80);
    cl.insert(60);

    cl.display(); // Expected Output: 20 100 40 80 60 20

    return 0;
}
