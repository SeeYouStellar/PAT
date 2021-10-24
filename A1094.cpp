//只需要计算出每个节点的深度即可，因为每层节点的深度是一样的。
//dfs,bfs皆可
//hashTable[100010]是关键
#include<bits/stdc++.h>
using namespace std;

int N, M, Count[100010] = {0}, hashTable[100010], bestn = 0, bestl = 0;
struct node{
    int level;
    vector<int> child;
}Node[100010];
void DFS(int root, int level)
{
    int size = Node[root].child.size();
    hashTable[level]++;
    for(int i=0;i<size;i++){
        Node[root].level = level + 1;
        DFS(Node[root].child[i], level+1);
    }
}
void BFS(int root)
{   
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int top = q.front();
        int size = Node[top].child.size();
        q.pop();
        int level = Node[top].level;
        hashTable[level]++;
        for(int i=0;i<size;i++){
            Node[Node[top].child[i]].level = level + 1;
            q.push(Node[top].child[i]);
        }
    }    
}
int Root()
{
    for(int i=1;i<=N;i++)
        if(Count[i] == 0)
            return i;
}
int main()
{
    cin>>N>>M;
    if(N == 0){
        cout<<0<<" "<<0<<endl;
        return 0;
    }
    int n, son, id;
    for(int i=0;i<M;i++){
        cin>>id>>n;
        for(int j=0;j<n;j++){
            cin>>son;
            Node[id].child.push_back(son);
            Count[son]++;
        }
    }
    int root = Root();
    Node[root].level = 1;
    //BFS(root);
    DFS(root, 1);
    int i=1;
    while(hashTable[i] != 0){
        if(hashTable[i] > bestn){
            bestn = hashTable[i];
            bestl = i;
        }
        i++;
    }
    cout<<bestn<<" "<<bestl<<endl;
    system("pause");
}