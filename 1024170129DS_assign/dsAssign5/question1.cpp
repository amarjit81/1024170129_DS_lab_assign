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

Node* head = NULL;

void insertAtBeginning(int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}
void insertAtEnd(int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void insertAfterValue(int key, int val) {
    Node* temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;
    if (temp == NULL) {
        cout << "Node " << key << " not found."<<endl;
        return;
    }
    Node* newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertBeforeValue(int key, int val) {
    if (head == NULL) {
        cout << "List is empty."<<endl;
        return;
    }
    if (head->data == key) {
        insertAtBeginning(val);
        return;
    }
    Node* temp = head;
    while (temp->next != NULL && temp->next->data != key)
        temp = temp->next;
    if (temp->next == NULL) {
        cout << "Node " << key << " not found."<<endl;
        return;
    }
    Node* newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;
}
void deleteFromBeginning() {
    if (head == NULL) {
        cout << "List is empty."<<endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}
void deleteFromEnd() {
    if (head == NULL) {
        cout << "List is empty."<<endl;
        return;
    }
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    delete temp->next;
    temp->next = NULL;
}


void deleteSpecificNode(int key) {
    if (head == NULL) {
        cout << "List is empty."<<endl;
        return;
    }
    if (head->data == key) {
        deleteFromBeginning();
        return;
    }
    Node* temp = head;
    while (temp->next != NULL && temp->next->data != key)
        temp = temp->next;
    if (temp->next == NULL) {
        cout << "Node " << key << " not found."<<endl;
        return;
    }
    Node* del = temp->next;
    temp->next = temp->next->next;
    delete del;
}
void searchNode(int key) {
    Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == key) {
            cout << "Node " << key << " found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Node not found."<<endl;
}
void displayList() {
    if (head == NULL) {
        cout << "List is empty."<<endl;
        return;
    }
    Node* temp = head;
    cout << "Linked List: ";
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}
int main() {
    int choice, val, key;
    while (true) {
        cout << "\n===== MENU =====\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After a Value\n";
        cout << "4. Insert Before a Value\n";
        cout << "5. Delete from Beginning\n";
        cout << "6. Delete from End\n";
        cout << "7. Delete Specific Node\n";
        cout << "8. Search for a Node\n";
        cout << "9. Display List\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                insertAtBeginning(val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                insertAtEnd(val);
                break;
            case 3:
                cout << "Enter key and value: ";
                cin >> key >> val;
                insertAfterValue(key, val);
                break;
            case 4:
                cout << "Enter key and value: ";
                cin >> key >> val;
                insertBeforeValue(key, val);
                break;
            case 5:
                deleteFromBeginning();
                break;
            case 6:
                deleteFromEnd();
                break;
            case 7:
                cout << "Enter value to delete: ";
                cin >> val;
                deleteSpecificNode(val);
                break;
            case 8:
                cout << "Enter value to search: ";
                cin >> val;
                searchNode(val);
                break;
            case 9:
                displayList();
                break;
            case 10:
                cout << "Exiting..."<<endl;
                return 0;
            default:
                cout << "Invalid choice!"<<endl;
        }
    }
}
