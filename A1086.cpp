//push操作顺序为前序遍历，pop操作顺序为中序遍历
#include<bits/stdc++.h>
using namespace std;
int N;
int pre[30], in[30], post[30];
vector<int> v;
struct node{
    int data;
    node* lchild;
    node* rchild;
};
node* create(int inl, int inr, int prel, int prer)
{
    if(prel > prer) return NULL;
    node* root = new node();
    root->data = pre[prel];
    int i;
    for(i=inl;i<=inr;i++)
        if(in[i] == root->data) break;
    int numleft = i - inl;
    root->lchild = create(inl, i-1, prel+1, prel+numleft);
    root->rchild = create(i+1, inr, prel+numleft+1, prer);
    return root;
}
void BFS(node* root)
{
    queue<node*> q;
    q.push(root);
    int count = 0;
    while(!q.empty()){
        node* now = q.front();
        q.pop();
        count++;
        cout<<now->data;
        if(count < N) cout<<" ";                         
        if(now->lchild) BFS(now->lchild);
        if(now->rchild) BFS(now->rchild);
    }
}

void postorder(node* root)
{
    if(root == NULL)
        return ;
    postorder(root->lchild);
    postorder(root->rchild);
    v.push_back(root->data);
}
int main()
{
    cin>>N;
    int j = 0, k = 0;
    stack<int> sk;
    for(int i=0;i<N*2;i++){
        string s;
        int a;
        cin>>s;
        if(s[1] == 'u') {cin>>a;pre[j++] = a;sk.push(pre[j-1]);}
        else {in[k++] = sk.top();sk.pop();}
    }
    // for(int i=0;i<N;i++) cout<<pre[i]<<" ";
    // cout<<endl;
    // for(int i=0;i<N;i++) cout<<in[i]<<" ";
    // cout<<endl;
    node* root = create(0, N-1, 0, N-1);
    postorder(root);
    for(int i=0;i<N;i++){
        cout<<v[i];
        if(i < N-1) cout<<" ";
    }
    cout<<endl;
    system("pause");
}