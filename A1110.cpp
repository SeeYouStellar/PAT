/*
 * @Author: xinyu Li
 * @Date: 2022-03-05 20:50:46
 * @LastEditTime: 2022-03-05 20:50:46
 * @Description: 
 * @FilePath: \helloworld\PTA\A1110.cpp
 * chaos is a ladder
 */
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int lchild, rchild;
}tree[100];
int N, in[100], R, CBT[100];
int inorder(int root, int i)
{
    if((root == -1 && i <= N) || (root != -1 && i > N)) return 0;
    CBT[i] = root;
    if(root == -1 && i > N) return 1;
    int l = inorder(tree[root].lchild, i*2);
    int r = inorder(tree[root].rchild, i*2+1);
    if(!l || !r)
        return 0;
    else
        return 1;
}

int main()
{
    cin>>N;
    string l, r;
    memset(in, 0, sizeof(in));
    for(int i=0;i<N;i++){
        cin>>l>>r;
        if(l != "-"){
            tree[i].lchild = stoi(l);
            in[stoi(l)]++;
        }else
            tree[i].lchild = -1;
        if(r != "-"){
            tree[i].rchild = stoi(r);
            in[stoi(r)]++;
        }else 
            tree[i].rchild = -1;
    }
    for(int i=0;i<N;i++){
        if(!in[i]){
            R = i;
            break;
        }
    }
    int ans = inorder(R, 1);
    if(ans)
        cout<<"YES "<<CBT[N]<<endl;
    else
        cout<<"NO "<<R<<endl;
}