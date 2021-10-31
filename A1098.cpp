/*
 * @Author: xinyu Li
 * @Date: 2021-10-26 17:43:56
 * @LastEditTime: 2021-10-27 08:26:53
 * @Description: 
 * @FilePath: \helloworld\PTA\A1098.cpp
 * I am because you are
 */
#include<bits/stdc++.h>
using namespace std;
int arr[101] = {0}, N, flag, newarr[101] = {0}, tmp[101] = {0};
bool cmp(int* a, int* b)
{
    for(int i=1;i<=N;i++)
        if(a[i] != b[i]) return false; 
    return true;
}
void InsertSort()  //插入排序有两个循环，外层遍历整个序列，内层遍历i之前的序列
{
    int i = 2, cnt = 1;
    while(i <= N && cnt >= 0){
        int j = i;
        //while(tmp[j] < tmp[j-1] && j > 1) {swap(tmp[j], tmp[j-1]);j--;}   //这里可以直接用sort代替：sort(tmp+1, tmp+i+1)
        sort(tmp+1, tmp+i+1);
        i++;  
        if(!cnt) cnt--;
        if(cmp(tmp, newarr)) {flag = 0;cnt--;}
    } 
}
void downadjust(int i, int n){
    int j = i*2;
    while(j <= n){
        if(j+1 <= n && arr[j+1] > arr[j]) j = j + 1;  //当右节点存在且左节点值小于右节点值，就交换右节点
        if(arr[i] < arr[j]){
            swap(arr[i], arr[j]);
            i = j;
            j = i*2;
        }else break;
    }
}
void print(int* a){
    for(int i=1;i<=N;i++){
        cout<<a[i];
        if(i < N) cout<<" ";
    }
    cout<<endl;
}
void createHeap() //O(n)
{
    for(int i=N/2;i>=1;i--)
        downadjust(i, N);
}

void HeapSort(){  //交换-调整
    int n = N, cnt = 1;
    createHeap();
    for(int i=N;i>=1 && cnt>=0;i--){
        swap(arr[i], arr[1]); //交换
        downadjust(1, i-1);   //调整
        if(!cnt) cnt--;
        if(cmp(arr, newarr)) {flag = 1;cnt--;}
    }
}

int main()
{
    cin>>N;
    for(int i=1;i<=N;i++)
        cin>>arr[i];
    for(int i=1;i<=N;i++)
        cin>>newarr[i];
    memcpy(tmp, arr, sizeof(int)*(N+1));
    
    HeapSort();
    InsertSort();
    if(flag){
        cout<<"Heap Sort\n";
        print(arr);
    }else{
        cout<<"Insertion Sort\n";
        print(tmp);
    }
    system("pause");
}
