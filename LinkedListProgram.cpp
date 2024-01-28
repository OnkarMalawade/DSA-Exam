#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node* next;
};
struct node* head=NULL;
struct node* current=NULL;
void printList(){
	struct node* p=head;
	cout<<"\n [";
	while(p!=NULL){
		cout<<" "<<p->data<<" ";
		p=p->next;
	}
	cout<<"]";
}
void insertatBegin(int data){
	struct node* lk=(struct node*)malloc(sizeof(struct node));
	lk->data=data;
	lk->next=head;
	head=lk;	
}
void deleteatBegin(){
	head=head->next;
}
void reverseList(struct node** head){
	struct node* prev=NULL,*cur=*head,*tmp;
	while(cur!=NULL){
		tmp=cur->next;
		cur->next=prev;
		prev=cur;
		cur=tmp;
	}
	*head=prev;
}
int main(){
	insertatBegin(12);
	insertatBegin(22);
	insertatBegin(30);
	insertatBegin(44);
	insertatBegin(50);
	cout<<"\n Linked list: ";
	printList();
	deleteatBegin();
	cout<<"\n After deletion Linked list: ";
	printList();
	reverseList(&head);
	cout<<"\n Reversed Linked list: ";
	printList();	
}


