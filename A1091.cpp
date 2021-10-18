//bfs 用队列实现
#include<bits/stdc++.h>
using namespace std;

int M, N, L, T, out = 0;
bool inq[1290][130][60] = {false};
int pixel[1290][130][60];
int X[6] = {0, 0, 0, 0, 1, -1};
int Y[6] = {0, 0, 1, -1, 0, 0};
int Z[6] = {1, -1, 0, 0, 0, 0};

class node{
public:
    int x;
    int y;
    int z;
};

bool text(int x, int y, int z)
{
    if(x >= M || x < 0 || y >= N || y < 0 || z >= L || z < 0) return false;  //这里的宽是列数，长是行数
    else if(inq[x][y][z] == true) return false;
    else if(pixel[x][y][z] == 0) return false;
    return true;
}

int BFS(int x, int y, int z)
{
    queue<node> q;
    node s;
    s.x = x;
    s.y = y;
    s.z = z;
    int count = 1;
    q.push(s);
    inq[x][y][z] = true;
    while(!q.empty()){
        node top = q.front();
        q.pop();
        for(int i=0;i<6;i++){
            int newx = top.x + X[i];
            int newy = top.y + Y[i];
            int newz = top.z + Z[i];
            if(text(newx, newy, newz)){
                node Node;
                Node.x = newx;
                Node.y = newy;
                Node.z = newz;
                inq[newx][newy][newz] = true;
                q.push(Node);
                count++;
            }
        }
    }
    return count;
}

int main()
{
    cin>>M>>N>>L>>T;
    for(int i=0;i<L;i++)
        for(int j=0;j<M;j++)
            for(int k=0;k<N;k++) 
                cin>>pixel[j][k][i];
    for(int i=0;i<L;i++){
        for(int j=0;j<M;j++){
            for(int k=0;k<N;k++){
                int count = 0;
                if(pixel[j][k][i] && !inq[j][k][i] && (count=BFS(j, k, i))>=T)
                    out+=count;
            }
        }
    }
    cout<<out;
    system("pause");
}