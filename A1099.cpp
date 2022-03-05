/*
 * @Author: xinyu Li
 * @Date: 2022-03-05 20:50:14
 * @LastEditTime: 2022-03-05 20:50:15
 * @Description: 
 * @FilePath: \helloworld\PTA\A1099.cpp
 * chaos is a ladder
 */
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    int lchild, rchild;
}tree[110];
int N, in[110], cnt = 0;
void inOrder(int root)
{
    if(root == -1) return;
    inOrder(tree[root].lchild);
    tree[root].val = in[cnt++];
    inOrder(tree[root].rchild);
}
void bfs(int root)
{
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int top = q.front();
        q.pop();
        if(top != root)
            cout<<" ";
        cout<<tree[top].val;
        if(tree[top].lchild != -1) q.push(tree[top].lchild);
        if(tree[top].rchild != -1) q.push(tree[top].rchild);
    }
}
int main()
{
    cin>>N;
    int l, r;
    for(int i=0;i<N;i++){
        cin>>l>>r;
        tree[i].lchild = l;
        tree[i].rchild = r;
    }
    for(int i=0;i<N;i++){
        cin>>l;
        in[i] = l;
    }
    sort(in, in+N);
    inOrder(0);
    bfs(0);
    cout<<endl;
}
