#include<bits/stdc++.h>
using namespace std;
string ans[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
int main()
{
    int sum = 0;
    string ss;
    cin>>ss;
    for(int i=0;i<ss.length();i++)
        sum += ss[i] - '0';
        
    stack<int> s;
    do{ 
        s.push(sum % 10);
        sum /= 10;
    }while(sum != 0);
    cout<<ans[s.top()];
    s.pop();
    while(!s.empty()){
        cout<<" "<<ans[s.top()];
        s.pop();
    }
    system("pause");
}