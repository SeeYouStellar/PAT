/*
 * @Author: xinyu Li
 * @Date: 2022-03-05 20:55:11
 * @LastEditTime: 2022-03-05 20:55:11
 * @Description: 
 * @FilePath: \helloworld\PTA\A1163.cpp
 * chaos is a ladder
 */
#include<bits/stdc++.h>
using namespace std;
struct node{
    string val;
    int issub;
    int lchild;
    int rchild;
}tree[30];
int N, in[30];
void dfs(int root)
{
    if(root == -1)return;
    cout<<"(";
    if((tree[root].lchild == -1 && tree[root].rchild != -1) || (tree[root].rchild == -1 && tree[root].lchild != -1))
        cout<<tree[root].val;
    dfs(tree[root].lchild);
    dfs(tree[root].rchild);
    if(!(tree[root].lchild == -1 && tree[root].rchild != -1) && !(tree[root].rchild == -1 && tree[root].lchild != -1)) 
        cout<<tree[root].val;
    cout<<")";
}
int main()
{
    cin>>N;
    string val, l, r;
    for(int i=1;i<=N;i++){
        cin>>val>>l>>r;
        if(val == "-") tree[i].issub = 1;
        tree[i].val = val;
        tree[i].lchild = stoi(l);
        tree[i].rchild = stoi(r);
        if(tree[i].lchild!=-1) in[tree[i].lchild]++;
        if(tree[i].rchild!=-1) in[tree[i].rchild]++;
    }
    int root = -1;
    for(int i=1;i<=N;i++)
        if(in[i]==0){
            root = i;
            break;
        }
    dfs(root);
    cout<<endl;
}