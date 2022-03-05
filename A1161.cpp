/*
 * @Author: xinyu Li
 * @Date: 2022-03-05 20:54:40
 * @LastEditTime: 2022-03-05 20:54:40
 * @Description: 
 * @FilePath: \helloworld\PTA\A1161.cpp
 * chaos is a ladder
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int da[maxn], ne[maxn], n, head1, head2;
int main()
{
    cin >> head1 >> head2 >> n;
    for (int i = 0; i < n; i++)
    {
        int addr;
        cin >> addr;
        cin >> da[addr] >> ne[addr];
    }
    vector<pair<int, int>> v1;
    vector<pair<int, int>> v2;
    vector<pair<int, int>> tmp, ans;
    while (head1 != -1)
    {
        v1.push_back(make_pair(head1, da[head1]));
        head1 = ne[head1];
    }
    while (head2 != -1)
    {
        v2.push_back(make_pair(head2, da[head2]));
        head2 = ne[head2];
    }
    int n1 = v1.size(), n2 = v2.size();
    if (n1 < n2)
    {
        ans = v1;
        v1 = v2;
        v2 = ans;
        swap(n1, n2);
    }
    reverse(v2.begin(), v2.end());
    int j = 0;
    for (int i = 0; i < n1; i++)
    {
        
        if(i%2==0 && i!=0 && j<n2){
            tmp.push_back(v2[j++]);
        }
        tmp.push_back(v1[i]);
    }
    if(j<n2) tmp.push_back(v2[j]);
    for (int i = 0; i < tmp.size(); i++)
    {
        if (i == tmp.size() - 1)
        {
            printf("%05d %d -1\n", tmp[i].first, tmp[i].second);
        }
        else
        {
            printf("%05d %d %05d\n", tmp[i].first, tmp[i].second, tmp[i + 1].first);
        }
    }

}