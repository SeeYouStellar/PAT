/*
 * @Author: xinyu Li
 * @Date: 2022-03-05 20:55:31
 * @LastEditTime: 2022-03-05 20:55:31
 * @Description: 
 * @FilePath: \helloworld\PTA\A1165.cpp
 * chaos is a ladder
 */
/*
 * @Author: xinyu Li
 * @Date: 2022-03-02 20:06:46
 * @LastEditTime: 2022-03-04 09:44:35
 * @Description: 
 * @FilePath: \helloworld\8.cpp
 * chaos is a ladder
 */
#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int head, n, k, da[maxn], ne[maxn], addr[maxn];
int main()
{
    cin>>head>>n>>k;
    for(int i=0;i<n;i++){
        int addr;
        cin>>addr;
        cin>>da[addr]>>ne[addr];
    }
    vector<pair<int, int>> v;
    vector<int> h;
    int cnt = 0;
    while(head!=-1){
        if(cnt%k==0) h.push_back(cnt);
        v.push_back(make_pair(head, da[head]));
        head = ne[head];
        cnt++;
    }
    int last = v.size()%k;
    reverse(h.begin(), h.end());
    for(int i=0;i<h.size();i++){
        int index = h[i];
        if(i==h.size()-1){
            if(i==0&&last)k=last;
            for(int j=0;j<k;j++){
                if(j<k-1)
                    printf("%05d %d %05d\n", v[index+j].first, v[index+j].second, v[index+1+j].first);
                else
                    printf("%05d %d -1\n", v[index+j].first, v[index+j].second);
            }
            continue;
        }
        if(last && !i){
            for(int j=0;j<last;j++){
                if(j<last-1)
                    printf("%05d %d %05d\n", v[index+j].first, v[index+j].second, v[index+1+j].first);
                else
                    printf("%05d %d %05d\n", v[index+j].first, v[index+j].second, v[h[i+1]].first);
            }
            continue;
        }
        for(int j=0;j<k;j++){
            if(j<k-1)
                printf("%05d %d %05d\n", v[index+j].first, v[index+j].second, v[index+1+j].first);
            else
                printf("%05d %d %05d\n", v[index+j].first, v[index+j].second, v[h[i+1]].first);
        }
    }
}   