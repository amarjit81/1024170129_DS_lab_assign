#include <iostream>
#include <stack>
using namespace std;

string reverseUsingStack(string str) {
    stack<char> s;

    
    for (char c : str)
        s.push(c);

    
    string reversed = "";
    while (!s.empty()) {
        reversed += s.top();
        s.pop();
    }

    return reversed;
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    string reversed = reverseUsingStack(str);
    cout << "Reversed string: " << reversed << endl;

    return 0;
}
