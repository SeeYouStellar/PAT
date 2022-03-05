/*
 * @Author: xinyu Li
 * @Date: 2022-03-05 20:51:56
 * @LastEditTime: 2022-03-05 20:51:57
 * @Description: 
 * @FilePath: \helloworld\PTA\A1122.cpp
 * chaos is a ladder
 */
#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main() {
    int n, m, cnt, k, a[210][210] = {0}, query[210] = {0};
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int t1, t2;
        scanf("%d%d", &t1, &t2);
        a[t1][t2] = a[t2][t1] = 1;
    }
    cin >> cnt;
    while(cnt--) {
        cin >> k;
        int flag1 = 1, flag2 = 1;
        cin>>query[0];
        set<int> s;
        s.insert(query[0]);
        for(int i=1;i<k;i++){
            cin>>query[i];
            s.insert(query[i]);
            if(!a[query[i-1]][query[i]]) flag1 = 0;
        }
        if(k>n+1 || s.size()!=n || query[0] != query[k-1]) flag2 = 0;
        if(!flag1 || !flag2) cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}