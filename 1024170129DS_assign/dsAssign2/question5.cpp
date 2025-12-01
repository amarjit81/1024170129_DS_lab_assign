//special matrices
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


void diagonalMatrix(int n) {
    vector<int> diag(n);
    cout << "Enter " << n << " diagonal elements: ";
    for (int i = 0; i < n; i++) cin >> diag[i];

    cout << "Diagonal Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) cout << diag[i] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }
}


void tridiagonalMatrix(int n) {
    int size = 3*n - 2;
    vector<int> tri(size);
    cout << "Enter " << size << " elements (tridiagonal): ";
    for (int i = 0; i < size; i++) cin >> tri[i];

    cout << "Tridiagonal Matrix:\n";
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (abs(i - j) <= 1) cout << tri[k++] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }
}


void lowerTriangularMatrix(int n) {
    int size = n*(n+1)/2;
    vector<int> lower(size);
    cout << "Enter " << size << " elements (lower triangular): ";
    for (int i = 0; i < size; i++) cin >> lower[i];

    cout << "Lower Triangular Matrix:\n";
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j) cout << lower[k++] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }
}


void upperTriangularMatrix(int n) {
    int size = n*(n+1)/2;
    vector<int> upper(size);
    cout << "Enter " << size << " elements (upper triangular): ";
    for (int i = 0; i < size; i++) cin >> upper[i];

    cout << "Upper Triangular Matrix:\n";
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i <= j) cout << upper[k++] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }
}


void symmetricMatrix(int n) {
    int size = n*(n+1)/2;
    vector<int> sym(size);
    cout << "Enter " << size << " elements (lower triangle): ";
    for (int i = 0; i < size; i++) cin >> sym[i];

    cout << "Symmetric Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j) cout << sym[(i*(i+1))/2 + j] << " ";
            else cout << sym[(j*(j+1))/2 + i] << " ";
        }
        cout << endl;
    }
}


int main() {
    int n, choice;
    cout << "Enter matrix size (n x n): ";
    cin >> n;

    do {
        cout << "\n--- Matrix Storage Menu ---\n";
        cout << "1. Diagonal Matrix\n";
        cout << "2. Tridiagonal Matrix\n";
        cout << "3. Lower Triangular Matrix\n";
        cout << "4. Upper Triangular Matrix\n";
        cout << "5. Symmetric Matrix\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: diagonalMatrix(n); break;
            case 2: tridiagonalMatrix(n); break;
            case 3: lowerTriangularMatrix(n); break;
            case 4: upperTriangularMatrix(n); break;
            case 5: symmetricMatrix(n); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while(choice != 0);

    return 0;
}