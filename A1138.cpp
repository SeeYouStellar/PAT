/*
 * @Author: xinyu Li
 * @Date: 2022-03-05 20:52:51
 * @LastEditTime: 2022-03-05 20:52:52
 * @Description: 
 * @FilePath: \helloworld\PTA\A1138.cpp
 * chaos is a ladder
 */
#include<bits/stdc++.h>
using namespace std;
int N, in[50010], pre[50010], cnt = 0;
vector<int> post;
void postOrder(int prel, int prer, int inl, int inr)
{
    if(prel > prer) return ;
    int i;
    for(i=inl;i<=inr;i++)
        if(in[i] == pre[prel])
            break;
    int cc = i - inl;
    postOrder(prel+1, prel+cc, inl, i-1);
    postOrder(prel+cc+1, prer, i+1, inr);
    post.push_back(pre[prel]);
    if(!cnt){
        cout<<pre[prel];
        cnt = 1;
    }
}
int main()
{
    
    cin>>N;
    post.resize(N);
    int a;
    for(int i=0;i<N;i++){
        cin>>a;
        pre[i] = a;
    }
    for(int i=0;i<N;i++){
        cin>>a;
        in[i] = a;
    }
    postOrder(0, N-1, 0, N-1);
    cout<<endl;
}