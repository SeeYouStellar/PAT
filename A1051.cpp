/*
 * @Author: xinyu Li
 * @Date: 2022-03-05 20:45:45
 * @LastEditTime: 2022-03-05 20:45:45
 * @Description: 
 * @FilePath: \helloworld\PTA\A1051.cpp
 * chaos is a ladder
 */
    #include<bits/stdc++.h>
    using namespace std;
    int M, N, K, st[1010];
    int main()
    {
        cin>>M>>N>>K;
        stack<int> s;
        for(int i=0;i<K;i++){
            for(int j=0;j<N;j++)
                cin>>st[j];
            while(!s.empty()) s.pop();
            int sttop = 0, flag = 1;
            for(int j=1;j<=N;j++){
                s.push(j);
                if(s.size()>M){
                    flag = 0;
                    break;
                }
                while(!s.empty() && s.top() == st[sttop]){
                    s.pop();
                    sttop++;
                }
            }
            if(flag && s.empty()) cout<<"YES\n";
            else cout<<"NO\n";

        }


    }
