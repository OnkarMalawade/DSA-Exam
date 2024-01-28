#include<iostream>
using namespace std;
int binarysearch(int arr[],int size,int key){
    int start=0;
    int end=size-1;
    int mid=start+(end-start)/2;
    while(start<=end){
        if(arr[mid]==key){
            return mid;
        }
        if(key>arr[mid])//goto right
        {
            start=mid+1;
        }
        else if(key<arr[mid])//goto left
        {
            end=mid-1;
        }
        mid=start+(end-start)/2;
    }
    return -1;
} /*
void bin2search(int arr[],int size, int key,int start,int end){
    //base case
    if(start>end){
        cout<<"Key Not Exits";
    }
    int mid = start+(end-start)/2;
    if(key == arr[mid]){
        cout<<"Key Found";
    }
    if(key > arr[mid]){
        bin2search(arr,size,key,mid+1,end);
    }
    if(key < arr[mid]){
        bin2search(arr,size,key,start,mid-1);
    }
    return ;
}*/
int main()
{
    int even[6]={1,3,5,6,7,9};
    int odd[5]={4,5,6,7,9};

    int Eindex=binarysearch(even,6,7);
    cout<<"\n Index of is "<<Eindex;
    
    int oindex=binarysearch(odd,5,7);
    cout<<"\n Index of is "<<oindex<<endl;

    bin2search(even,6,7,0,5);
    return 0;
}
