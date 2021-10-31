/*
 * @Author: xinyu Li
 * @Date: 2021-10-30 16:15:16
 * @LastEditTime: 2021-10-30 23:56:03
 * @Description: 
 * @FilePath: \helloworld\PTA\A1076.cpp
 * I am because you are
 */
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int test[maxn] = {0}, N, K, L;
struct node{
    int id;
    int level;
};
vector<int> G[maxn];
// void DFS(int now, int l)
// {
//     test[now] = 1;
//     cnt++;
//     if(l == L) return;
//     for(int i=0;i<G[now].size();i++){
//         if(!test[G[now][i]]){
//             DFS(G[now][i], l+1);  
//         }
//     }   
// }
// void DFStravel(int K)
// {
//     for(int i=0;i<K;i++){
//         cin>>a;
//         int l = 0;
//         DFS(a, l);
//         cout<<cnt-1<<endl;
//         cnt = 0;
//         memset(test, 0, sizeof(int)*maxn);
//     }
// }
/*
5 3
0
1 1
1 2
2 1 3
1 4
1 1

7 3
3 2 3 4
0
2 5 6
2 3 1
2 3 4
1 4
1 5
1 6
*/
void BFS(int K)
{   
    int a;
    for(int i=0;i<K;i++){
        cin>>a;
        queue<node> q;
        q.push(node{a, 0});
        test[a] = 1;
        int cnt = 0;
        while(!q.empty()){
            node top = q.front();
            q.pop();
            cnt++;  //被访问的数量
            if(top.level == L) continue;
            for(int j=0;j<G[top.id].size();j++){
                if(!test[G[top.id][j]]){ 
                    q.push(node{G[top.id][j], top.level+1});
                    test[G[top.id][j]] = 1;
                }
            }
        }
        memset(test, 0, sizeof(int)*(N+1)); //very important 要么直接sizeof(test)，要么用sizeof(int)*(N+1)，不是*N，因为数组到N+1都是有意义的
        cout<<cnt-1<<endl;
    }
}
int main()
{
    cin>>N>>L;
    int n, a;
    for(int i=1;i<=N;i++){
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>a;
            G[a].push_back(i);
        }
    }
    cin>>K;
    BFS(K);
    system("pause");
}