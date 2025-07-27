#include <bits/stdc++.h>
using namespace std;
 int main()
{
int t;
cin >> t;
while (t--) {
        int n;
        cin>>n;
        vector<int> a;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            a.push_back(x);
        }
        if(a[0] == 1)
        {
            cout << "YES" << endl;
        }
        else
        cout<<"NO" << endl;
}
 return 0;
}   