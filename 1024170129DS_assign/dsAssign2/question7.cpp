//count the number of inversions
#include<iostream>
using namespace std;
int main(){
    int i;int size;int target;int j;int a;
    cout<<"enter size ";
    cin>>size;
    int arr1[size];
    cout<<"enter the elements ";
    for(i=0;i<size;i++){
        cin>>arr1[i];
    } int count=0 ;
    for(i=0;i<size;i++){
       for(j=i+1;j<size;j++){
        if(arr1[i]>arr1[j]){
            count=count+1;
        }
       }
    }
    cout<<" the number of inversions is "<<count;
return 0;
}