//从中序遍历和前序（或后序）遍历序列中得出整棵二叉树，并输出层序序列
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* lchild;
    node* rchild;
};
int post[30], in[30], N;
node* create(int inl, int inr, int postl, int postr){
    if(postl > postr) return NULL;
    node* root = new node();
    root->data = post[postr];
    int i, numleft;
    for(i=inl;i<=inr;i++)
        if(in[i] == root->data)
            break;
    numleft = i - inl; 
    root->lchild = create(inl, i-1, postl, postl+numleft-1);
    root->rchild = create(i+1, inr, postl+numleft, postr-1);
    return root;
}
void BFS(node* root) //输出层序序列
{
    queue<node*> q;
    q.push(root);
    int count = 0;
    while(!q.empty()){
        node* top = q.front();
        q.pop();
        cout<<top->data;
        count++;
        if(count < N)
            cout<<" ";
        if(top->lchild) {q.push(top->lchild);}
        if(top->rchild) {q.push(top->rchild);}
        // if(top->lchild) {q.push(top->lchild);count++;}
        // if(top->rchild) {q.push(top->rchild);count++;}
        /*
        tip:
        这里不能这么写：if(top->rchild) {q.push(top->rchild);count++;} 
        这种写法是在节点入队时计数（已遍历的节点数目），
        首先这种写法count初值应为1，因为根节点在循环外已经入队，
        再者单纯计数的话这样是正确的，但如果如果有像本题的要求，最后一个非叶节点在扩展子节点时已经计数了，在弹出最后两个节点时显然就不会输出空格了。
        如果不是在访问到某个节点才增加遍历的节点数量，
        */
    }
}
int main()
{
    cin>>N;
    for(int i=0;i<N;i++) cin>>post[i];
    for(int i=0;i<N;i++) cin>>in[i];
    node* root = create(0, N-1, 0, N-1);
    
    BFS(root);
    cout<<endl;
    system("pause");
}
