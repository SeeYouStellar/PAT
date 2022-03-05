/*
 * @Author: xinyu Li
 * @Date: 2022-03-05 20:48:30
 * @LastEditTime: 2022-03-05 20:48:31
 * @Description: 
 * @FilePath: \helloworld\PTA\A1078.CPP
 * chaos is a ladder
 */
#include <bits/stdc++.h>
using namespace std;
int tsize, N, hash_[10010];
int isprime(int x)
{
    if(x<2) return 0;
    for(int i=2;i<=(int)sqrt(x+1);i++){
        if(!(x % i)) return 0;
    }
    return 1;
}
int insertkey(int x)
{
    int key;
    for(int i=0;i<tsize;i++){
        key = (x+i*i)%tsize;
        if(!hash_[key]){
            hash_[key] = x;
            return key;
        }else
            continue;
    }
    return -1;
}
int main()
{
    cin>>tsize>>N;
    while(!isprime(tsize)){tsize++;}
    int a, key;
    for(int i=0;i<N;i++){
        cin>>a;
        int ans = insertkey(a);
        if(ans == -1) cout<<"-";
        else cout<<ans;
        if(i != N-1) cout<<" ";
    }
    cout<<endl;
}