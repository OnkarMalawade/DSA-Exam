#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data,key;
	struct node *next;
	struct node *prev;
};
struct node * head=NULL;
struct node * last=NULL;
struct node * current=NULL;
bool isEmpty(){
	return head==NULL;
}
void printList(){
	struct node* ptr=head;
	while(ptr!=NULL){
		cout<<" "<<ptr->key<<"["<<ptr->data<<"]";
		ptr=ptr->next;
	}
}
void insertFirst(int key,int data){
	struct node * link=(struct node*)malloc(sizeof(struct node));
	link->key=key;
	link->data=data;
	if(isEmpty()){
		last=link;
	}	
	else{
		head->prev=link;
	}
	link->next=head;
	head=link;
}
struct node* deleteFirst(){
	struct node* templink=head;
	if(head->next==NULL){
		last=NULL;
	}
	else{
		head->next->prev=NULL;
	}
	head=head->next;
	return templink;
}
//void reverseList(struct node** head){
//	struct node * prev=NULL,*cur=*head,*tmp;
//	while(cur!=NULL){
//		tmp=cur->next;
//		cur->next=prev;
//		prev=cur;
//		cur=tmp;
//	}
//	head=prev;
//}
int main(){
	insertFirst(1,10);
	insertFirst(2,20);
	insertFirst(3,30);
	insertFirst(4,1);
	insertFirst(5,40);
	insertFirst(6,56);
	cout<<"\n Double Linked list: ";
	printList();
	deleteFirst();
	cout<<"\n After deletion Double Linked list: ";
	printList();
//	reverseList(&head);
//	cout<<"\n Reversed Linked list: ";
//	printList();	
}


