/*
 * @Author: xinyu Li
 * @Date: 2022-03-05 20:48:12
 * @LastEditTime: 2022-03-05 20:48:12
 * @Description: 
 * @FilePath: \helloworld\PTA\A1077.cpp
 * chaos is a ladder
 */
#include<bits/stdc++.h>
using namespace std;
void fun(string& s, string& ss)
{
    reverse(s.begin(), s.end());
    reverse(ss.begin(), ss.end());
    int i=0, j=0;
    while(i<s.length() && j<ss.length() && s[i]==ss[j]){
        i++;
        j++;
    }
    s.assign(s.begin(), s.begin()+i);
    reverse(s.begin(), s.end());
}
int main()
{    
    int n;
    string s, ss;
    cin>>n;
    getchar();
    getline(cin, s);
    for(int i=0;i<n-1;i++){
        getline(cin, ss);
        fun(s, ss);
    }
    if(s=="")cout<<"nai";
    else cout<<s;

    system("pause");
}
