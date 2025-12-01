
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter sorted elements :"<<endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int expected_sum = n * (n + 1) / 2;
    int actual_sum = 0;
    for (int i = 0; i < n; i++) {
        actual_sum += arr[i];
    }
    int missing = expected_sum - actual_sum;
 cout << "The missing number is: " << missing << endl;

    return 0;
}