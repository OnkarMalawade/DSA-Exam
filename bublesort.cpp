 #include<iostream>
 using namespace std;
 void bubblesort(int arr[],int n){
    for(int i=1;i<n;i++){
        for (int j = 0; j < n-i; j++)
        {
            if (arr[j]>arr[j+1])
            {
              int temp = arr[j];
              arr[j] = arr[j+1];
              arr[j+1] = temp;
            }
        }
    }
 }
 int main(){
    int arr[6]={10,1,7,6,9,14};
    bubblesort(arr,6);
    for(int i=0;i<6;i++){
        cout<< arr[i]<<" ";
    }
    return 0;
 }
