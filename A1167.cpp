/*
 * @Author: xinyu Li
 * @Date: 2022-03-05 20:55:58
 * @LastEditTime: 2022-03-05 20:55:59
 * @Description: 
 * @FilePath: \helloworld\PTA\A1167.cpp
 * chaos is a ladder
 */
#include <bits/stdc++.h>
using namespace std;
const int INF = 10000000;
const int maxn = 50;

struct node{
    int val;
    node* lchild;
    node* rchild;
};
int in[maxn], n;
node* buildtree(int l, int r)
{
    if(l>r) return NULL;
    int MIN = INF, root = -1;
    for(int i=l;i<=r;i++){
        if(MIN>in[i]){
            MIN = in[i];
            root = i;
        }
    }
    node *ROOT = new node();
    ROOT->val = in[root];
    ROOT->lchild = buildtree(l, root-1);
    ROOT->rchild = buildtree(root+1, r);
    return ROOT;
}
void bfs(node* root)
{
    queue<node*> q;
    q.push(root);
    int cnt=0;
    while(!q.empty()){
        node* top = q.front();
        q.pop();
        cnt++;
        cout<<top->val;
        if(cnt<n) cout<<" ";
        if(top->lchild!=NULL) q.push(top->lchild);
        if(top->rchild!=NULL) q.push(top->rchild);
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>in[i];
    }
    node* root = buildtree(0, n-1);
    bfs(root);
    cout<<endl;
}
