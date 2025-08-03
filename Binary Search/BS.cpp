#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr) / sizeof(arr[0]);  

    int ele = 5;
    int low = 0, high = n - 1, mid;

    while (low <= high) {
        mid = low + (high - low) / 2;

        if (arr[mid] == ele) {
            cout << "Element found at index: " << mid << endl;
            return 0;
        }
        else if (arr[mid] < ele) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    cout << "Element not found!" << endl;
    return 0;
}
