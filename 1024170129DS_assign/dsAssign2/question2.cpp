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
    }
     
for(i=0;i<size-1;i++){
     bool x=0;
    for(j=0;j<size-i-1;j++){
        if(arr1[j]>arr1[j+1]){
            x=1;
            int temp = arr1[j];
            arr1[j]=arr1[j+1];
            arr1[j+1]=temp;
        }
    }  if(x==0){ break;}
}
for(a=0;a<size;a++){
    cout<<arr1[a];
}
    return 0;
}