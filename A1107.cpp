/*
* @Author: xinyu Li
* @Date: 2021-10-25 20:25:35
 * @LastEditTime: 2021-10-25 23:03:48
* @Description: 
 * @FilePath: \helloworld\fuck\Tree\UFS\A1107.cpp
* I am because you are
*/
//将所有人的编号构建成并查集，两个编号是否合并根据这两个人是否有喜好相同，只要一个喜好a有人i喜欢则isRoot[a]=i，所以某个人的喜好是否有人也喜欢，即看isRoot是否有大于0的值，
//如果当前没有人喜欢这个喜好则将这个人自己和自己合并（即啥也不做）。所以每个人要么和其他人合并，要么自己令其一个集合，自己为该集合的根节点。所以只要找到这些人中的根节点的个数，那么就找到了集合的个数
#include <bits/stdc++.h>
using namespace std;
int N, father[1001], isRoot[1001] = {0}, course[1001] = {0};
void init(int n)
{
    for (int i = 1; i <= n; i++){
        father[i] = i;
        isRoot[i] = 0;
    }
}
int find(int node)
{
    int tmp = node;
    while (father[node] != node)
        node = father[node];
    while (tmp != father[tmp]){
        int a = tmp;
        tmp = father[tmp];
        father[a] = node;
    }
    return node;
}
void Union(int a, int b)
{
    int fa = find(a);
    int fb = find(b);
    if (fa != fb)
        father[fa] = fb;
}
bool cmp(int a, int b) { return a > b; }
int main()
{
    int n, a;
    cin >> N;
    init(N);
    for (int i = 1; i <= N; i++){
        scanf("%d:", &n);
        for (int j = 0; j < n; j++){
            scanf("%d", &a);
            if (course[a] == 0)     //每个人的喜好要么还没人喜欢，要么已经有人喜欢了，有人喜欢则与喜欢该喜好的人的根节点Union，没有则和自己Union
                course[a] = i;
            Union(i, find(course[a]));
        }
    }
    for (int i = 1; i <= N; i++)
        isRoot[find(i)]++;
    int ans = 0;
    for (int i = 1; i <= N; i++)
        if (isRoot[i] != 0)
            ans++;
    cout << ans << endl;
    sort(isRoot + 1, isRoot + N + 1, cmp);
    for (int i = 1; i <= ans; i++){
        cout << isRoot[i];
        if (i < ans)
            cout << " ";
    }
    system("pause");
}