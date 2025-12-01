//sparse matrix
#include <iostream>
using namespace std;

void display(int sparse[][3], int nonZero) {
    cout << "Row\tCol\tValue\n";
    for (int i = 0; i <= nonZero; i++) {
        cout << sparse[i][0] << "\t" << sparse[i][1] << "\t" << sparse[i][2] << "\n";
    }
}

int main() {
    int rows, cols;

    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    int mat[10][10];
    cout << "Enter matrix elements (" << rows << "x" << cols << "):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> mat[i][j];
        }
    }

    // Step 1: Convert to sparse matrix (3-tuple form)
    int sparse[100][3];
    int k = 1; // index for non-zero elements
    sparse[0][0] = rows;
    sparse[0][1] = cols;
    sparse[0][2] = 0; // will hold total non-zero count

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = mat[i][j];
                k++;
            }
        }
    }
    sparse[0][2] = k - 1; // total non-zero count

    cout << "\nSparse Matrix (3-tuple form):\n";
    display(sparse, k - 1);

    // Step 2: Find transpose (swap row & column of each element)
    int trans[100][3];
    trans[0][0] = sparse[0][1];
    trans[0][1] = sparse[0][0];
    trans[0][2] = sparse[0][2];

    int p = 1;
    for (int col = 0; col < cols; col++) {
        for (int i = 1; i <= sparse[0][2]; i++) {
            if (sparse[i][1] == col) {
                trans[p][0] = sparse[i][1];
                trans[p][1] = sparse[i][0];
                trans[p][2] = sparse[i][2];
                p++;
            }
        }
    }

    cout << "\nTranspose Sparse Matrix (3-tuple form):\n";
    display(trans, trans[0][2]);

    return 0;
}