//要按照路径的字典序排列输出  
//路径：DFS
//树：静态数组
//字典序：sort(pointer begin, pointer end, cmp)
//对序列的排序输出思路不一定是用优先队列存储序列，可以是sort函数，对序列进行排序输出，写法与优先队列类似，可以自己定义比较函数（不用写struct来重载，只需要写一个cmp函数）
#include<bits/stdc++.h>
using namespace std;
int N, M, S, sum = 0, W, ROOT, Count[100];

vector<int> tmp;

struct node{
    int w;
    vector<int> child;
    
}Node[100];
void DFS(int root){   //树的先根遍历就是深度优先搜索
    int size = Node[root].child.size();
    if(sum == S && !size){
        if(root == ROOT) {cout<<W<<endl;return;}
        cout<<W<<" ";
        for(int i=0;i<tmp.size();i++){
            cout<<Node[tmp[i]].w;
            if(i < tmp.size()-1) cout<<" ";
        }
        cout<<endl;
        return;
    }
    if(!Node[root].child.size() || sum > S) return;
    for(int i=0;i<size;i++){
        tmp.push_back(Node[root].child[i]);
        sum += Node[Node[root].child[i]].w;
        DFS(Node[root].child[i]);
        sum -= Node[Node[root].child[i]].w;
        tmp.pop_back();
    }  
}
int Root(){
    for(int i=0;i<M;i++)
        if(Count[i] == 0) return i;
}
bool cmp(int a, int b){
    return Node[a].w > Node[b].w;
}
int main()
{
    cin>>N>>M>>S;
    int w, id, c;
    for(int i=0;i<N;i++)
        cin>>Node[i].w;
    for(int i=0;i<M;i++){
        cin>>id>>c; //id和儿子数量
        int a;
        for(int j=0;j<c;j++) {cin>>a;Node[id].child.push_back(a);Count[a]++;}
        sort(Node[id].child.begin(), Node[id].child.end(), cmp);
    }

    ROOT = Root();
    sum += Node[ROOT].w;
    W = sum;
    DFS(ROOT);
    system("pause");
    return 0;
}
/*
20 9 24
10 2 4 3 5 10 2 18 9 7 2 2 1 3 12 1 8 6 2 2
00 4 01 02 03 04
02 1 05
04 2 06 07
03 3 11 12 13
06 1 09
07 2 08 10
16 1 15
13 3 14 16 17
17 2 18 19
*/