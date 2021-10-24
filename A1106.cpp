#include<bits/stdc++.h>
using namespace std;
int hashTable[100010] = {0}, N;
double P, r, minP = 1e12;
struct node{
    int level;
    vector<int> child;
}Node[100010];
void BFS(int root)
{   
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int top = q.front();
        int size = Node[top].child.size();
        q.pop();
        int level = Node[top].level;
        if(!Node[top].child.size())
            hashTable[level]++;
        for(int i=0;i<size;i++){
            Node[Node[top].child[i]].level = level + 1;
            q.push(Node[top].child[i]);
        }
    }    
}
double pow(int n)
{
    double plus = P;
    for(int i=0;i<n;i++)
        plus *= (1+r);
    return plus;
}
int main()
{
    cin>>N>>P>>r;
    r /= 100;
    for(int i=0;i<N;i++){
        int n, child;
        cin>>n;
        if(n != 0){
            for(int j=0;j<n;j++){cin>>child;Node[i].child.push_back(child);}
        }else continue;
    }
    BFS(0);
    int i = 0;
    while(!hashTable[i])i++;
    printf("%.4f %d\n", pow(i), hashTable[i]);
    system("pause");
}
