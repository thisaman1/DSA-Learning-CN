#include<bits/stdc++.h>
using namespace std;
void insertionsort(int arr[],int size){
    int i,key,j;
    for(i=1;i<size;i++){
        key = arr[i];
        j= i-1;
        while(j>=0 and key<arr[j]){
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}
int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    insertionsort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    delete []arr;
    return 0;
}