//menu problem
#include <iostream>
using namespace std;
int arr[100];int size=0;
void create(){
    int i;
  cout<<" Enter the size of the array "<<endl;
  cin>>size;
  cout<<" Enter the elements of the array "<<endl;
  for(i=0;i<size;i++){
    cin>>arr[i];
  }
}

void insert(){
    int value;int position;
    cout<<" enter the value you want to insert ";
    cin>>value;
    cout<<" enter the position at which you want to insert ";
    cin>>position;
    for(int i=size-1;i>=position;i--){
        arr[i+1]=arr[i]; }
         arr[position]= value;
         size=size+1;

}
void deleteelement(){
    int positiondelete;
    cout<<"enter the position of the element you want to delete ";
    cin>>positiondelete;
    for(int i=positiondelete;i<size-1;i++){
        arr[i]=arr[i+1];
    }
    size--;

}
void display(){
    cout<<"The entered array is ";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}
void linearsearch(){
cout<<"enter the target";int target;int a;
    cin>>target;
    for( int i=0;i<size;i++){
        if(arr[i]==target){
            a=1;break;
        } 
        else{
            a=2;
        }
    }
    if(a==1){
        cout<<"found";

    }else{
        cout<<"not found ";
    }

}
int main(){
 int menu;do{
cout<<"\n MENU "<<endl;
cout<<"1.Create"<<endl;
cout<<"2.Display"<<endl;
cout<<"3.Insert"<<endl;
cout<<"4.Delete"<<endl;
cout<<"5.Linear Search"<<endl;
cout<<"6.Exit"<<endl;
cout<<"Select a menu item"<<endl;
cin>>menu;
switch(menu){
    case 1: create();
    break;
    case 2:display();
    break;
    case 3: insert();break;
    case 4 : deleteelement();break;
    case 5: linearsearch();break;
     


}}while (menu!=6);


    return 0;
}