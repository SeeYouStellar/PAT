/*
 * @Author: xinyu Li
 * @Date: 2021-10-29 23:04:13
 * @LastEditTime: 2021-10-30 15:47:18
 * @Description: 
 * @FilePath: \helloworld\fuck\Graph\A1021\A1021.cpp
 * I am because you are
 * 
 * 题目要求首先给的图是一棵树，即没有回环且只有一个连通分量
 */
#include<bits/stdc++.h>
using namespace std;
const int maxn = 10010;
int Graph[maxn][maxn] = {0}, N, test[maxn] = {0}, bestd = 0, best = 0, parent[maxn] = {0};
vector<int> G[maxn];
map<int, int> m;
void DFS(int now, int d)
{
    if(d > best) best = d;
    test[now] = 1;
    for(int i=0;i<G[now].size();i++){
        if(!test[G[now][i]]){
            DFS(G[now][i], d+1);
        }
    }
}
int DFStravel()
{   
    int cnt = 0, d = 0;
    for(int i=1;i<=N;i++){
        if(!test[i]){
            DFS(i, d);
            cnt++;
        }
    }
    memset(test, 0, sizeof(int)*maxn);
    d = 0;
    best = 0;
    if(cnt != 1) return cnt;
    for(int i=1;i<=N;i++){
        DFS(i, d);
        if(best > bestd) bestd = best;
        m[i] = best;
        best = 0;
        d = 0;
        memset(test, 0, sizeof(int)*maxn);
    }
    return cnt;
}
// int find(int now)
// {
//     if(now != parent[now]) parent[now] = find(now);
//     return parent[now];
// }
// void unit(int a, int b)
// {
//     int fa = find(a);
//     int fb = find(b);
//     if(fa != fb) parent[a] = fb;
// }
int main()
{
    cin>>N;
    int a, b;
    for(int i=0;i<N-1;i++){
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int n = DFStravel();
    if(n == 1){
        for(map<int, int>::iterator it=m.begin();it!=m.end();it++){
            if(it->second == bestd) cout<<it->first<<endl;
        }
    }else
        cout<<"Error: "<<n<<" components\n";
    system("pause");
}