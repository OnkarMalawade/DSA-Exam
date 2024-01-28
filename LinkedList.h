#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
class LinkedList{
	unsigned long data;
	LinkedList* next;
	LinkedList();
	LinkedList(unsigned long);
	friend LinkedList* insert(LinkedList* head,unsigned long dataval);
	friend void display(LinkedList* head);
};
LinkedList::LinkedList(){
	data=0;
	next=NULL;
}
LinkedList::LinkedList(unsigned long dataval){
	data=dataval;
	next=NULL;
}
LinkedList* insert(LinkedList* head,unsigned long dataval){
	LinkedList* temp=new LinkedList(dataval);
	LinkedList* trav=head;
	if(trav!=NULL){
		while(trav->next!=NULL){
			trav=trav->next;
		}
		trav->next=temp;
	}
	else{
		head=temp;
	}
	return head;
}
void display(LinkedList*head){
	LinkedList* trav=head;
	if(trav==NULL){
		return;
	}
	else if(trav->next==NULL){
		cout<<trav->data<<" ";
	}
	else{
		while(trav!=NULL){
			cout<<trav->data<<" ";
			trav=trav->next;
		}
	}
}
