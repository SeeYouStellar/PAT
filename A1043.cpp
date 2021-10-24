//反转二叉树（本题的mirror）可以在生成二叉树时反转（结构反转），也可以在遍历时反转（输出反转）
#include<bits/stdc++.h>
using namespace std;
int N, Data[1000];
vector<int> v, post;
struct node{
    int data;
    node* lchild;
    node* rchild;
}Node[1000];
//删除BTS中的节点
// node* findmax(node* root)
// {
    
// }
// node* findmin(node* root)
// {

// }
// void deleteNode(node* root, int data)
// {
    
// }
void insertNode(node* &root, int x)
{
    if(root == NULL) {root = new node();root->data = x;return;}
    else if(root->data > x)insertNode(root->lchild, x);
    else if(root->data <= x)insertNode(root->rchild, x);
    else return;
}
node* createNode(int n)
{
    node* root = NULL;
    for(int i=0;i<n;i++)
        insertNode(root, Data[i]);
    return root;
}
void InsertNode(node* &root, int x)
{
    if(root == NULL) {root = new node();root->data = x;return;}
    else if(root->data <= x)InsertNode(root->lchild, x);
    else if(root->data > x)InsertNode(root->rchild, x);
    else return;
}
node* CreateNode(int n)
{
    node* root = NULL;
    for(int i=0;i<n;i++)
        InsertNode(root, Data[i]);
    return root;
}
void preorder(node* root)
{
    if(root == NULL) return;
    v.push_back(root->data);
    preorder(root->lchild);
    preorder(root->rchild);
}
bool cmp()
{
    for(int i=0;i<N;i++)
        if(v[i] != Data[i]) return false;
    return true;
}
void postorder(node* root)
{
    if(root == NULL) return;
    postorder(root->lchild);
    postorder(root->rchild);
    post.push_back(root->data);
}
int main()
{
    int d, flag = 0;
    cin>>N;
    for(int i=0;i<N;i++) {cin>>d;Data[i] = d;} 
    node* root = createNode(N);
    node* mirror = CreateNode(N);
    preorder(root);
    if(cmp()){
        cout<<"YES\n";
        postorder(root);
        for(int i=0;i<N;i++){
            cout<<post[i];
            if(i < N-1) cout<<" ";
        }
        cout<<endl;
        flag = 1;
    }
    v.clear();
    post.clear();
    preorder(mirror);
    if(!flag && cmp()){
        cout<<"YES\n";
        postorder(mirror);
        for(int i=0;i<N;i++){
            cout<<post[i];
            if(i < N-1) cout<<" ";
        }
        cout<<endl;
        flag = 1;
    }
    if(!flag) cout<<"NO\n";
    system("pause");
}