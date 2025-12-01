#include<iostream>
using namespace std;
int main(){
    int arr[3][3];
    //row wise input 
    cout<<" enter the matrix elements ";
    for(int row=0;row<3;row++){
         for(int col=0;col<3;col++){
            cin>>arr[row][col];
        }
     }

     cout<<" the entered 2Darray is<<endl ";

for(int row=0;row<3;row++){
    for(int col=0;col<3;col++){
        cout<<arr[row][col]<<" ";

    }
    cout<<endl;
}
//rowise sum
for(int i=0;i<3;i++){
    int rowsum=0;
    for(int j=0;j<3;j++){
          rowsum= rowsum+arr[i][j];
    } cout<<" sum of " << i <<" row is "<<rowsum<<endl;
}
//column wise sum
for(int i=0;i<3;i++){
    int sum=0;
    for(int j=0;j<3;j++){
          sum= sum+arr[j][i];
    } cout<<" sum of " << i <<" column is "<<sum<<endl;
}
return 0;
}