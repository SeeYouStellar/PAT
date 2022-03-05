/*
 * @Author: xinyu Li
 * @Date: 2022-03-05 20:47:43
 * @LastEditTime: 2022-03-05 20:47:43
 * @Description: 
 * @FilePath: \helloworld\PTA\A1074.cpp
 * chaos is a ladder
 */
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 100010;

struct Node{
    int add, data, next;
} nodes[maxn];

int main() {
#if ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    int head, N, K, add;
    scanf("%d %d %d", &head, &N, &K);
    for(int i = 0; i < N; i++) {
        scanf("%d", &add);
        scanf("%d %d", &nodes[add].data, &nodes[add].next);
    }
    vector<pair<int, int>> linked;
    while(head != -1) {
        linked.push_back(make_pair(head, nodes[head].data));
        head = nodes[head].next;
    }
    N = linked.size();
    for(int i = 0; i < N / K; i++) {
        reverse(linked.begin()+i*K, linked.begin()+(i+1)*K);
    }
    for(auto it = linked.begin(); it != linked.end(); it++) {
        if(it != linked.end() - 1) {
            printf("%05d %d %05d\n", it->first, it->second, (it+1)->first);
        } else {
            printf("%05d %d %d\n", it->first, it->second, -1);
        }
    }
    return 0;
}