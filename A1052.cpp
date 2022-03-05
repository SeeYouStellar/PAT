/*
 * @Author: xinyu Li
 * @Date: 2022-03-05 20:45:58
 * @LastEditTime: 2022-03-05 20:46:05
 * @Description: 
 * @FilePath: \helloworld\PTA\A1052.cpp
 * chaos is a ladder
 */
#include<bits/stdc++.h>
using namespace std;
const int maxn = 110000;
int val[maxn], nex[maxn], n, head;
bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}
int main()
{
    cin>>n>>head;
    for(int i=0;i<n;i++){
        int addr;
        cin>>addr;
        cin>>val[addr]>>nex[addr];
    }
    if(head == -1){
        printf("0 -1\n");
        return 0;
    }
    vector<pair<int, int>> v;
    while(head!=-1){
        v.push_back(make_pair(head, val[head]));
        head = nex[head];
    }
    
    sort(v.begin(), v.end(), cmp);
    printf("%d %05d\n", v.size(), v[0].first);
    for(int i=0;i<v.size();i++){
        if(i == v.size()-1)printf("%05d %d -1\n", v[i].first, v[i].second);
        else printf("%05d %d %05d\n", v[i].first, v[i].second, v[i+1].first);
    }
}