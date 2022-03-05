/*
 * @Author: xinyu Li
 * @Date: 2022-03-05 20:46:41
 * @LastEditTime: 2022-03-05 20:46:41
 * @Description: 
 * @FilePath: \helloworld\PTA\A1056.cpp
 * chaos is a ladder
 */
#include<bits/stdc++.h>
using namespace std;
int Np, Ng;

struct mice{
    int weight;
    int rank;
}mouse[1010];
queue<int> q;

int main()
{
    cin>>Np>>Ng;
    for(int i=0;i<Np;i++)
        cin>>mouse[i].weight;
    for(int i=0;i<Np;i++){
        int a;
        cin>>a;
        q.push(a);
    }
    while(!q.empty()){
        if(q.size() == 1){
            mouse[q.front()].rank = 1;
            q.pop();
            continue;
        }
        int n = q.size()/Ng;
        int last = q.size()%Ng;
        int rank = last==0?n+1:n+2;
        
        while(n--){
            int k = q.front();
            for(int i=0;i<Ng;i++)
            {
                int now = q.front();
                q.pop();
                if(mouse[k].weight < mouse[now].weight){
                    k = now;
                }
                mouse[now].rank = rank;
            }
            q.push(k);
        }
        if(last){
            int  k = q.front();
            while(last--){
                int now = q.front();
                q.pop();
                if(mouse[k].weight < mouse[now].weight){
                    k = now;
                }
                mouse[now].rank = rank;
            }
            q.push(k);
        }
    }
    for(int i=0;i<Np;i++){
        cout<<mouse[i].rank;
        if(i < Np-1) cout<<" ";
    }
    cout<<endl;
}