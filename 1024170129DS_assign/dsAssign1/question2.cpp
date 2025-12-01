//remove duplicates
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
    for(j=0;j<size-i;j++){
        if(arr1[j]>arr1[j+1]){
            int temp = arr1[j+1];
            arr1[j+1]=arr1[j];
            arr1[j]=temp;
        }
    }
} 
for(i=0;i<size;i++){
    if(arr1[i]==arr1[i+1]){
        for(j=i;j<size;j++){
            arr1[j]=arr1[j+1];
        }size--;
    }
}
for(a=0;a<size;a++){
    cout<<arr1[a]<<" ";
}
    return 0;
}