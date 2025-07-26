#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;

        vector<int> a;
        a.push_back(0); // starting point

        for (int i = 0; i < n; i++)
        {
            int p;
            cin >> p;
            a.push_back(p);
        }

        a.push_back(x); // ending point

        sort(a.begin(), a.end()); // sort the positions

        int max_dis = 0;
        for (int i = 1; i < a.size(); i++)
        {
            // Special case for the last interval: double the gap
            if (i == a.size() - 1)
                max_dis = max(max_dis, 2 * (a[i] - a[i - 1]));
            else
                max_dis = max(max_dis, a[i] - a[i - 1]);
        }

        cout << max_dis << endl;
    }
    return 0;
}
