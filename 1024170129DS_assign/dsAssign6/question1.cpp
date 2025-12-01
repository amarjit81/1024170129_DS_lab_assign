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

// --------------------- Doubly Linked List ---------------------
class DoublyList {
    Node *head;
public:
    DoublyList() { head = NULL; }

    void insertFirst(int val) {
        Node *n = new Node(val);
        if (!head) {
            head = n;
        } else {
            n->next = head;
            head->prev = n;
            head = n;
        }
    }

    void insertLast(int val) {
        Node *n = new Node(val);
        if (!head) {
            head = n;
            return;
        }
        Node *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = n;
        n->prev = temp;
    }

    void insertAfter(int key, int val) {
        Node *temp = head;
        while (temp && temp->data != key)
            temp = temp->next;
        if (!temp) {
            cout << "Node not found!\n";
            return;
        }
        Node *n = new Node(val);
        n->next = temp->next;
        if (temp->next)
            temp->next->prev = n;
        temp->next = n;
        n->prev = temp;
    }

    void deleteNode(int key) {
        if (!head) {
            cout << "List is empty!\n";
            return;
        }
        Node *temp = head;
        while (temp && temp->data != key)
            temp = temp->next;

        if (!temp) {
            cout << "Node not found!\n";
            return;
        }

        if (temp == head)
            head = head->next;
        if (temp->prev)
            temp->prev->next = temp->next;
        if (temp->next)
            temp->next->prev = temp->prev;

        delete temp;
        cout << "Node deleted successfully.\n";
    }

    void search(int key) {
        Node *temp = head;
        while (temp) {
            if (temp->data == key) {
                cout << "Node found!\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Node not found.\n";
    }

    void display() {
        Node *temp = head;
        cout << "Doubly Linked List: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// --------------------- Circular Linked List ---------------------
class CircularList {
    Node *head;
public:
    CircularList() { head = NULL; }

    void insertFirst(int val) {
        Node *n = new Node(val);
        if (!head) {
            head = n;
            n->next = head;
            return;
        }
        Node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        n->next = head;
        temp->next = n;
        head = n;
    }

    void insertLast(int val) {
        Node *n = new Node(val);
        if (!head) {
            head = n;
            n->next = head;
            return;
        }
        Node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = n;
        n->next = head;
    }

    void deleteNode(int key) {
        if (!head) {
            cout << "List empty!\n";
            return;
        }
        Node *curr = head, *prev = NULL;
        while (curr->data != key) {
            if (curr->next == head) {
                cout << "Node not found!\n";
                return;
            }
            prev = curr;
            curr = curr->next;
        }

        if (curr == head && curr->next == head) {
            head = NULL;
            delete curr;
            return;
        }

        if (curr == head) {
            Node *temp = head;
            while (temp->next != head)
                temp = temp->next;
            head = head->next;
            temp->next = head;
        } else {
            prev->next = curr->next;
        }
        delete curr;
        cout << "Node deleted.\n";
    }

    void search(int key) {
        if (!head) {
            cout << "Empty list!\n";
            return;
        }
        Node *temp = head;
        do {
            if (temp->data == key) {
                cout << "Node found!\n";
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Node not found!\n";
    }

    void display() {
        if (!head) {
            cout << "List is empty!\n";
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

// --------------------- Main Menu ---------------------
int main() {
    DoublyList dlist;
    CircularList clist;
    int choice, listType, val, key;

    cout << "1. Doubly Linked List\n2. Circular Linked List\nChoose type: ";
    cin >> listType;

    do {
        cout << "\nMenu:\n1. Insert First\n2. Insert Last\n3. Insert After\n4. Delete Node\n5. Search\n6. Display\n0. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter value: "; cin >> val;
            (listType == 1) ? dlist.insertFirst(val) : clist.insertFirst(val);
            break;
        case 2:
            cout << "Enter value: "; cin >> val;
            (listType == 1) ? dlist.insertLast(val) : clist.insertLast(val);
            break;
        case 3:
            if (listType == 1) {
                cout << "Enter key and value: ";
                cin >> key >> val;
                dlist.insertAfter(key, val);
            } else {
                cout << "Insert After not supported directly for circular list.\n";
            }
            break;
        case 4:
            cout << "Enter value to delete: "; cin >> val;
            (listType == 1) ? dlist.deleteNode(val) : clist.deleteNode(val);
            break;
        case 5:
            cout << "Enter value to search: "; cin >> val;
            (listType == 1) ? dlist.search(val) : clist.search(val);
            break;
        case 6:
            (listType == 1) ? dlist.display() : clist.display();
            break;
        }
    } while (choice != 0);

    return 0;
}
