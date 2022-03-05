/*
 * @Author: xinyu Li
 * @Date: 2022-03-05 20:51:03
 * @LastEditTime: 2022-03-05 20:51:04
 * @Description: 
 * @FilePath: \helloworld\PTA\A1113.cpp
 * chaos is a ladder
 */
#include <bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    int lchild, rchild;
    int step;
}tree[1100];
int index_ = 0, N, depth[1100];
int newnode(int val)
{
    int root = index_;
    tree[root].val = val;
    tree[root].lchild = -1;
    tree[root].rchild = -1;
    tree[root].step = 1;
    index_++;
    return root;
}
void insert(int& root, int val)
{
    if(root == -1){
        root = newnode(val);
        return ;
    }
    if(tree[root].val >= val)
        insert(tree[root].lchild, val);
    else
        insert(tree[root].rchild, val);
}
void bfs(int root)
{
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int top = q.front();
        q.pop();
        if(tree[top].lchild != -1){
            q.push(tree[top].lchild);
            tree[tree[top].lchild].step = tree[top].step + 1;
        }
        if(tree[top].rchild != -1){
            q.push(tree[top].rchild);
            tree[tree[top].rchild].step = tree[top].step + 1;
        }
    }
}
int main()
{
    cin>>N;
    int a;
    int root = -1;
    for(int i=0;i<N;i++){
        cin>>a;
        insert(root, a);
    }
    bfs(root);
    int maxd = 1;
    for(int i=0;i<N;i++){
        depth[tree[i].step]++;
        if(tree[i].step > maxd) maxd = tree[i].step;
    }
    cout<<depth[maxd]<<" + "<<depth[maxd-1]<<" = "<<depth[maxd]+depth[maxd-1]<<endl;
}