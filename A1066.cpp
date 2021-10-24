/*
 * @Author: xinyu Li
 * @Date: 2021-10-24 16:00:52
 * @LastEditTime: 2021-10-24 22:26:37
 * @Description: AVL树
 * @FilePath: \helloworld\fuck\Tree\BST\AVL\A1066.cpp
 * I am because you are
 */
#include<iostream>
using namespace std;
int N, arr[20] = {0};
struct node{
    int data, h;
    node* lchild;
    node* rchild;
};
int geth(node* root)  //获取节点的高度（只是获取node->h）每次调用这个函数都是在他的子节点在本次插入过程中已经更新了
{
    if(root == NULL) return 0;
    return root->h;
}
void upgradeh(node* root) //更新节点高度 （每个叶节点初始高度为1，随着其他节点的插入，该节点变成非叶节点，需要不断更新高度，此时的高度不能从node->h获取，因为那是之前的高度，要想获取当前高度，得用下面这几句代码） 
{
    root->h = 1 + max(geth(root->lchild), geth(root->rchild));
    //这里不能是1+max(root->lchild->h, root->rchild->h)，因为有些时候左右子树可能是空的，就会报错
}
void leftRotation(node* &root)  //左旋
{
    node* tmp = root->rchild;
    root->rchild = tmp->lchild;
    tmp->lchild = root;
    upgradeh(root);   //旋转过后自然要更新h
    root = tmp;
    upgradeh(tmp);
}
void rightRotation(node* &root)  //右旋
{
    node* tmp = root->lchild;
    root->lchild = tmp->rchild;
    tmp->rchild = root;
    upgradeh(root);
    root = tmp;
    upgradeh(tmp);
}
node* newnode(int data)
{
    node* tmp = new node();
    tmp->data = data;
    tmp->h = 1;
    tmp->lchild = tmp->rchild = NULL;
    return tmp;
}
int getbalance(node* root) //计算平衡因子
{
    return geth(root->lchild) - geth(root->rchild);
}

void insert(node* &root, int d)
{
    if(root == NULL){root = newnode(d);return;}
    else if(root->data == d)return;
    else if(root->data < d){ //进入右子树
        insert(root->rchild, d); 
        upgradeh(root); //更新root的h
        if(getbalance(root) == -2){ //root的平衡因子为-2，且只可能为-2不可能为2
            if(getbalance(root->rchild) == 1){//root的右子树的平衡因子为1 
                rightRotation(root->rchild);
                leftRotation(root);
            }   
            else       //root的右子树的平衡因子为-1
                leftRotation(root);
        }
    }
    else{   //进入左子树
        insert(root->lchild, d); 
        upgradeh(root); //更新root的h
        if(getbalance(root) == 2){ //root的平衡因子为-2，且只可能为-2不可能为2
            if(getbalance(root->lchild) == -1){//root的右子树的平衡因子为1 
                leftRotation(root->lchild);
                rightRotation(root);
            }   
            else       //root的右子树的平衡因子为-1
                rightRotation(root);
        }
    }
}
node* create()
{
    node* root = NULL;
    for(int i=0;i<N;i++)
        insert(root, arr[i]);
    return root;
}
int main()
{
    cin>>N;
    for(int i=0;i<N;i++) cin>>arr[i];
    node* root = create();
    cout<<root->data<<endl;
    system("pause");
}

