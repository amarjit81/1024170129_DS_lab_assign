#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node *next;
    Node *prev;
    Node(char ch) {
        data = ch;
        next = prev = NULL;
    }
};

class DoublyList {
    Node *head;
    Node *tail;
public:
    DoublyList() {
        head = tail = NULL;
    }

    void insert(char ch) {
        Node *n = new Node(ch);
        if (head == NULL) {
            head = tail = n;
        } else {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
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

    bool isPalindrome() {
        if (!head) return true;
        Node *left = head;
        Node *right = tail;
        while (left != right && right->next != left) {
            if (left->data != right->data)
                return false;
            left = left->next;
            right = right->prev;
        }
        return true;
    }
};

int main() {
    DoublyList dl;
    string s;
    cout << "Enter string: ";
    cin >> s;

    for (char c : s)
        dl.insert(c);

    dl.display();

    if (dl.isPalindrome())
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}
