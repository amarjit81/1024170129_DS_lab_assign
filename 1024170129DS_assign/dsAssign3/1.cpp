#include <iostream>
using namespace std;

#define MAX 5   

class Stack {
    int arr[MAX];
    int top;
public:
    Stack() { top = -1; }

    bool isEmpty() { return top == -1; }
    bool isFull()  { return top == MAX - 1; }

    void push(int x) {
        if (isFull())
            cout << "Stack Overflow!"<<endl;
        else
            arr[++top] = x;
    }

    void pop() {
        if (isEmpty())
            cout << "Stack Underflow!\n";
        else
            cout << "Popped: " << arr[top--] << endl;
    }

    void peek() {
        if (isEmpty())
            cout << "Stack is Empty!"<<endl;
        else
            cout << "Top element: " << arr[top] << endl;
    }

    void display() {
        if (isEmpty())
            cout << "Stack is Empty!"<<endl;
        else {
            cout << "Stack elements: ";
            for (int i = top; i >= 0; i--)
                cout << arr[i] << " ";
            cout << endl;
        }
    }
};

int main() {
    Stack st;
    int choice, val;

    do {
        cout <<endl<< " Stack Menu "<<endl;
        cout << "1. Push\n2. Pop\n3. Peek\n4. isEmpty\n5. isFull\n6. Display\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                st.push(val);
                break;
            case 2: st.pop(); break;
            case 3: st.peek(); break;
            case 4: cout << (st.isEmpty() ? "Stack is Empty\n" : "Stack is NOT Empty")<<endl; break;
            case 5: cout << (st.isFull() ? "Stack is Full\n" : "Stack is NOT Full")<<endl; break;
            case 6: st.display(); break;
            case 0: cout << "Exiting..."<<endl; break;
            default: cout << "Invalid choice!"<<endl;
        }
    } while (choice != 0);

    return 0;
}
