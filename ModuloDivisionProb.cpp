#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define bucketsize 10
int ModuleDivHashing(unsigned long keyval,unsigned long fact){
	return(keyval%fact);
}
int main(){
	int i,num,fact,k;
	int bucket[bucketsize];
	cout<<"Enter the no of values to be inserted:";
	cin>>num;
	cout<<"Enter the modulo division factor:";
	cin>>fact;
	int keyArray[num];
	cout<<"enter values: \n";
	for(i=0;i<num;i++){
		cin>>keyArray[i];
	}
	for(i=0;i<bucketsize;i++){
		bucket[i]=-999;
	}
	for(i=0;i<num;i++){
		k=ModuleDivHashing(keyArray[i],fact);
		while(bucket[k]!= -999){
			k++;
		}
		bucket[k]=keyArray[i];
	}
	for(k=0;k<bucketsize;k++){
		cout<<"\n Bucket["<<k<<"]\t";
		cout<<bucket[k]<<endl;
	}
	return 0;
	
}
											
