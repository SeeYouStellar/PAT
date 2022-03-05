/*
 * @Author: xinyu Li
 * @Date: 2022-03-05 20:53:33
 * @LastEditTime: 2022-03-05 20:53:34
 * @Description: 
 * @FilePath: \helloworld\PTA\A1147.cpp
 * chaos is a ladder
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1100;
int levelOrder[maxn], n, m;
vector<int> v;
void postOrder(int root)
{
    if(root > m) return;
    postOrder(root*2);
    postOrder(root*2+1);
    v.push_back(levelOrder[root]);
}
int main()
{
    cin>>n>>m;
    while(n--){
        for(int i=1;i<=m;i++)
            cin>>levelOrder[i];
        int minh = 1, maxh = 1;
        for(int i=1;i<=m/2;i++){
            int tmp;
            if(i*2+1<=m) tmp = max(levelOrder[i*2], levelOrder[i*2+1]);
            else tmp = levelOrder[i*2];
            if(levelOrder[i]<tmp) {
                maxh = 0;
                break;
            }
        }
        for(int i=1;i<=m/2;i++){
            int tmp;
            if(i*2+1<=m) tmp = min(levelOrder[i*2], levelOrder[i*2+1]);
            else tmp = levelOrder[i*2];
            if(levelOrder[i]>tmp) {
                minh = 0;
                break;
            }
        }
        if(minh) cout<<"Min Heap\n";
        else if(maxh) cout<<"Max Heap\n";
        else cout<<"Not Heap\n";
        postOrder(1);
        for(int i=0;i<v.size();i++){
            cout<<v[i];
            if(i != v.size()-1) cout<<" ";
        }
        v.clear();
        cout<<endl;
    }
}