/*
 * @Author: xinyu Li
 * @Date: 2021-10-31 11:48:50
 * @LastEditTime: 2021-10-31 15:40:54
 * @Description: 
 * @FilePath: \helloworld\fuck\Graph\A1013.cpp
 * I am because you are
 * 
 * 
 * n个连通分量，要构成连通图则至少用n-1条边连起来
 */
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int N, M, K, Graph[maxn][maxn] = {0}, test[maxn] = {0};
void DFS(int now, int c)
{
    if(now == c) return ;   //若扩展到c则自动返回，因为题意为c自身形成一个连通分量，与其他任意点都是不连通的
    test[now] = 1;
    for(int i=1;i<=N;i++){
        if(!test[i] && Graph[now][i] == 1) 
            DFS(i, c);
    }
}
int DFStravel(int c)
{
    int cnt = 0;
    for(int i=1;i<=N;i++){
        if(!test[i] && i != c){  //不用计c这个连通分量，因为题意为计算删除c后的图的连通分量个数
            DFS(i, c);
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    int S, D, concern;
    cin>>N>>M>>K;
    for(int i=0;i<M;i++){
        cin>>S>>D;
        Graph[S][D] = 1;
        Graph[D][S] = 1;
    }
    for(int i=0;i<K;i++){
        cin>>concern;
        int cnt = DFStravel(concern);
        memset(test, 0, sizeof(int)*(N+1));
        cout<<cnt-1<<endl;
    }
    system("pause");
}
