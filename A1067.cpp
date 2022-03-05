/*
 * @Author: xinyu Li
 * @Date: 2022-03-05 20:47:04
 * @LastEditTime: 2022-03-05 20:47:05
 * @Description: 
 * @FilePath: \helloworld\PTA\A1067.cpp
 * chaos is a ladder
 */
#include <iostream>
using namespace std;
int main() {
    int n, t, cnt = 0, a[100010];
    cin >> n;
    for(int i = 0; i < n; i++){
    	cin >> t;
    	a[t] = i;
    }
    for(int i = 1; i < n; i++) {
        if(i != a[i]) {
            while(a[0] != 0) {
                swap(a[0],a[a[0]]);
                cnt++;
            }
            if(i != a[i]) {
                swap(a[0],a[i]);
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}