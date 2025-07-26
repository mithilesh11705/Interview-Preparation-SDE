#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            b[i] = a[i];
        }

        sort(b.begin(), b.end());

        if (k == 1)
        {
            if (a == b)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }
    return 0;
}
