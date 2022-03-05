#include<bits/stdc++.h>
using namespace std;
int N, M, Zero[101] = {0}, h[101] = {0}, l = 0;
vector<int> tree[101];
void DFS(int root, int level)
{
    if(level > l) l = level;
    if(!tree[root].size()) Zero[level]++;
    for(int i=0;i<tree[root].size();i++)
        DFS(tree[root][i], level+1);
}
void BFS(int root)
{
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int now = q.front();
        l = max(l, h[now]);
        q.pop();
        if(!tree[now].size()) Zero[h[now]]++;
        for(int i=0;i<tree[now].size();i++) {h[tree[now][i]] = h[now] + 1;q.push(tree[now][i]);}
    }
}
int main()
{
    cin>>N>>M;
    int k, child, id;
    for(int i=0;i<M;i++){
        cin>>id>>k;
        for(int j=0;j<k;j++){cin>>child;tree[id].push_back(child);}
    }
    //DFS(1, 1);
    h[1] = 1; //根节点编号为1， 根节点位于第1层
    BFS(1);
    for(int i=1;i<=l;i++){
        cout<<Zero[i];
        if(i < l) cout<<" ";
    }
    cout<<endl;
    system("pause");
}

