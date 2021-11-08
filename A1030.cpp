/*
 * @Author: xinyu Li
 * @Date: 2021-11-07 23:32:31
 * @LastEditTime: 2021-11-07 23:32:38
 * @Description: 
 * @FilePath: \helloworld\PTA\A1030.cpp
 * I am because you are
 */

#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000;
const int INF = 1000;
int vis[maxn], G[maxn][maxn], d[maxn], C[maxn][maxn], c[maxn], Prev[maxn];
int N, M, S, D;
void Dijkstra(int s)
{
    fill(d, d+maxn, INF);
    fill(c, c+maxn, INF);
    d[s] = 0;
    c[s] = 0;
    for(int i=0;i<N;i++){
        int u = -1, tmp = INF;
        for(int j=0;j<N;j++)
            if(!vis[j] && d[j] < tmp){
                u = j;  
                tmp = d[j];
            }
        if(u == -1) return; 
        vis[u] = 1;
        for(int j=0;j<N;j++){
            if(!vis[j] && G[u][j] != INF){
                if(d[j] > d[u] + G[u][j]){
                    d[j] = d[u] + G[u][j];
                    c[j] = c[u] + C[u][j];
                    Prev[j] = u;
                }else if(d[j] == d[u] + G[u][j] && c[j] > c[u] + C[u][j]){
                    c[j] = c[u] + C[u][j];
                    Prev[j] = u;
                }
            }
        }
    }
}
int main()
{
    cin>>N>>M>>S>>D;
    fill(G[0], G[0]+maxn*maxn, INF);
    fill(C[0], C[0]+maxn*maxn, INF);
    for(int i=0;i<M;i++){
        int a, b;
        cin>>a>>b;
        cin>>G[a][b]>>C[a][b];
        G[b][a] = G[a][b];
        C[b][a] = C[a][b];
    }
    Dijkstra(S);
    vector<int> v;
    int tmp = Prev[D];
    v.push_back(D);
    while(tmp != S){
        v.push_back(tmp);
        tmp = Prev[tmp];
    }   
    v.push_back(S);
    for(int i=v.size()-1;i>=0;i--)
        cout<<v[i]<<" ";
    cout<<d[D]<<" "<<c[D]<<endl;
    system("pause");
}

