/*
 * @Author: xinyu Li
 * @Date: 2022-03-05 20:57:40
 * @LastEditTime: 2022-03-05 20:57:40
 * @Description: 
 * @FilePath: \helloworld\PTA\Advance2021Spring\7_2.cpp
 * chaos is a ladder
 */
/*
 * @Author: xinyu Li
 * @Date: 2022-02-24 13:15:37
 * @LastEditTime: 2022-03-01 11:01:45
 * @Description: 
 * @FilePath: \helloworld\2.cpp
 * chaos is a ladder
 */

#include<bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, int>> inout;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    if(a.first != b.first)
        return a.first > b.first;
    else if(a.first==b.first)
        return a.second < b.second;
}
int main()
{
    cin>>n;
    int hi, mi, si, ho, mo, so;
    for(int i=0;i<n;i++){
        scanf("%d:%d:%d %d:%d:%d", &hi, &mi, &si, &ho, &mo, &so);
        int in = hi*3600+mi*60+si, out = ho*3600+mo*60+so;
        inout.push_back(make_pair(in, out));
    }   
    sort(inout.begin(), inout.end(), cmp);
    int maxin = inout[0].first, cnt = 1;
    for(int i=1;i<inout.size();i++){
        if(inout[i].second <= maxin){
            maxin = inout[i].first;
            cnt++;
        }
    }
    cout<<cnt;
    system("pause");
}