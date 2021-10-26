/*
 * @Author: xinyu Li
 * @Date: 2021-10-26 17:43:56
 * @LastEditTime: 2021-10-26 19:51:26
 * @Description: 
 * @FilePath: \helloworld\fuck\heap\A1098.cpp
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
void InsertSort()
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
        if(j+1 <= n && arr[j+1] > arr[j]) j = j + 1;
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

void HeapSort(){
    int n = N, cnt = 1;
    createHeap();
    for(int i=N;i>=1 && cnt>=0;i--){
        swap(arr[i], arr[1]);
        downadjust(1, i-1);
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
