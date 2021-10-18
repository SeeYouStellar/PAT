//dfs
#include <bits/stdc++.h>
using namespace std;
int N;
int K;
int P;
vector<int> fac;
vector<int> temp;
vector<int> best;
int maxSum = -1;
int n;
void DFS(int i, int nowk, int cp, int nowN)
{
    if(cp == N && nowk == K){
        if(maxSum < nowN){
            maxSum = nowN;
            best = temp;
            return ;
        }
    }
    if(nowk > K || cp > N || i <= 0) return ;
    temp.push_back(i);
    DFS(i, nowk+1, cp+fac[i], nowN+i);
    temp.pop_back();
    DFS(i-1, nowk, cp, nowN);
}

void Getfac(int N, int P)
{
    int i = 0, power = 0;
    while(power <= N){
        fac.push_back(power);
        i++;
        power = pow(i,P);
    }
}
int main()
{
    cin>>N>>K>>P;
    Getfac(N, P);
    n = fac.size();
    DFS(n-1, 0, 0, 0);
    if(maxSum == -1) cout<<"Impossible\n";
    else{
        cout<<N<<" = ";
        for(int i=0;i<best.size();i++){
            if(i == 0) cout<<best[i]<<"^"<<P;
            else cout<<" + "<<best[i]<<"^"<<P;
        }
    }
    system("pause"); 
}