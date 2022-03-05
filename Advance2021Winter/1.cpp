/*
 * @Author: xinyu Li
 * @Date: 2022-03-05 20:59:40
 * @LastEditTime: 2022-03-05 20:59:40
 * @Description: 
 * @FilePath: \helloworld\PTA\Advance2021Winter\1.cpp
 * chaos is a ladder
 */
/*
 * @Author: xinyu Li
 * @Date: 2022-03-01 19:47:44
 * @LastEditTime: 2022-03-01 19:47:45
 * @Description: 
 * @FilePath: \helloworld\6.cpp
 * chaos is a ladder
 */
#include<bits/stdc++.h>
using namespace std;
struct site{
    int id;
    int mostlikelytime;
    int f;
    int opinion[110];
}sites[10010];
int n, M;
map<int, int> m;

int main()
{
    cin>>n>>M;
    int a;
    
    for(int j=0;j<M;j++){
        m.clear();
        for(int i=0;i<n;i++){
            cin>>a;
            sites[i].opinion[j] = a;
            if(m.find(a)!=m.end())
                m[a]++;
            else
                m[a] = 1;
        }
        int maxf = 0;
        for(int i=0;i<n;i++){
            sites[i].f = n-m[sites[i].opinion[j]];
            if(sites[i].f>maxf) maxf = sites[i].f;
        }
        for(int i=0;i<n;i++){
            if(sites[i].f==maxf){
                sites[i].mostlikelytime++;
            }
        }
    }
    
    int maxt = 0, u = -1;
    for(int i=0;i<n;i++){
        if(maxt<sites[i].mostlikelytime){maxt = sites[i].mostlikelytime;u = i+1;}
    }
    cout<<u<<endl;
    system("pause");
}