#include <iostream>
#include <conio.h>
#include <stdlib.h>
#define QUEUESIZE 5
using namespace std;
class queue{
	private:
		int arr[QUEUESIZE];
		int q_front;
		int q_rear;
	public:
		queue();
		void insertElement_rear(int x);
		void insertElement_front(int x);
		void deleteElement_rear();
		void deleteElement_front();
		bool is_empty();
		bool is_full();
		int size();
		void displayElement();
		
};
queue::queue()
{
	q_front=-1;
	q_rear=-1;
}
void queue::insertElement_front(int val)
{
	
}
void queue::insertElement_rear(int val)
{
	if(is_full()==true)
	{
		cout<<"Queue is Full , can not insert"<<endl;
	}
	else if (is_empty()==true)
	{
		q_rear=0;
		q_front=0;
		arr[q_rear]=val;
	}
	else
	{
		q_front=(q_front-1+QUEUESIZE)%QUEUESIZE;
		arr[q_front]=val;
	}
}
void queue::deleteElement_front()
{
	int q_element;
	q_element=arr[q_front];
	if(is_empty()==true)
	{
		cout<<"Queue is empty, can not delete" <<endl;
	}
	else if(q_front==q_rear)
	{
		q_element=arr[q_front];
		q_rear=-1;
		q_front=-1;
		cout<<"\n Delete Element is: "<<q_element<<endl;
	}
	else
	{
		q_element=arr[q_front];
		q_front=(q_front+1)%QUEUESIZE;
		cout<<"\n Deleted Element is: "<<q_element<<endl;
	}
}
void queue::deleteElement_rear()
{
	int q_element;
	q_element=arr[q_front];
	
	if(is_empty()==true)
	{
		cout<<"\n Queue is empty, can not delete"<<endl;
	}
	else if(q_front==q_rear)
	{
		q_element=arr[q_rear];
		q_rear=-1;
		q_front=-1;
		cout<<"\n Delete Element is: "<<q_element<<endl;
	}
	else
	{
		q_element=arr[q_rear];
		q_rear=(q_rear-1+QUEUESIZE)%QUEUESIZE;
		cout<<"\n Deleted Element is: "<<q_element<<endl;
	}
}
bool queue::is_empty()
{
	if(q_rear==-1)
	return true;
	else 
	return false;
}
bool queue::is_full()
{
	if((q_rear+1)%QUEUESIZE == q_front)
		return true;
	else
		return false;
}
int queue::size()
{
	return q_rear;
}
void queue::displayElement()
{
	if(q_rear==-1)
	{
		cout<<"No element to display"<<endl;
		return;
	}
	cout<<"Element in the queue are: ";
	for(int i=q_front;i!=q_rear;i=(i+1)%QUEUESIZE)
	{
		cout<<arr[i]<<" ";
	 } 
	 cout<<arr[q_rear]<<" ";
	 cout<<endl;
}
int main()
{
	system ("cls");
	queue myqueue;
	int val;
	int choice;
	while(1)
	{
		cout<<"1. Insert at Front \n";
		cout<<"2. Insert at Rear \n";
		cout<<"3. Delete at Front \n";
		cout<<"4. Delete at Rear \n";
		cout<<"5. Display \n";
		cout<<"6. Exit \n";
		cout<<"Enter Choice ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Enter the value to Enter ";
				cin>>val;
				myqueue.insertElement_front(val);
				break;
			case 2:
				cout<<"Enter the Value to Enter ";
				cin>>val;
				myqueue.insertElement_rear(val);
				break;
			case 3:
				myqueue.deleteElement_front();
				break;
			case 4:
				myqueue.deleteElement_rear();
				break;		
			default:
				cout<<"Wrong Choice!!! ";
					
		}
		
		
	}
	getch();
	return 0;
}
