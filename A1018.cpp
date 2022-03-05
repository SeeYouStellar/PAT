/*
 * @Author: xinyu Li
 * @Date: 2022-03-05 20:43:40
 * @LastEditTime: 2022-03-05 20:43:40
 * @Description: 
 * @FilePath: \helloworld\PTA\A1018.cpp
 * chaos is a ladder
 */

#include<bits/stdc++.h>
using namespace std;
const int maxn = 510;
const int INF = 100000;
int Cmax, N, sp, M, bestn = INF, bestb = INF;  //最大容量 站数量 问题站 边数 最少带去 带回
int Cap[maxn], G[maxn][maxn], d[maxn], vis[maxn];
vector<int> Prev[maxn];
void Dijkstra(int s)
{
    fill(d, d+maxn, INF);
    d[s] = 0;
    for(int i=0;i<=N;i++){
        int u = -1, tmp = INF;
        for(int j=0;j<=N;j++)
            if(!vis[j] && tmp > d[j]){tmp = d[j];u = j;}
        if(u == -1) return;
        vis[u] = 1;
        for(int j=0;j<=N;j++){
            if(!vis[j] && G[u][j] != INF){
                if(d[j] > d[u] + G[u][j]){
                    d[j] = d[u] + G[u][j];
                    Prev[j].clear();
                    Prev[j].push_back(u);
                }else if(d[j] == d[u] + G[u][j])
                    Prev[j].push_back(u);
            }
        }
    }
}
vector<int> path, ans;
void dfs(int root)
{
    if(root == 0){
        int need = 0, back = 0;
        for(int i=path.size()-1;i>=0;i--){
            int id = path[i];
            if(Cap[id]>0){
                back+=Cap[id];
            }else{
                if(back < abs(Cap[id])){
                    need += abs(Cap[id])-back;
                    back = 0;
                    
                }else{
                    back -= abs(Cap[id]);
                }
            }
        }
        if(need<bestn){
            bestn = need;
            bestb = back;
            ans = path;
        }else if(need == bestn && bestb > back){
            bestb = back;
            ans = path;
        }
        
        return;
    }
    path.push_back(root);
    for(int i=0;i<Prev[root].size();i++){
        
        dfs(Prev[root][i]);
        
    }
    path.pop_back();
}

int main()
{
    cin>>Cmax>>N>>sp>>M;
    Cmax /= 2;
    for(int i=1;i<=N;i++) {cin>>Cap[i];Cap[i] -= Cmax;}
    fill(G[0], G[0]+maxn*maxn, INF);
    for(int i=0;i<M;i++){
        int a, b;
        cin>>a>>b;
        cin>>G[a][b];
        G[b][a] = G[a][b];
    }
    Dijkstra(0);
    dfs(sp);
    cout<<bestn<<" "<<"0";
    for(int i=ans.size()-1;i>=0;i--){
        cout<<"->"<<ans[i];
    }
    cout<<" "<<bestb<<endl;
    system("pause");
}
