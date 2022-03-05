/*
 * @Author: xinyu Li
 * @Date: 2022-03-05 20:57:53
 * @LastEditTime: 2022-03-05 20:57:54
 * @Description: 
 * @FilePath: \helloworld\PTA\Advance2021Spring\7_3.cpp
 * chaos is a ladder
 */
/*
 * @Author: xinyu Li
 * @Date: 2022-03-01 11:06:06
 * @LastEditTime: 2022-03-01 11:59:37
 * @Description: 
 * @FilePath: \helloworld\3.cpp
 * chaos is a ladder
 */
#include <bits/stdc++.h>
using namespace std;
int n, m, seq[1010];
map<int, int> mm;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>seq[i];
        for(int j=i;j>1;j/=2){
            if(seq[j]>seq[j/2]){
                swap(seq[j], seq[j/2]);
            }else
                break;
        }
    }
    for(int i=1;i<=n;i++) mm[seq[i]] = i;
    getchar();
    char* s;
    string ss;
    for(int i=0;i<m;i++){
        getline(cin, ss);
        s = (char*)ss.c_str();
        int a, b;
        if(ss.find("root")!=string::npos){
            sscanf(s, "%d is the root", &a);
            if(a==seq[1])
                cout<<1;
            else 
                cout<<0;
          
        }else if(ss.find("siblings")!=string::npos){
            sscanf(s, "%d and %d are siblings", &a, &b);
            a = mm[a];
            b = mm[b];
            if(a/2 == b/2) cout<<1;
            else cout<<0;
        }else if(ss.find("parent")!=string::npos){
            sscanf(s, "%d is the parent of %d", &a, &b);
            a = mm[a];
            b = mm[b];
            
            if(b/2 == a) cout<<1;
            else cout<<0;
        }else if(ss.find("left")!=string::npos){
            sscanf(s, "%d is the left child of %d", &a, &b);
            
            a = mm[a];
            b = mm[b];
            if(a/2 == b && a%2==0) cout<<1;
            else cout<<0;
        }else if(ss.find("right")!=string::npos){
            sscanf(s, "%d is the right child of %d", &a, &b);
            
            a = mm[a];
            b = mm[b];
            if(a/2 == b && a%2==1) cout<<1;
            else cout<<0;
            
        }
    }
    system("pause");
}