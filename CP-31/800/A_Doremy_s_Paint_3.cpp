#include <bits/stdc++.h>
using namespace std;
  

int main() {
     int t; // Number of test cases
    cin >> t;

    while (t--) {
       int n; // Length of the array
       cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // Sort the array
        sort(a.begin(), a.end());

        // Check if sum of smallest two elements equals sum of largest two elements
        if (a[0] + a[1] == a[n - 1] + a[n - 2]) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
