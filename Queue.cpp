#include<iostream>
#include<conio.h>
#include<stdlib.h>
#define QUEUESIZE 10

using namespace std;

class queue{
	private:
		int arr[QUEUESIZE];
		int q_front;
		int q_rear;
	public:
		queue();
		void insertElement(int x);
		int deleteElement();		
		bool is_empty();
		bool is_full();
		int size();
		void displayElement();
};

queue::queue()
{
	q_front=0;
	q_rear=-1;
}

void queue::insertElement(int val){
	q_rear=q_rear+1;
	arr[q_rear]=val;
	
}

int queue::deleteElement() 
{
	int q_element;
	q_element=arr[q_front];
	q_front=q_front+1;
	return q_element;
}

bool queue::is_empty()
{
	if(q_rear==-1||q_front>q_rear)
		return true;
	else
		return false;
}
//Algoritm isFull in circular queue
bool queue::is_full()
{
	if(q_rear==QUEUESIZE-1)

		return true;
	
	else
		return false;
}

//size of the queue
int queue::size()
{
	return q_rear;
}

//Algorithm display
void queue::displayElement()
{
	cout<<"Element in the queue are :";
	for(int i=q_front;i<=q_rear;i++)
	cout<<arr[i]<<" ";
	cout<<endl;
}

int main()
{
	queue myqueue;
	int val;
	int choice;
	while(1)
	{
		cout<<"1.Insert\n";
		cout<<"2.Delete\n";
		cout<<"3.Display\n";
		cout<<"4.Quit\n";
		cout<<"Enter your choice :";
		cin>>choice;
		switch(choice)
		{
			case 1:
				if(myqueue.is_full()==false)
				{
					cout<<"Enter Value to be inserted";
					cin>>val;
					myqueue.insertElement(val);
				}
				else
				{
					cout<<"Queue is full ,can not insert"<<endl;
				}
				break;
			case 2:
				if(myqueue.is_empty()==false)
				{
					val=myqueue.deleteElement();
					cout<<"\n Element "<<val<<"is deleted succesfully";
				}
				else
				{
					cout<<"\nQueue is empty cannot deleted"<<endl;
					
				}
				break;
			case 3:
				if(myqueue.is_empty()==false)
				{
					myqueue.displayElement();
					
				}
				else
				{
					cout<<"\nQueue is empty cannot display"<<endl;
				}
				break;
			case 4:
				exit(1);
				default:
				cout<<"wrong choice\n";
				
		}
	}
	getch();
	return 0;
}











