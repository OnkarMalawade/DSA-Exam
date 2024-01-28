#include<iostream>
#include<conio.h>
using namespace std;
int binarySearch(int a[],int size,int key){
	int top,bottom,mid;
	bool found_flag;
	top=0;
	bottom=size-1;
	found_flag=false;
	while(top<=bottom && found_flag==false){
		mid=(top+bottom)/2;
		if(a[mid]>key){
			bottom=mid-1;
		}
		else if(a[mid]<key){
			top=mid+1;
		}
		else{
			found_flag=true;
		}
	}
	if(found_flag==true){
		return 1;
	}else{
		return 0;
	}
}
int main(){
	int size,key;
	bool flag=1;
	cout<<"Enter size: ";
	cin>>size;
	int a[size];
	cout<<"Enter elements: ";
	for(int i=0;i<size;i++){
		cin>>a[i];
	}
	cout<<"Enter element to be search: "<<endl;
	cin>>key;
	flag=binarySearch(a,size,key);
	if(flag==1){
		cout<<"element found...";	
	}	
	else{
		cout<<"element not found...";
	}	
	return 0;
}
