#include<iostream>
#include<bits/stdc++.h>
#include<stdlib.h>
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
//count
int countNode(){
	struct node* temp = head;
	int i = 0;
	while(temp != NULL){
		i++;
		temp = temp -> next;
	}
	return i;
}
//insert
void insertatBegin(int data){
	struct node* lk=(struct node*)malloc(sizeof(struct node));
	lk->data=data;
	lk->next=head;
	head=lk;	
}
void insertLast(int data){
	struct node* temp = new node;
	temp -> data = data;
	temp -> next = NULL;
	struct node* trav = head;
	if(trav != NULL){
		while(trav -> next != NULL){
			trav = trav -> next;
		}
		trav -> next = temp;
	}
	else{
		head = temp;
	}
}
void insertAt(int pos, int data){
	struct node* temp = new node;
	struct node* trav = head;
	int k = 1;
	int cnt = countNode();
	if(head == NULL){
		insertatBegin(data);
	} 
	else{
		if(pos > cnt){
			cout << "Wrong Position!";
		}
		else{
			while(k== pos-1){
				trav = trav -> next;
				k++;
			}
			temp -> data = data;
			temp -> next = trav->next;
			trav->next = temp;
		}
	}
}
//remove
void removeFirst(){
	head=head->next;
}
void removeAt(int pos){
	int node_cnt = countNode();
	if(node_cnt < pos){
		cout << "Wrong Position!"; 
	}
	else{
		struct node* trav = head;
		int k = 1;
		while(k < pos-1){
			trav = trav -> next;
			k++;
		}
		struct node* temp = trav -> next;
		trav->next = temp->next;
	}
}
void removeLast(){
	struct node* trav = head;
	if(trav->next == NULL){
		head = NULL;
	}
	else{
		while(trav->next->next != NULL){
			trav = trav -> next;
		}
		struct node* temp = trav->next;
		trav -> next = NULL;
		temp = NULL;
	}
}
//reverse
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
//sort
void sort(){
	struct node*sort_head = head;
	struct node* trav = head;
	while(trav !=NULL){
		if(trav->data < sort_head->data){
			int temp = trav->data;
			trav->data= sort_head->data;
			sort_head->data =temp;
		}
		trav = trav->next;
	}
	sort_head = sort_head->next;
}
//searching
void search(int data){
	struct node* trav = head;
	bool flag = false;
	while(trav != NULL && flag == false){
		if(trav -> data == data){
			flag = true;
			break;
		}
		else{
			trav = trav -> next;
		}
	}
	if(flag == true){
		cout << "Element Found!";
	}
	else{
		cout << "Element Not Found!";
	}
}
int main(){
	insertatBegin(12);
	insertatBegin(22);
	insertatBegin(30);
	insertatBegin(44);
	insertatBegin(50);
	cout<<"\n Linked list: ";
	printList();
	insertLast(10);
	cout<<"\nSearching Element in the Linked list: ";
	int n;
	cin >> n;
	search(n);
	cout<<"\n Insert At Last Linked list: ";
	printList();
	insertAt(2,90);
	cout<<"\n Insert At Linked list: ";
	printList();
	removeFirst();
	cout<<"\n After Remove first Node Linked list: ";
	printList();
	removeLast();
	cout<<"\n After Remove Last Node Linked list: ";
	printList();
	removeAt(3);
	cout<<"\n After Remove At position Node Linked list: ";
	printList();
	
	insertAt(1,10);
	cout<<"\n Insert At Linked list: ";
	printList();
	cout<<"\n Reversed Linked list: ";
	reverseList(&head);
	printList();
	sort();
	cout<<"\n Sorted Link List";
	printList();
	cout << "\n Count of the Node is " << countNode();	
	/*cout<<"\nSearching Element in the Linked list: ";
	int n;
	cin >> n;
	search(n);
	*/
}



