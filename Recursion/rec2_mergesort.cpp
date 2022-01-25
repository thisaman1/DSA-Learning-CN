#include <iostream>
using namespace std;
void merge(int arr[],int start,int mid,int end){
    int temp[end-start];
    int i=start;
    int j=mid+1;
    int k=0;
    while(i<=mid and j<=end){
        if(arr[i]<arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++]= arr[j++];
        }
    }
    if(i<=mid){
        while(i<=mid){
            temp[k++]=arr[i++];
        }
    }
    else if(j<=end){
        while(j<=end){
            temp[k++]= arr[j++];
        }
    }
    k=0;
    for(int x=start;x<=end;x++){
        arr[x] = temp[k++];
    }
}
void merge_sort(int arr[],int start,int end){
    if(start>=end)
        return;
    
    int mid = (start+end)/2;
    merge_sort(arr,start,mid);
    merge_sort(arr,mid+1,end);
    merge(arr,start,mid,end);
}

int main() {
	// your code goes here
	int n;
	cin>>n;
	int* arr = new int[n];
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	}
	merge_sort(arr,0,n-1);
	for(int i=0;i<n;i++){
	    cout<<arr[i]<<" ";
	}
	return 0;
}
