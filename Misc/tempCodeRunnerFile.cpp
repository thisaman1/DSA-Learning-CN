#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long int a,b,c;
        cin>>a>>b>>c;
        if(a==b&&b==c)
            cout<<"1"<<" "<<"1"<<" "<<"1"<<endl;
        else if(a>b&&a>c)
            cout<<"0"<<" "<<a-b+1<<" "<<a-c+1<<endl;
        else if(b>c&&b>a)
            cout<<b-a+1<<" "<<"0"<<" "<<b-c+1<<endl;
        else
            cout<<c-a+1<<" "<<c-b+1<<" "<<"0"<<endl;
    }
    return 0;
}