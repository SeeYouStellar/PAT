/*
 * @Author: xinyu Li
 * @Date: 2022-03-05 20:54:22
 * @LastEditTime: 2022-03-05 20:54:23
 * @Description: 
 * @FilePath: \helloworld\PTA\A1159.cpp
 * chaos is a ladder
 */
/*
 * @Author: xinyu Li
 * @Date: 2022-03-01 16:02:19
 * @LastEditTime: 2022-03-01 16:06:25
 * @Description: 
 * @FilePath: \helloworld\5.cpp
 * chaos is a ladder
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 40;
int in[maxn], post[maxn], n, m;
map<int, int> sib;
struct node{
    int val;
    node* lchild;
    node* rchild;
    int level;
    int isfull;
};
map<int, node*> treenode; 
int isfullnum = 0;
node* buildtree(int inl, int inr, int pl, int pr, int level)
{
    if(inl>inr) {return NULL;}
    node* root = new node();
    root->val = post[pr];
    root->level = level;
    treenode[root->val] = root;
    int i;
    for(i=0;i<n;i++){
        if(in[i] == post[pr]) break;
    }
    int cc = i-inl;
    root->lchild = buildtree(inl, i-1, pl, pl+cc-1, level+1);
    root->rchild = buildtree(i+1, inr, pl+cc, pr-1, level+1);
    if(root->lchild!=NULL && root->rchild!=NULL) {
        sib[root->lchild->val] = root->rchild->val;
        sib[root->rchild->val] = root->lchild->val;
        root->isfull = 1;
        isfullnum++;
    }else if(root->lchild==NULL && root->rchild==NULL){
        isfullnum++;
    }
    return root;
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>post[i];
    for(int i=0;i<n;i++)
        cin>>in[i];
    node* root = buildtree(0, n-1, 0, n-1, 1);
    cin>>m;
    getchar();
    string ss;
    char* s;
    for(int i=0;i<m;i++){
        getline(cin, ss);
        s = (char*)ss.c_str();
        int a, b;
        if(ss.find("root")!=string::npos){
            sscanf(s, "%d is the root", &a);
            if(a==root->val)
                cout<<"Yes\n";
            else 
                cout<<"No\n";
        }else if(ss.find("siblings")!=string::npos){
            sscanf(s, "%d and %d are siblings", &a, &b);
            if(sib.find(a)!=sib.end() && sib[a] == b)
                cout<<"Yes\n";
            else cout<<"No\n";
        }else if(ss.find("parent")!=string::npos){
            sscanf(s, "%d is the parent of %d", &a, &b);
            if(treenode[a]->lchild == treenode[b] || treenode[a]->rchild == treenode[b])
                cout<<"Yes\n";
            else cout<<"No\n";
        }else if(ss.find("left")!=string::npos){
            sscanf(s, "%d is the left child of %d", &a, &b);
            if(treenode[b]->lchild == treenode[a])
                cout<<"Yes\n";
            else cout<<"No\n";
        }else if(ss.find("right")!=string::npos){
            sscanf(s, "%d is the right child of %d", &a, &b);
            if(treenode[b]->rchild == treenode[a]) 
                cout<<"Yes\n";
            else cout<<"No\n";
        }else if(ss.find("level")!=string::npos){
            sscanf(s, "%d and %d are on the same level", &a, &b);
            if(treenode[a]->level == treenode[b]->level)
                cout<<"Yes\n";
            else cout<<"No\n";
        }else if(!strcmp(s, "It is a full tree")){
            if(isfullnum==n)
                cout<<"Yes\n";
            else cout<<"No\n";
        }
    }
    system("pause");
}

