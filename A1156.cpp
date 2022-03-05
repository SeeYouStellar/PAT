/*
 * @Author: xinyu Li
 * @Date: 2022-03-05 20:53:52
 * @LastEditTime: 2022-03-05 20:53:52
 * @Description: 
 * @FilePath: \helloworld\PTA\A1156.cpp
 * chaos is a ladder
 */
#include <iostream>
using namespace std;
bool isPrime(int x)//判断是不是素数
{
    if (x < 3)
        return x > 1;
    for (int i = 2; i*i <= x; ++i)
        if (x%i == 0)
            return false;
    return true;
}
int isSexyPrimes(int x)//判断满不满足题目要求
{
    if (isPrime(x))
    {
        bool fL = isPrime(x - 6), fR = isPrime(x + 6);
        if (fL || fR)
            return fL ? x - 6 : x + 6;
    }
    return -1;
}
int main()
{
    int n;
    cin >> n;
    int res = isSexyPrimes(n);
    if (res > 0)
    {
        printf("Yes\n");
        printf("%d\n", res);
    }
    else
    {
        printf("No\n");
        for (int i = n + 1; i < INT32_MAX; ++i)//另寻找大数，直至满足要求
        {
            if (isSexyPrimes(i) > 0)
            {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}