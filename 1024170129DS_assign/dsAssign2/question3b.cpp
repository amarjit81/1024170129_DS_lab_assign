#include <iostream>
using namespace std;

int findMissingNumber(int arr[], int n) {
    int start = 0, end = n - 2; 

    while (start <= end) {
        int mid = (start + end) / 2;

        if (arr[mid] == mid + 1)
            start = mid + 1;   
        else
            end = mid - 1;     
    }

    return start + 1; 
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    int arr[n - 1];
    cout << "Enter " << n - 1 << " sorted elements (from 1 to " << n << "): ";
    for (int i = 0; i < n - 1; i++)
        cin >> arr[i];

    cout << "Missing number is: " << findMissingNumber(arr, n) << endl;

    return 0;
}
