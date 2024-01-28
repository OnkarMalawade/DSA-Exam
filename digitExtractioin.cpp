#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include "LinkedList.h"
using namespace std;
#define bucketsize 10
LinkedList* bucket[bucketsize];
unsigned long DigitextrHash(unsigned long keyval,int* extr){
	unsigned long tempval=keyval;
	int val[3];
	for(int i=0;i<=6-extr[0];i++){
		val[0]=tempval%10;
		tempval=tempval/10;
	}
	tempval=keyval;
	for(int i=0;i<=6-extr[1];i++){
		val[1]=tempval%10;
		tempval=tempval/10;
	}
	tempval=keyval;
	for(int i=0;i<=6-extr[2];i++){
		val[2]=tempval%10;
		tempval=tempval/10;
	}
	return((val[0]*100)+(val[1]*10)+val[2])%100;
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
		k=DigitextrHash(keyArray[i],extr);
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

