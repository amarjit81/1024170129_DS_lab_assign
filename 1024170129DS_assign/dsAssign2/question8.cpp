//find the number of distinct elements
#include<iostream>
using namespace std;
int main(){
    int i;int size;int target;int j;int a;int count =0;
    cout<<"enter size ";
    cin>>size;
    int arr1[size];
    cout<<"enter the elements ";
    for(i=0;i<size;i++){
        cin>>arr1[i];
    }

for(i=0;i<size-1;i++){
    for(j=0;j<size-i;j++){
        if(arr1[j]>arr1[j+1]){
            int temp = arr1[j+1];
            arr1[j+1]=arr1[j];
            arr1[j]=temp;
        }
    }}
    for(i=0;i<size;i++){
        if(arr1[i]==arr1[i+1]){
count++;
        }
    }
    
    cout<<"the number of distinct elements are "<<size-count;
    return 0;

}