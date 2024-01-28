#include<iostream>
#include<conio.h>
#include<stdlib.h>
#define QUEUESIZE 10

using namespace std;

class queue{
	private:
		int arr[QUEUESIZE];
		int  q_front;
		int q_rear;
	public:
		queue();
		void insertElement(int x);
		int deleteElement();
		bool isEmpty();
		bool isFull();
		int size();
		void display();
};

queue::queue(){
	q_rear = -1;
	q_front = -1;
}

void queue::insertElement(int val){
	if(isEmpty()==true)
	{
		q_rear =0;
		q_front =0;
		arr[q_rear] = val;
	}
	else
	{
		q_rear = (q_rear+1)%QUEUESIZE;
		arr[q_rear] =val;
	}
}

int queue::deleteElement(){
	int q_element ;
	if(q_front==q_rear){
		q_element = arr[q_front];
		q_rear = -1;
		q_front = -1;
	}
	else
	{
		q_element = arr[q_front];
		q_front = (q_front+1)%QUEUESIZE;
	}
	return q_element;
}

bool queue::isEmpty(){
	if(q_rear==-1){
		return true;
	}
	else
	{
		return false;
	}
}

bool queue::isFull(){
	if((q_rear+1)%QUEUESIZE==q_front)
		return true;
	else
		return false;
}

int queue::size(){
	if(q_rear>q_front){
		return q_rear -q_front+1;
	}
	else
		return QUEUESIZE-q_rear-q_front+1;
}

void queue::display(){
	if(q_rear==-1)
	{
		cout<<"no element to display"<<endl;
	}
	cout<<"Elements in queue are:";
	for(int i=q_front;i!=q_rear;i=(i+1)%QUEUESIZE)
	{
		cout<<arr[i]<<" ";
	}
	cout<<arr[q_rear]<<" ";
	cout<<endl;
			
}
	
int main()
{
	queue myqueue;
	int val;
	int choice;
	while(1)
	{
		cout<<"1.Insert \n";
		cout<<"2.Delete \n";
		cout<<"3.Display \n";
		cout<<"4. Exit \n";
		cin>>choice;
		switch(choice)
		{
			case 1:
				if(myqueue.isFull()==false)
				{
					cout<<"Enter Value to Insert ";
					cin>>val;
					myqueue.insertElement(val);
				}
				else
				{
					cout<<"Queue is Full";
				}
				break;
			case 2:
				if(myqueue.isEmpty()==false)
				{
					val = myqueue.deleteElement();
					cout<<"Deleted element is "<<val<<" from the list"<<endl;
				}
				else
				{
					cout<<"Stack is Empty ";
				}
				break;
			case 3:
				if(myqueue.isEmpty()==false){
						myqueue.display();
				}
				else
				{
					cout<<"Queue is Empty";
				}
				break;
			case 4:
				exit(1);
				break;
			default:
				cout<<"Wrong Choice ";
				getch();
				return 0;
		}
	}
	getch();
	return 0;
}
