/*
 * @Author: xinyu Li
 * @Date: 2022-03-05 20:59:52
 * @LastEditTime: 2022-03-05 20:59:53
 * @Description: 
 * @FilePath: \helloworld\PTA\Advance2021Winter\3.cpp
 * chaos is a ladder
 */
// #include<bits/stdc++.h>

// using namespace std;

// const int N = 1e5+10;

// /*

// */

// int n,m;
// vector<int> g[N];
// bool vis[N];
// int cnt[N];

// int dfs(int u){
// 	int sum = 1;
// 	for(int j : g[u]){
// 		if(vis[j]) continue;
// 		vis[j] = true;
// 		sum += dfs(j);
// 		vis[j] = false;
// 	}
// 	cnt[u] = sum;
// 	return sum;
// }

// int main(){
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);
// 	cin >> n;
// 	for(int i = 2; i <= n; i ++ ){
// 		int x;cin>>x;
// 		g[x].push_back(i);
// 	}	
// 	dfs(1);
// 	cin>>m;
// 	for(int i = 0; i < m; i ++){
// 		int idx;cin>>idx;
// 		cout<<cnt[idx]<<endl;
// 	}
// 	return 0;
// }

/*
 * @Author: xinyu Li
 * @Date: 2022-03-01 20:49:36
 * @LastEditTime: 2022-03-01 20:52:30
 * @Description: 
 * @FilePath: \helloworld\7.cpp
 * chaos is a ladder
 */
#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n, m;
vector<int> child[maxn];
int bfs(int root)
{
    queue<int> q;
    q.push(root);
    int cnt = 0;
    while(!q.empty()){
        int top = q.front();
        q.pop();
        cnt++;
        for(int i=0;i<child[top].size();i++){
            q.push(child[top][i]);
        }
    }
    return cnt;
}
int num[maxn];
int dfs(int root)
{
    int sum = 1;
    for(int i=0;i<child[root].size();i++){
        if(num[child[root][i]]) sum+=num[child[root][i]];
        else sum+=dfs(child[root][i]);
    }
    num[root] = sum;
    return sum;
}
int main()
{
    cin>>n;
    int a;
    for(int i=2;i<=n;i++){
        cin>>a;
        child[a].push_back(i);
    }
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>a;
        cout<<dfs(a)<<endl;
    }
}