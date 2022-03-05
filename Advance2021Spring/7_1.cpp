/*
 * @Author: xinyu Li
 * @Date: 2022-03-05 20:57:23
 * @LastEditTime: 2022-03-05 20:57:23
 * @Description: 
 * @FilePath: \helloworld\PTA\Advance2021Spring\7_1.cpp
 * chaos is a ladder
 */
/*
 * @Author: xinyu Li
 * @Date: 2022-02-22 16:24:01
 * @LastEditTime: 2022-03-01 10:42:16
 * @Description: 
 * @FilePath: \helloworld\1.cpp
 * chaos is a ladder
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n, maxp, isprime[maxn];
vector<int> prime;
int main(){
    cin>>n>>maxp;
    fill(isprime, isprime+maxn, 1);
    for(int i=2;i<=maxp;i++){
        if(isprime[i]){
            prime.push_back(i);
            for(int j=2;j*i<=maxp;j++)
                isprime[j*i] = 0;           
        }
    }
    if(n == 1){
        cout<<prime[prime.size()-1]<<endl;
        return 0;
    }else if(n==0){
        return 0;
    }
    int maxdiff = -1, maxfirst = 0;
    vector<int> tmp, ans;
    for(int i=0;i<prime.size()-1;i++){
        tmp.push_back(prime[i]);
        for(int j=i+1;j<prime.size();j++){
            tmp.push_back(prime[j]);
            int diff = prime[j] - prime[i];
            int k = 1;
            while(prime[j]+diff*k<=maxp && isprime[diff*k+prime[j]] && k+2<=n){
                k++;
            }
            if(k+2>n){
                if(maxdiff <= diff){
                    maxdiff = diff;
                    maxfirst = prime[i];
                    for(int u=1;u<k;u++) tmp.push_back(u*diff+prime[j]);
                    ans = tmp;
                    for(int u=1;u<k;u++) tmp.pop_back();
                }
            }
            tmp.pop_back();
        }
        tmp.pop_back();
    }
    if(maxdiff==-1) cout<<prime[prime.size()-1]<<endl;
    else{
        for(int i=0;i<ans.size();i++){
            if(i) cout<<" ";
            cout<<ans[i];
        }
    }
    system("pause");
}
/*
5 1000
*//*
 * @Author: xinyu Li
 * @Date: 2022-02-22 16:24:01
 * @LastEditTime: 2022-03-01 10:42:16
 * @Description: 
 * @FilePath: \helloworld\1.cpp
 * chaos is a ladder
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n, maxp, isprime[maxn];
vector<int> prime;
int main(){
    cin>>n>>maxp;
    fill(isprime, isprime+maxn, 1);
    for(int i=2;i<=maxp;i++){
        if(isprime[i]){
            prime.push_back(i);
            for(int j=2;j*i<=maxp;j++)
                isprime[j*i] = 0;           
        }
    }
    if(n == 1){
        cout<<prime[prime.size()-1]<<endl;
        return 0;
    }else if(n==0){
        return 0;
    }
    int maxdiff = -1, maxfirst = 0;
    vector<int> tmp, ans;
    for(int i=0;i<prime.size()-1;i++){
        tmp.push_back(prime[i]);
        for(int j=i+1;j<prime.size();j++){
            tmp.push_back(prime[j]);
            int diff = prime[j] - prime[i];
            int k = 1;
            while(prime[j]+diff*k<=maxp && isprime[diff*k+prime[j]] && k+2<=n){
                k++;
            }
            if(k+2>n){
                if(maxdiff <= diff){
                    maxdiff = diff;
                    maxfirst = prime[i];
                    for(int u=1;u<k;u++) tmp.push_back(u*diff+prime[j]);
                    ans = tmp;
                    for(int u=1;u<k;u++) tmp.pop_back();
                }
            }
            tmp.pop_back();
        }
        tmp.pop_back();
    }
    if(maxdiff==-1) cout<<prime[prime.size()-1]<<endl;
    else{
        for(int i=0;i<ans.size();i++){
            if(i) cout<<" ";
            cout<<ans[i];
        }
    }
    system("pause");
}
/*
5 1000
*/