#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
struct node * head=NULL;
void display(){
	struct node* ptr;
	ptr=head;
	do{
		cout<<ptr->data<<" ";
		ptr=ptr->next;
	}while(ptr!=head);
}
void insert(int newdata){
	struct node * newnode=(struct node *) malloc(sizeof(struct node));
	struct node* ptr=head;
	newnode->data=newdata;
	newnode->next=head;
	if(head!=NULL){
		while(ptr->next!=head)
			ptr=ptr->next;
			ptr->next=newnode;
	}
	else{
		newnode->next=newnode;
		head=newnode;
	}
}
//void deleteFirst(){
//	struct node* templink=head;
//	if(head->next==NULL){
//		last=NULL;
//	}
//	else{
//		head->next->prev=NULL;
//	}
//	head=head->next;
//	return templink;
//}
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
	insert(3);
	insert(1);
	insert(7);
	insert(2);
	insert(9);
	cout<<"\n Circular Linked list: ";
	display();
	return 0;	
}


