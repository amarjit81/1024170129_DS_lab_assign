// Implement Heapsort (Increasing/Decreasing order).

#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i, bool ascending) {
    int extreme = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (ascending) {
        if (l < n && arr[l] > arr[extreme]) extreme = l;
        if (r < n && arr[r] > arr[extreme]) extreme = r;
    } else {
        if (l < n && arr[l] < arr[extreme]) extreme = l;
        if (r < n && arr[r] < arr[extreme]) extreme = r;
    }

    if (extreme != i) {
        swap(arr[i], arr[extreme]);
        heapify(arr, n, extreme, ascending);
    }
}

void heapSort(int arr[], int n, bool ascending=true) {
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i, ascending);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, ascending);
    }
}

int main() {
    int arr[] = {4, 10, 3, 5, 1};
    int n = 5;

    heapSort(arr, n, true); // ascending

    cout << "Sorted: ";
    for (int x : arr) cout << x << " ";
}