/*
 * @Author: xinyu Li
 * @Date: 2022-03-05 20:52:29
 * @LastEditTime: 2022-03-05 20:52:29
 * @Description: 
 * @FilePath: \helloworld\PTA\A1128.cpp
 * chaos is a ladder
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
    int k, n;
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> n;
        vector<int> v(n);
        bool result = true;
        for (int j = 0; j < n; j++) {
            cin >> v[j];
            for (int t = 0; t < j; t++) {
                if (v[j] == v[t] || abs(v[j]-v[t]) == abs(j-t)) {
                    result = false;
                    break;
                }
            }
        }
        cout << (result == true ? "YES\n" : "NO\n");
    }
    return 0;
}