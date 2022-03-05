/*
 * @Author: xinyu Li
 * @Date: 2022-03-05 20:54:06
 * @LastEditTime: 2022-03-05 20:54:07
 * @Description: 
 * @FilePath: \helloworld\PTA\A1157.cpp
 * chaos is a ladder
 */
#include<bits/stdc++.h>
using namespace std;
map<string, int> alumni;
map<string, string> v1, v2;
int n, m;

int main()
{
    cin>>n;
    string id;
    for(int i=0;i<n;i++){
        cin>>id;
        alumni[id] = 1;
    }
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>id;
        string bir;
        bir.assign(id.begin()+7, id.end());
        if(alumni.find(id)!=alumni.end()) {
            v1[bir] = id;
        }
        else v2[bir] = id;
    }
    if(v1.size()){
        cout<<v1.size()<<endl;
        cout<<v1.begin()->second<<endl;
    }else{
        cout<<0<<endl;
        cout<<v2.begin()->second<<endl;
    }
}
