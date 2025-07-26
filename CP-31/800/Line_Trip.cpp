#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        vector<int>a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
       int d=a[0];
       for(int i=1;i<n;i++)
       {
        int k=a[i]-a[i-1];
        d=max(d,k);
       }
       int d4=2*(x-a[n-1]);
       d=max(d,d4);
       cout<<d4<<endl;
    }
    return 0;
}