/*
 * @Author: xinyu Li
 * @Date: 2021-10-29 19:07:02
 * @LastEditTime: 2021-10-30 13:14:12
 * @Description: 
 * @FilePath: \helloworld\PTA\A1034.cpp
 * I am because you are
 * 
 * 
 * map<type, type>   
 * map.insert(pair<type, type>)
 * 
 * 
 * 图中的权值分为点权和边权
 * 
 * 该图为无向图，边权为两点间相互通话时间之和
 * 
 * 点权是和他相接的每条边权相加
 * 
 * 所以点权等于边权乘二
 */
#include<bits/stdc++.h>
using namespace std;
const int maxn = 2010;
const int INF = INT16_MAX;
int Graph[maxn][maxn] = {0}, pointW[maxn] = {0}, N, T, id = 0, test[maxn] = {0};
map<string, int> m1; //英文编号到整型编号
map<int, string> m2; //整形编号到英文编号
map<string, int> m3; //英文编号head到该gang的数量  map是按键的字典序排列的（用rbtree实现）所以输出时会按string的字典序来
void DFS(int s, int& n, int& t, int& head)
{
    n++;
    test[s] = true;
    if(pointW[s] > pointW[head]) head = s;
    for(int i=0;i<id;i++) {
        if(Graph[s][i] != 0) {
            t += Graph[s][i];
            Graph[s][i] = Graph[i][s] = 0;
            if(!test[i])DFS(i, n, t, head);
        }
    }
}
void DFStravel()  //计算不同连通分量的head(head of gang),n(总节点个数),t(总通话时长)
{
    for(int i=0;i<m1.size();i++){
        if(!test[i]){
            int n = 0, t = 0, head = i;
            DFS(i, n, t, head);
            if(n > 2 && t > T) m3[m2[head]] = n;
        }
    }
}
int change(string a)
{
    if(m1.find(a) != m1.end()) return m1[a];
    else{
        m1[a] = id++; 
        m2[id-1] = a;
        return id-1;
    }
}
int main()
{
    cin>>N>>T;
    string a, b;
    int t, A, B;
    for(int i=0;i<N;i++){    
        cin>>a>>b>>t;
        A = change(a);
        B = change(b);
        Graph[A][B] += t;Graph[B][A] += t;   //AB之间和BA之间的通话时长是一样的
        pointW[A] += t;pointW[B] += t;       //每条边都会在增加两个点的点权
    }
    DFStravel();
    cout<<m3.size()<<endl;
    for(map<string, int>::iterator it=m3.begin();it!=m3.end();it++){
        cout<<it->first<<" "<<it->second<<endl;   //迭代器的两个属性是公共的
    }
    system("pause");
}