/*
 * @Author: xinyu Li
 * @Date: 2022-03-05 20:59:56
 * @LastEditTime: 2022-03-05 21:00:38
 * @Description: 
 * @FilePath: \helloworld\PTA\Advance2021Winter\4(notenough).cpp
 * chaos is a ladder
 */
#include<bits/stdc++.h>

using namespace std;

const int N = 1e3+10;
const int inf = 0x3f3f3f3f;
typedef pair<int,int> pii;
/*
5 11 08:00
09:00 10 2
08:30 50 10
13:00 5 1
08:35 20 3
08:30 200 80
1 0 5
0 2 30
3 0 20
0 4 40
4 5 5
1 4 21
1 3 60
1 2 30
2 3 10
3 4 2
2 4 60
5
1 4 1 3 2
3 4 1 2 1
3 4 1 1 2
5 1 2 3 1
5 4 1 1 2

*/

int n,m,st;
int g[N][N];
pair<int,pii> p[N];
int a[N];

int convert(string tim){
	int hh = stoi(tim.substr(0,2))*60;
	int tt = stoi(tim.substr(3,2));
	return hh+tt;
}

void floyd(){
	for(int k = 0; k <= n; k ++ ){
		for(int i = 0; i <= n; i ++ ){
			for(int j = 0; j <= n; j ++ ){
				if(g[i][k]!=inf&&g[k][j]!=inf)
				g[i][j] = min(g[i][k]+g[k][j],g[i][j]);
			}
		}
	}
}

int main(){
	string t;
	cin>>n>>m>>t;
	st = convert(t);
	for(int i = 1; i <= n; i ++ ){
		string t;
		int ya,yb;
		cin>>t>>ya>>yb;
		int tim = convert(t);
		p[i] = {tim,{ya,yb}};
	}
	for(int i = 0; i <= n; i ++ ){
		for(int j = 0; j <= n; j ++ ){
			if(i == j) continue;
			g[i][j] = inf;
		}
	}
	for(int i = 1; i <= m; i ++){
		int a,b,c;cin>>a>>b>>c;
		g[a][b] = g[b][a] = min(g[a][b],c);
	}
	floyd();
//	for(int i = 0; i <= n; i ++ ){
//		for(int j = 0; j <= n; j ++ ){
//			cout<<g[i][j]<<" ";
//		}
//		puts("");
//	}
//	return 0;
	int k;cin>>k;
	int mx_a = -1e9,mx_b = 1e9;
	//修改为-inf,inf
	while(k --){
		map<int,int> hs;
		bool flag = false;
		for(int i = 1; i <= n; i ++){
			cin >> a[i];
			hs[a[i]]+=1;
			if(hs[a[i]] > 1 || a[i] < 1 || a[i] > n) flag = true;
		}
		if(flag) continue;
		int tim = st;
		int idx = 0;
		int sa = 0;
		for(int i = 1; i <= n+1; i ++){
			if(g[idx][a[i]] == inf) {
				flag = true;break;
			}
			tim += g[idx][a[i]];
			idx = a[i];
			int a1 = p[a[i]].second.first;
			int b1 = p[a[i]].second.second;
			int c = p[a[i]].first;
			sa+=a1;
			if(tim > c) sa -= b1;
			//cout<<tim/60<<" "<<tim%60<<endl;
		}
		if(flag) continue;
		//return 0;
		if(mx_a < sa){
			mx_a = sa;
			mx_b = tim;
		}else if(mx_a == sa){
			if(mx_b > tim) mx_b = tim;
		}
//		printf("--------\n");
//		cout<<tim/60<<" "<<tim%60<<endl;
//		cout<<sa<<endl;
//		printf("--------\n");
	}
	//分钟对24*60进行取余运算
	//mx_b%=24*60;
	printf("%d %02d:%02d",mx_a,mx_b/60,mx_b%60);
	return 0;
}
