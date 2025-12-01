
#include <iostream>
using namespace std;
int main(){
int i;int size;int target;int a;
    cout<<"enter size ";
    cin>>size;
    int arr1[size];
    cout<<"enter the elements in ascending order";
    for(i=0;i<size;i++){
        cin>>arr1[i];
    }
    cout<<"enter the target";
    cin>>target;
    int start=0;
    int end=size-1;
    int mid=start+(end-start)/2;
    while(start<=end){
        if(arr1[mid]==target){
            cout<<"number is found at index "<<mid;
        
            break;
        }
        else
        if(arr1[mid]>target){
            end =mid-1;
        }
        if(arr1[mid]<target){
            start=mid+1;
        }
        mid=start+(end-start)/2;
    }

    if(arr1[mid]!=target){
        cout<<"not present";
    }



    return 0;
}