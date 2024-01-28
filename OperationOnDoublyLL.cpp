#include <iostream>
#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

int i = 0;

struct node {
	int key;
	struct node* prev;
	struct node* next;
} ;
node* head = NULL;
node* first = NULL;
node* temp = NULL;
node* tail = NULL;

bool isEmpty(){
	return head == NULL;
}
void addnode(int k)
{
	node* ptr = (node*)malloc(sizeof(node));
	ptr->key = k;
	ptr->next = NULL;
	ptr->prev = NULL;
	if (isEmpty() == true) {
		head = ptr;
		first = head;
		tail = head;
	}
	else {
		temp = ptr;
		first->next = temp;
		temp->prev = first;
		first = temp;
		tail = temp;
	}
	i++;
}
void traverse() // PrintList
{
	node* ptr = head;
	while (ptr != NULL) {
		cout <<" " << ptr->key;
		ptr = ptr->next;
	}

	cout <<"\n";
}
void insertatbegin(int k)
{
	node* ptr = (node*)malloc(sizeof(node));
	ptr->key = k;
	ptr->next = NULL;
	ptr->prev = NULL;
	if (isEmpty() == true) { // or head == NULL
		first = ptr;
		first = head;
		tail = head;
	}
	else {
		temp = ptr;
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
	i++;
}

void insertatend(int k)
{
	node* ptr = (node*)malloc(sizeof(node));
	ptr->key = k;
	ptr->next = NULL;
	ptr->prev = NULL;
	if (head == NULL) { // isEmpty() == true
		first = ptr;
		first = head;
		tail = head;
	}
	else {
		temp = ptr;
		temp->prev = tail;
		tail->next = temp;
		tail = temp;
	}
	i++;
}

void insertatpos(int k, int pos)
{
	if (pos < 1 || pos > i + 1) {
		cout <<"Please enter a valid position!!!\n";
	}
	else if (pos == 1) {
		insertatbegin(k);
	}
	else if (pos == i + 1) {
		insertatend(k);
	}
	else {
		node* src = head;

		while (pos--) {
			src = src->next;
		}

		node **da, **ba;
		node* ptr = (node*)malloc(sizeof(node));
		ptr->next = NULL;
		ptr->prev = NULL;
		ptr->key = k;
		ba = &src;
		da = &(src->prev);
		ptr->next = (*ba);
		ptr->prev = (*da);
		(*da)->next = ptr;
		(*ba)->prev = ptr;
		i++;
	}
}

void delatbegin()
{
	head = head->next;
	i--;
}

void delatend()
{
	tail = tail->prev;
	tail->next = NULL;
	i--;
}

void delatpos(int pos)
{
	if (pos < 1 || pos > i + 1) {
		cout <<"Please enter a valid position\n";
	}
	else if (pos == 1) {
		delatbegin();
	}
	else if (pos == i) {
		delatend();
	}
	else {
		node* src = head;
		pos--;

		while (pos--) {
			src = src->next;
		}

		node **pre, **aft;
		pre = &(src->prev);
		aft = &(src->next);

		(*pre)->next = (*aft);
		(*aft)->prev = (*pre);

		i--;
	}
}
void search(int data){
	struct node* trav = head;
	bool flag = true;
	while(trav != NULL && flag == true){
		if(trav -> key == data){
			flag = false;
			break;
		}
		else{
			trav = trav -> next;
		}
	}
	if(flag == false){
		cout << "Element Found!";
	}
	else{
		cout << "Element Not Found!";
	}
}
int main()
{
	addnode(2);
	addnode(4);
	addnode(9);
	addnode(1);
	addnode(21);
	addnode(22);

	cout <<"Linked List: ";
	traverse();
	
	cout << "\nCount of the Doubly Linked List: " << i;
	cout <<"\n";

	cout <<"\nLinked List after inserting at beginning: ";
	insertatbegin(1);
	traverse();

	insertatend(0);
	cout <<"Linked List after inserting 0 at end: ";
	traverse();

	cout << "\nDo you want to insert Element in the Linked List(Y/N): ";
	char ch;
	cin >> ch;
	switch(ch){
		case 'Y':
			int a, b;
			cout <<"\nPlease Enter Data want to be insert:";
			cin >> a;
			cout <<"\nPlease Enter Position want to be insert:";
			cin >> b;
			cout <<"\nLinked List after inserting "<< a <<" after "<< b <<"rd Node: ";
			insertatpos(a, b);
			traverse();
			break;
		case 'N':
			cout << "\nThank You!!!";
			traverse();
			break;
		default:
			exit(0);
	}
	
	int j;
	cout << "\nIf you want to search in the Linked list: \n  Press 1 \n  Stop to Search in Linked List: Press Any Number: ";
	cin >> j;
	while(j == 1){
		cout<<"\nSearching Element in the Linked list: ";
		int n;
		cin >> n;
		search(n);
		cout << "\nSearching Operation of Linked List want perform Again Press 1: ";
		cin >> j;
	}
	
	cout <<"\n \n";

	delatbegin();
	cout <<"Linked List after deleting node at beginning: ";
	traverse();
	
	delatend();
	cout <<"Linked List after deleting node at end: ";
	traverse();

	cout << "\nEnter the element position you want Delete: ";
	int d;
	cin >> d;
	cout <<"Linked List after deleting node at position "<< d <<": ";
	delatpos(d);
	traverse();

	return 0;
}
