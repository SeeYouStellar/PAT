/*
 * @Author: xinyu Li
 * @Date: 2022-03-05 20:55:37
 * @LastEditTime: 2022-03-05 20:55:37
 * @Description: 
 * @FilePath: \helloworld\PTA\A1166.cpp
 * chaos is a ladder
 */
#include <bits/stdc++.h>
using namespace std;

int n, m, k, t;
unordered_map<int, bool> heads;

int judge(vector<int> &arrange) {
    // -1: need help; 0: ok; other number invite people;
    int len = t;
    for (int i = 0; i < len - 1; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (!heads[arrange[i] * 1000 + arrange[j]]) {
                return -1;
            }
        }
    }
    unordered_set<int> st(arrange.begin(), arrange.end());
    // 寻找是否还有额外共同的朋友
    for (int i = 1; i <= n; ++i) {
        if (st.find(i) != st.end()) continue;
        bool b = true;
        for (int &h : arrange) {
            if (!heads[h * 1000 + i]) {
                b = false;
                break;
            }
        }
        if (b) return i;
    }
    return 0;
}

int main() {
    scanf("%d%d", &n, &m);
    int t1, t2;
    for (int i = 0; i < m; ++i) {
        cin >> t1 >> t2;
        heads[t1 * 1000 + t2] = true;
        heads[t2 * 1000 + t1] = true;
    }
    scanf("%d", &k);
    for (int i = 1; i <= k; ++i) {
        cin >> t;
        vector<int> arrange(t);
        for (int j = 0; j < t; ++j) {
            cin >> arrange[j];
        }
        int res = judge(arrange);
        if (res == 0) printf("Area %d is OK.\n", i);
        else if (res == -1) printf("Area %d needs help.\n", i);
        else printf("Area %d may invite more people, such as %d.\n", i, res);
    }
    return 0;
}