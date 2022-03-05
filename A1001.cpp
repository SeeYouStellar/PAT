#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a, b, c;
    cin>>a>>b;
    c = a + b;
    if(c < 0){
        cout<<"-";
        c = -c;
    }
    int tmp[10] = {0}, i = 0;
    while(c!=0){
        tmp[i++] = c % 10;
        c /= 10;
    }
    for(int j=i-1;j>=0;j--){
        cout<<tmp[j];
        if(j%3 == 0 && j>0) cout<<",";
    }
    if(!i) cout<<0;
}