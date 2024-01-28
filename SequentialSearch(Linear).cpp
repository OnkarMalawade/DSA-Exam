#include<iostream>
#include<conio.h>
using namespace std;
int sequentialSearch(int a[],int size,int key){
	string flag="false";
	for(int i=0;i<size;i++){
		if(a[i]==key){
			flag="true";
		}
	}
	if(flag=="true"){
		return 1;
	}
	else{
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
	cout<<"Enter element to be search: ";
	cin>>key;
	flag=sequentialSearch(a,size,key);
	if(flag==1)
		cout<<"element found...";
	else	
		cout<<"element not found...";
	return 0;
}
