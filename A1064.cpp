//BTS的中序遍历是递增的
//满二叉树：所有节点都有左右子节点
//完全二叉树CBT:除了最后一层，每一层的节点数都是满的，最后一层到最后一个节点之前的节点数也是满的
//CBT数组是用来储存完全二叉树，完全二叉树节点编号为i(CBT[i]),其左儿子编号为i*2,右儿子节点编号i*2+1
//对输入的插入顺序数组进行升序排序，可以得到BTS的中序遍历数组
//对CBT数组进行中序遍历（稍微更改处理节点的操作） 中序遍历数组的顺序即为中序遍历递归的结果
//CBT数组的顺序即层序遍历的顺序
#include<bits/stdc++.h>
using namespace std;
int N, CBT[1001], tree[1000], cnt = 0;
vector<int> in;

void inorder(int root)
{
    if(root > N) return;
    inorder(root*2);
    CBT[root] = tree[cnt++]; //处理root:只需要将中序遍历的值赋给cbt数组即可
    inorder(root*2+1);
}
int main()
{
    cin>>N;
    for(int i=0;i<N;i++) cin>>tree[i];
    sort(tree, tree+N);
    inorder(1);
    for(int i=1;i<=N;i++){
        cout<<CBT[i];
        if(i < N) cout<<" ";
    }
    cout<<endl;
    system("pause");
}

