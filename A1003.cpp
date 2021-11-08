/*
 * @Author: xinyu Li
 * @Date: 2021-11-07 21:50:42
 * @LastEditTime: 2021-11-07 23:34:45
 * @Description: 
 * @FilePath: \helloworld\PTA\A1003.cpp
 * I am because you are
 */
/*
 * @Author: xinyu Li
 * @Date: 2021-11-07 20:32:57
 * @LastEditTime: 2021-11-07 21:49:11
 * @Description: 
 * @FilePath: \helloworld\fuck\Graph\Dijkstra\A1030.cpp
 * I am because you are
 */
#include<bits/stdc++.h>
using namespace std;
int vis[510], G[510][510], d[510], C[510][510], c[510], Prev[510];
int N, M, S, D;
void Dijkstra(int s)
{
    fill(d, d+510, 1000);
    fill(c, c+510, 1000);
    d[s] = 0;
    c[s] = 0;
    for(int i=0;i<N;i++){
        int u = -1, tmp = 1000;
        for(int j=0;j<N;j++)
            if(!vis[j] && d[j] < tmp){
                u = j;  
                tmp = d[j];
            }   
        if(u == -1) return; 
        vis[u] = 1;
        for(int j=0;j<N;j++){
            if(!vis[j] && G[u][j] != 1000){
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
    fill(G[0], G[0]+510*510, 1000);
    fill(C[0], C[0]+510*510, 1000);
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
    for(int i=v.size()-1;i>=0;i--)
        cout<<v[i];
    cout<<d[D]<<" "<<c[D];
    system("pause");
}

