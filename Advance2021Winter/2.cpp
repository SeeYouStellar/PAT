/*
 * @Author: xinyu Li
 * @Date: 2022-03-05 20:59:48
 * @LastEditTime: 2022-03-05 20:59:49
 * @Description: 
 * @FilePath: \helloworld\PTA\Advance2021Winter\2.cpp
 * chaos is a ladder
 */
#include<bits/stdc++.h>
using namespace std;
map<int, int> m, mm;
int n;
int in[100010];
int main()
{
    
    int a;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        in[a] = 1;
        m[i] = a;
    }
    int head;
    for(int i=0;i<n;i++)
        if(!in[i]) {
            head = i;
            break;
        }
    int deg = 1;
    while(head!=-1){
        mm[head] = deg;
        head = m[head];
        deg++;
    }
    for(int i=0;i<n;i++){
        cout<<mm[i];
        if(i<n-1)cout<<" ";
    }
    cout<<endl;
}