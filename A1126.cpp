/*
 * @Author: xinyu Li
 * @Date: 2022-03-05 20:52:14
 * @LastEditTime: 2022-03-05 20:52:14
 * @Description: 
 * @FilePath: \helloworld\PTA\A1126.cpp
 * chaos is a ladder
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 510;
int graph[maxn][maxn], n, m, degree[maxn], vis[maxn], num = 0;
void dfs(int root)
{
    vis[root] = 1;
    num++;
    for(int i=1;i<=n;i++){
        if(!vis[i] && graph[root][i] == 1)
            dfs(i);
    }
}
int main()
{
    cin>>n>>m;
    int a, b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        graph[a][b] = graph[b][a] = 1;
        degree[a]++;
        degree[b]++;
    }
    int flag = 1, cnt = 0;
    for(int i=1;i<=n;i++){
        cout<<degree[i];
        if(i!=n) cout<<" ";
        if(degree[i]%2!=0) {flag = 0;cnt++;}
    }
    cout<<endl;
    dfs(1);
    if(num!=n) cout<<"Non-Eulerian\n";
    else if(flag == 1) cout<<"Eulerian\n";
    else if(cnt == 2) cout<<"Semi-Eulerian\n";
    else cout<<"Non-Eulerian\n";
}
