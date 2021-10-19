//构造一棵树即可，每一层算每一层的price，每一层的price是一样的。先根遍历到达叶节点时，就在总销售额上加上这个叶节点（retailer）的销售额
#include<bits/stdc++.h>
using namespace std;
int N, flag[100010];
double P, r, sum = 0;
struct node{
    int count;
    vector<int> child;
}Node[100010];
void PreOrder(int root, double price)  //树的先根遍历
{
    if(!Node[root].child.size()){
        sum += Node[root].count*price;
    }
    price = price*(1+r);
    for(int i=0;i<Node[root].child.size();i++)
        PreOrder(Node[root].child[i], price);
}
int Root()//找到根节点
{
    for(int i=0;i<N;i++)
        if(flag[i] == 0) return i;
}
int main()
{
    int n;
    cin>>N>>P>>r;
    r /= 100;
    for(int i=0;i<N;i++){
        cin>>n;//每个节点的子节点个数
        int c;
        if(n != 0) for(int j=0;j<n;j++) {cin>>c;Node[i].child.push_back(c);flag[c]++;}
        else {cin>>c;Node[i].count = c;flag[i]++;}
    }
    int root = Root();
    PreOrder(root, P);
    printf("%.1f\n", sum);  //注意最后输出小数点后1位
    system("pause");
}