/*
 * @Author: xinyu Li
 * @Date: 2022-03-05 20:45:14
 * @LastEditTime: 2022-03-05 20:45:15
 * @Description: 
 * @FilePath: \helloworld\PTA\A1032.CPP
 * chaos is a ladder
 */
#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int ne[maxn], n, head1, head2, flag[maxn];
char da[maxn];
int main()
{
    cin>>head1>>head2>>n;
    for(int i=0;i<n;i++){
        int addr;
        cin>>addr;
        cin>>da[addr]>>ne[addr];
    }
    while(head1!=-1){
        flag[head1] = 1;
        head1 = ne[head1];
    }
    while(head2!= -1){
        if(flag[head2]) break;
        head2 = ne[head2];
    }
    if(head2 == -1){
        cout<<"-1"<<endl;
    }else{
        printf("%05d\n", head2);
    }
}