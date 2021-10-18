//静态数组实现二叉树
//题目分解：输入的二叉树的保存（静态二叉链表），根节点的确定，转置二叉树，二叉树的层序遍历和中序遍历
#include<bits/stdc++.h>
using namespace std;
int N;
vector<int> in;

struct node{
    int data;
    int lchild;
    int rchild;
}Node[10];
//Node[i]代表值为第i个节点，每个节点的值不一定是i，lchild和rchild代表左右子节点在数组内的下标
void PrevOrder(int root)  //前序遍历
{
    if(root == -1) return ;
    int tmp = Node[root].lchild;          //转置二叉树就是在每个节点处，将其左右子树交换（静态实现的交换数组下标，动态实现的交换子树指针）
    Node[root].lchild = Node[root].rchild;
    Node[root].rchild = tmp;
    PrevOrder(Node[root].lchild);    //用任何遍历方式都可以
    PrevOrder(Node[root].rchild);
}
void BFS(int root) //层序遍历
{
    queue<int> q;
    q.push(root);
    int count = 0;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        cout<<Node[now].data;
        count++;
        if(count < N) cout<<" ";
        if(Node[now].lchild != -1) q.push(Node[now].lchild);
        if(Node[now].rchild != -1) q.push(Node[now].rchild);
    }
}
void InOrder(int root)
{
    if(root == -1) return ;
    InOrder(Node[root].lchild);
    in.push_back(Node[root].data);
    InOrder(Node[root].rchild);
}
int main()
{
    cin>>N;
    char l ,r;
    int count[10] = {0}, root;  //根节点是二叉树中唯一没有入度的节点，count数组为了记录每个节点的入度
    for(int i=0;i<N;i++){
        cin>>l>>r;
        Node[i].data = i;
        if(l != '-'){Node[i].lchild = l - '0';count[l-'0']++;}  //是数字则转换为数字
        else Node[i].lchild = -1;                               //是'-'则转换为-1代表没有该子节点
        if(r != '-'){Node[i].rchild = r - '0'; count[r-'0']++;} 
        else Node[i].rchild = -1; 
    }
    for(int i=0;i<N;i++)
        if(count[i] == 0){
            root = i;
            break;
        }
    PrevOrder(root);
    BFS(root);
    cout<<endl;
    InOrder(root);
    for(int i=0;i<N;i++){
        cout<<in[i];
        if(i < N-1) cout<<" ";
    }
    cout<<endl;
    system("pause");
}