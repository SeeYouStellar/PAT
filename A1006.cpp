#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string name[n];
    string signin[n];
    string signout[n];
    
    for(int i=0;i<n;i++){
        cin>>name[i]>>signin[i]>>signout[i];
    }
    string max = signout[0], min = signin[0];
    string maxname = name[0], minname = name[0];
    for(int i=0;i<n;i++){
        if(signin[i]<min){
            min = signin[i];
            minname = name[i];
        }
        if(signout[i]>max){
            max = signout[i];
            maxname = name[i];
        }
    }
    cout<<minname<<" "<<maxname;
}