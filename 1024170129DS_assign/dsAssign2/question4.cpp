//string question
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void concatenate() {
    string str1, str2;
    cout << "Enter first string: ";
    getline(cin, str1);
    cout << "Enter second string: ";
    getline(cin, str2);
    cout << "Concatenated String: " << str1 + str2 << endl;
}

void reverseString() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    reverse(str.begin(), str.end());
    cout << "Reversed String: " << str << endl;
}

void deleteVowels() {
    string str, result = "";
    cin.ignore();
    cout << "Enter a string: ";
    getline(cin, str);
    for (char c : str) {
        if (c!='a' && c!='e' && c!='i' && c!='o' && c!='u' &&
            c!='A' && c!='E' && c!='I' && c!='O' && c!='U') {
            result += c;
        }
    }
    cout << "String without vowels: " << result << endl;
}

void sortStringChars() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    sort(str.begin(), str.end());
    cout << "String with characters sorted: " << str << endl;
}

void upperToLower() {
    char ch;
    cout << "Enter an uppercase character: ";
    cin >> ch;
    if (ch >= 'A' && ch <= 'Z') {
        ch = ch + 32;  
    }
    cout << "Lowercase character: " << ch << endl;
}

int main() {
    int choice;
    do {
        cout << "\n--- String Operations Menu ---\n";
        cout << "1. Concatenate two strings\n";
        cout << "2. Reverse a string\n";
        cout << "3. Delete vowels from a string\n";
        cout << "4. Sort characters in a string\n";  
        cout << "5. Convert uppercase to lowercase\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: concatenate(); break;
            case 2: reverseString(); break;
            case 3: deleteVowels(); break;
            case 4: sortStringChars(); break; 
            case 5: upperToLower(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while(choice != 0);

    return 0;
}
