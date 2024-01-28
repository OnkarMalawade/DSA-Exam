#include<iostream>
#include "LinkedList.h"
using namespace std;
#define bucketsize 100
LinkedList* bucket[bucketsize];
unsigned long foldshiftHashing(unsigned long keyval){
	unsigned long tempval=keyval;
	int val[3];
	val[0]=tempval%100;
	tempval=tempval/100;
	val[1]=tempval%100;
	tempval=tempval/100;
	val[2]=tempval%100;
	tempval=tempval/100;
	return ((val[0]+val[1]+val[2])%100);
}

int main(){
	int i,num,extr[3];
	unsigned long k;
	cout<<"Enter the no of values to be inserted:";
	cin>>num;
	cout<<"Enter the digit you want to extract:";
	for(int i=0;i<6;i++){
		cin>>extr[i];
	}
	unsigned long keyArray[num];
	cout<<"enter six digit values: \n";
	for(i=0;i<num;i++){
		cin>>keyArray[i];
	}
	for(i=0;i<num;i++){
		k=foldshiftHashing(keyArray[i]);
		bucket[k]=insert(bucket[k],keyArray[i]);
	}
	for(k=0;k<bucketsize;k++){
		cout<<"\n Bucket ["<<k<<"]:\t";
		display(bucket[k]);
		cout<<endl;
	}
	getch();
	return 0;
	
}


