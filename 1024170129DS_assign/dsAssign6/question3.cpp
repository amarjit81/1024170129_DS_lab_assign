#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = prev = NULL;
    }
};

// ==================== DOUBLY LINKED LIST ====================
class DoublyList {
    Node *head;
public:
    DoublyList() {
        head = NULL;
    }

    void insert(int val) {
        Node *n = new Node(val);
        if (head == NULL) {
            head = n;
        } else {
            Node *temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = n;
            n->prev = temp;
        }
    }

    int size() {
        int count = 0;
        Node *temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void display() {
        Node *temp = head;
        cout << "Doubly List: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// ==================== CIRCULAR LINKED LIST ====================
class CircularList {
    Node *head;
public:
    CircularList() {
        head = NULL;
    }

    void insert(int val) {
        Node *n = new Node(val);
        if (head == NULL) {
            head = n;
            n->next = head;
        } else {
            Node *temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = n;
            n->next = head;
        }
    }

    int size() {
        if (head == NULL)
            return 0;
        int count = 0;
        Node *temp = head;
        do {
            count++;
            temp = temp->next;
        } while (temp != head);
        return count;
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        Node *temp = head;
        cout << "Circular List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

// ==================== MAIN FUNCTION ====================
int main() {
    DoublyList dlist;
    CircularList clist;

    dlist.insert(10);
    dlist.insert(20);
    dlist.insert(30);
    clist.insert(5);
    clist.insert(15);
    clist.insert(25);
    clist.insert(35);

    dlist.display();
    cout << "Size of Doubly Linked List: " << dlist.size() << endl;

    clist.display();
    cout << "Size of Circular Linked List: " << clist.size() << endl;

    return 0;
}
