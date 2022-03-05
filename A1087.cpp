/*
 * @Author: xinyu Li
 * @Date: 2022-03-05 20:49:09
 * @LastEditTime: 2022-03-05 20:49:09
 * @Description: 
 * @FilePath: \helloworld\PTA\A1087.cpp
 * chaos is a ladder
 */
#include<bits/stdc++.h>
using namespace std;
const int maxn = 210;
const int INF = 10000000;
map<string, int> m;
map<int, string> mm;
int N, M, happiness[maxn], graph[maxn][maxn], c[maxn], vis[maxn], num[maxn], maxhapavg, maxhapsum;
string S;
vector<int> Prev[maxn], tmp, ans;
int index_ = 0;
int getid(string city)
{
    if(m.find(city) != m.end()){
        return m[city];
    }else{
        int id = index_++;
        m[city] = id;
        mm[id] = city;
        return id;
    }
}
void dijkstra(int s)
{
    fill(c, c+maxn, INF);
    c[s] = 0;
    num[s] = 1;
    for(int i=0;i<N;i++){
        int min = INF, u = -1;
        for(int j=0;j<N;j++){
            if(min > c[j] && !vis[j]){
                min = c[j];
                u = j;
            }
        }
        if(u == -1) return;
        vis[u] = 1;
        for(int j=0;j<N;j++){
            if(graph[u][j]!=INF && !vis[j]){
                if(c[j]>c[u]+graph[u][j]){
                    c[j] = c[u]+graph[u][j];
                    Prev[j].clear();
                    Prev[j].push_back(u);
                    num[j] = num[u];
                }else if(c[j]==c[u]+graph[u][j]){
                    Prev[j].push_back(u);
                    num[j]+=num[u];
                }
            }
        }
    }
}
void dfs(int city)
{
    if(city == getid(S)){
        tmp.push_back(city);
        int hapsum = 0, hapavg;
        for(int i=0;i<tmp.size();i++){
            hapsum+=happiness[tmp[i]];
        }
        hapavg = hapsum/(tmp.size()-1);
        if(hapsum > maxhapsum){
            maxhapsum = hapsum;
            maxhapavg = hapavg;
            ans = tmp;
        }else if(hapavg > maxhapavg){
            maxhapavg = hapavg;
            ans = tmp;
        }
        tmp.pop_back();
        return;
    }   
    tmp.push_back(city);
    for(int i=0;i<Prev[city].size();i++) dfs(Prev[city][i]);
    tmp.pop_back();
}

int main()
{
    cin>>N>>M>>S;
    happiness[getid(S)] = 0;
    for(int i=0;i<N-1;i++){
        string city;
        int hap;
        cin>>city>>hap;
        int id = getid(city);
        happiness[id] = hap;
    }
    fill(graph[0], graph[0]+maxn*maxn, INF);
    for(int i=0;i<M;i++){
        string city1, city2;
        int cost;
        cin>>city1>>city2>>cost;
        graph[getid(city1)][getid(city2)] = cost;
        graph[getid(city2)][getid(city1)] = cost;
    }
    dijkstra(getid(S));
    int rom = getid("ROM");
    dfs(rom);
    cout<<num[rom]<<" "<<c[rom]<<" "<<maxhapsum<<" "<<maxhapavg<<endl;
    cout<<S;
    for(int i=ans.size()-2;i>=0;i--)cout<<"->"<<mm[ans[i]];
    
    cout<<endl;
    system("pause");
}