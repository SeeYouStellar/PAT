/*
 * @Author: xinyu Li
 * @Date: 2022-03-05 20:58:08
 * @LastEditTime: 2022-03-05 20:58:09
 * @Description: 
 * @FilePath: \helloworld\PTA\Advance2021Spring\7_4.cpp
 * chaos is a ladder
 */
/*
 * @Author: xinyu Li
 * @Date: 2022-03-01 13:24:56
 * @LastEditTime: 2022-03-01 15:00:18
 * @Description: 
 * @FilePath: \helloworld\web\4.cpp
 * chaos is a ladder
 */

#include <bits/stdc++.h>
using namespace std;
const int maxn = 210;
const int INF = 100000000;
int d[maxn][maxn], n, m, vis[maxn];
void floyd()
{
    for(int i=0;i<=n;i++) d[i][i] = 0;
    for(int k=0;k<=n;k++){
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(d[i][k]!=INF && d[k][j]!=INF && d[i][k]+d[k][j]<d[i][j])
                    d[i][j] = d[i][k]+d[k][j];
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    fill(d[0], d[0]+maxn*maxn, INF);
    for(int i=0;i<m;i++){
        int a, b, c;
        cin>>a>>b>>c;
        d[a][b] = d[b][a] = c;
    }
    floyd();
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=n;j++){
    //         cout<<d[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    int head = 0, cnt = 0, dd = 0;
    vector<int> ans;
    ans.push_back(head);
    for(int i=0;i<=n;i++){
        int MIN = INF, u = -1;
        for(int j=1;j<=n;j++){
            if(!vis[j] && d[head][j] < MIN){
                MIN = d[head][j];
                u = j;
            }
        }
        if(u == -1)
            break;
        vis[u] = 1;
        dd+=MIN;
        cnt++;
        head = u;
        ans.push_back(head);
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
        if(i < ans.size()-1) cout<<" ";
    }
    cout<<endl;
    if(cnt!=n){
        cnt = n-cnt;
        for(int i=1;i<=n && cnt>0;i++){
            if(cnt>1){
                if(!vis[i]) {cout<<i<<" ";cnt--;}
            }else
                if(!vis[i]) cout<<i;
        }
    }else cout<<dd;
    system("pause");
}

/*
7 10
0 2 1
0 4 5
0 7 3
0 6 4
0 5 5
1 2 2
1 7 2
2 3 4
3 4 2
6 7 9


*/