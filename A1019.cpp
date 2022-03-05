/*
 * @Author: xinyu Li
 * @Date: 2022-03-05 20:44:00
 * @LastEditTime: 2022-03-05 20:44:01
 * @Description: 
 * @FilePath: \helloworld\PTA\A1019.cpp
 * chaos is a ladder
 */
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N, b;
    cin>>N>>b;
    string tmp;
    int ans, tmp3;
    stack<int> s;
    while(N != 0){
        ans = N % b;
        tmp+=ans+'0';
        N/=b;
        s.push(ans);
    }
    string tmp2 = tmp;
    reverse(tmp.begin(), tmp.end());
    if(tmp2 == tmp)
        cout<<"Yes\n";
    else    
        cout<<"No\n";
    tmp3 = s.top();
    s.pop();
    cout<<tmp3;
    while(!s.empty()){
        cout<<" "<<s.top();
        s.pop();
    }
    system("pause");
}