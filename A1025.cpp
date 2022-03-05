/*
 * @Author: xinyu Li
 * @Date: 2022-03-05 20:44:55
 * @LastEditTime: 2022-03-05 20:44:56
 * @Description: 
 * @FilePath: \helloworld\PTA\A1025.cpp
 * chaos is a ladder
 */
#include<bits/stdc++.h>
using namespace std;
struct stu{
    char ID[20];
    int grade;
    int local;
    int localRank;
    int globalRank;
}global[30010];
int N, K;
bool cmp(stu a, stu b)
{
    if(a.grade == b.grade){
        return strcmp(a.ID, b.ID) < 0;
    }
    return a.grade > b.grade;
}

int main()
{
    cin>>N;
    int index = 0;
    for(int i=0;i<N;i++){
        cin>>K;
        for(int j=index;j<K+index;j++){
            cin>>global[j].ID>>global[j].grade;
            global[j].local = i+1;
        }
        sort(global+index, global+index+K, cmp);
        global[index].localRank = 1;
        for(int j=index+1;j<index+K;j++){
            if(global[j].grade == global[j-1].grade)
                global[j].localRank = global[j-1].localRank;
            else
                global[j].localRank = j+1-index;
        }
        index+=K;
    }
    sort(global, global+index, cmp);
    global[0].globalRank = 1;
    for(int j=1;j<index;j++){
        if(global[j].grade == global[j-1].grade)
            global[j].globalRank = global[j-1].globalRank;
        else
            global[j].globalRank = j+1;
    }
    cout<<index<<endl;
    for(int i=0;i<index;i++){
        cout<<global[i].ID<<" "<<global[i].globalRank<<" "<<global[i].local<<" "<<global[i].localRank<<endl;
    }
    system("pause");
}