/*
 * @Author: xinyu Li
 * @Date: 2022-03-05 20:47:23
 * @LastEditTime: 2022-03-05 20:47:23
 * @Description: 
 * @FilePath: \helloworld\PTA\A1072.cpp
 * chaos is a ladder
 */
#include<bits/stdc++.h>
using namespace std;
const int maxn = 2000;
const int INF = 100000000;
string bestdic;
int N, M, K, T, gas;
int graph[maxn][maxn], vis[maxn], d[maxn], Prev[maxn];
vector<int> tmp, ans;
void dijkstra(int s)
{
    memset(vis, 0, sizeof(vis));
    fill(d, d+maxn, INF);
    d[s] = 0;
    for(int i=0;i<N+M;i++){
        int min = INF, u = -1;
        for(int j=1;j<=N+M;j++){
            if(min > d[j] && !vis[j]){min = d[j];u = j;}
        }
        if(u == -1) return;
        vis[u] = 1;
        for(int j=1;j<=N+M;j++){
            if(graph[u][j]!=INF && !vis[j]){
                if(graph[u][j]+d[u]<d[j] && graph[u][j]+d[u]<=T){
                    d[j] = graph[u][j]+d[u];
                    Prev[j] = u;
                }
            }
        }
    }
}

int main()
{
    cin>>N>>M>>K>>T;
    string a, b;
    int c;
    fill(graph[0], graph[0]+maxn*maxn, INF);
    for(int i=0;i<K;i++){
        int aa, bb;
        cin>>a>>b>>c;
        if(a[0] == 'G') aa = N+stoi(&a[1]);
        else aa = stoi(a);
        if(b[0] == 'G') bb = N+stoi(&b[1]);
        else bb = stoi(b);
        graph[aa][bb] = graph[bb][aa] = c;
    }
    double mind = -1, minsum = INF;
    int mingas = -1;
    for(int i=1;i<=M;i++){
        gas = N+i;
        dijkstra(gas);
        double sum = 0, dd = INF;
        for(int j=1;j<=N;j++){
            if(d[j]>T) {dd = -1;continue;}
            sum+=1.0*d[j]/N;
            if(dd > d[j]) dd=d[j];
        }
        if(dd == -1) continue;
        if(dd > mind){
            mind = dd;
            minsum = sum;
            mingas = i;
        }else if(dd == mind && sum < minsum){
            minsum = sum;
            mingas = i;
        }
    }
    if(mingas == -1){
        cout<<"No Solution\n";
    }else{
        printf("G%d\n", mingas);
        printf("%.1f %.1f", mind, minsum);
    }
}
