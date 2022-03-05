#include<bits/stdc++.h>
using namespace std;
struct stu{
    int ID;
    int grade[4];
}ans[2100];

int now, N, M, R[1000000][4];
char aa[4] = {'A', 'C', 'M', 'E'};
bool cmp(stu a, stu b) {
    return a.grade[now] > b.grade[now];              //成绩降序，排名升序
}

int main()
{    
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>ans[i].ID>>ans[i].grade[1]>>ans[i].grade[2]>>ans[i].grade[3];
        ans[i].grade[0] = (ans[i].grade[1] + ans[i].grade[2] + ans[i].grade[3])/3;
    }
    for(int i=0;i<4;i++){
        now = i;
        sort(ans, ans+N, cmp);
        R[ans[0].ID][i] = 1;
        for(int j=1;j<N;j++){
            if(ans[j].grade[i] == ans[j-1].grade[i]) 
                R[ans[j].ID][i] = R[ans[j-1].ID][i];
            else    
                R[ans[j].ID][i] = j+1;
        }
    }
    int ID;
    for(int i=0;i<M;i++){
        cin>>ID;
        if(!R[ID][0]) cout<<"N/A\n";
        else{
            int min = R[ID][0], k = 0;
            for(int j=1;j<4;j++){
                if(min > R[ID][j]){
                    min = R[ID][j];
                    k = j;
                }
            }
            cout<<min<<" "<<aa[k]<<endl;
        }
    }
    system("pause");
}  