#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int> &arr, int start, int mid, int end);


void mergesort(vector<int> &arr,int start, int end){
    if(start<end){
        int mid = start + (end-start)/2;
        mergesort(arr,start, mid);
        mergesort(arr,mid+1,end);
        merge(arr,start,mid,end);
        }
}
void merge(vector <int> &arr, int start, int mid, int end){
    vector <int> temp;
    int i = start;
    int j = mid+1;
    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=end){
        temp.push_back(arr[j]);
        j++;
    }
    for(int k=start;k<=end;k++){
        arr[k] = temp[k-start];
    }
}
int main(){
    vector <int> arr = {38,27,43,3,9,82,10};
    int n = arr.size();
    mergesort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}


