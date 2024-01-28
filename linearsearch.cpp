#include<iostream>
using namespace std;
int linearSearch(int arr[],int size,int key){
    for (int i = 0; i < size; i++)
    {
        if(arr[i]==key){
             return i;
        }
    }
    return -1;
}

int main(){
    int arr[10]={5,-7,10,7,1,9,6,51,4,8};
    cout<<"\n Enter Key:";
    int key;
    cin>>key;
    cout << "\n Check Location of the if its Founded: " << linearSearch(arr, sizeof(arr)/sizeof(arr[0]), key);
    return 0;
}
