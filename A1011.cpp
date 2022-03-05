#include<bits/stdc++.h>
using namespace std;
int main()
{
    double ans[3][3];
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            cin>>ans[i][j];
    double max = 1.0;
    int maxi = 0, maxj = 0, maxk = 0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(ans[0][i]*ans[1][j]*ans[2][k] > max){
                    max = ans[0][i]*ans[1][j]*ans[2][k];
                    maxi = i;
                    maxj = j;
                    maxk = k;
                }
            }
        }
    }
    char maxii, maxjj, maxkk;
    if(maxi == 0) maxii = 'W';
    else if(maxi == 1) maxii = 'T';
    else maxii = 'L';
    if(maxj == 0) maxjj = 'W';
    else if(maxj == 1) maxjj = 'T';
    else maxjj = 'L';
    if(maxk == 0) maxkk = 'W';
    else if(maxk == 1) maxkk = 'T';
    else maxkk = 'L';
    cout<<maxii<<" "<<maxjj<<" "<<maxkk<<" ";
    printf("%.2f", (max*0.65-1)*2);
}