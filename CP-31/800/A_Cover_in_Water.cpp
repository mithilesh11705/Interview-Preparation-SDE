#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;

        int k=0;int su=0;
        for(char c:s)
        {
            if(c=='.')
            {
                k++;
            }
            else{
            if(k>2){
                break;
            }
            else{
            su+=k;
            k=0;
            }
        }
    }
        if(k>2){
            cout<<2<<endl;
        }
        else{
            cout<<su+k<<endl;
        }
}
    return 0;
}