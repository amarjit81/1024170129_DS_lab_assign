#include<iostream>
using namespace std;
int main (){
    int i;int size;int target;int a; 
    cout<<"enter size ";
    cin>>size;
    int arr1[size];
    cout<<"enter the elements";
    for(i=0;i<size;i++){
        cin>>arr1[i];
    }
    for(i=0;i<size/2;i++){
         a=arr1[i];
       arr1[i]=arr1[size-1-i];
       arr1[size-1-i]=a;
       
    }
    for(i=0;i<size;i++){
       
        cout<<arr1[i]<<" ";
    }
    

    return 0;

}