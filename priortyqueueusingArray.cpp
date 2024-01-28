#include<iostream>
#include<conio.h>
#include<stdlib.h>
#define QUEUESIZE 5
using namespace std;
class node
{
	public:
		int value;
		int priority;
	node()
	{
		value=0;
		priority=0;
	}
};
class queue
{
	private:
		node arr[QUEUESIZE];
		int q_front;
		int q_rear;
	public:
		queue();
		void insertElement(int,int);
		int deleteElement();
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
void queue::insertElement(int val,int pr)
{
	if(is_empty()==true)
	{
		q_rear=0;
		q_front=0;
		arr[q_rear].value=val;
		arr[q_rear].priority=pr;
	}
	else
	{
		int walker=q_rear;
		while((arr[walker].priority)<pr)
		{
			arr[(walker+1)%QUEUESIZE].value=arr[walker].value;
			arr[(walker+1)%QUEUESIZE].priority=arr[walker].priority;
			walker=(walker-1+QUEUESIZE)%QUEUESIZE;
			if((walker+1)%QUEUESIZE==q_front){
			    break;
			}
		}
		walker=(walker+1)%QUEUESIZE;
		arr[walker].value=val;
		arr[walker].priority=pr;
		q_rear=(q_rear+1)%QUEUESIZE;
	}
}
int queue::deleteElement()
{
	int q_element;
	q_element=arr[q_front].value;
        if(q_front==q_rear)
        {
        	q_rear=-1;
        	q_front=-1;
	}
	else
	{
		q_front=(q_front+1)%QUEUESIZE;
	}
	return q_element;

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
	if((q_rear+1)%QUEUESIZE==q_front)
	   return true;
	else
	   return false;
}


int queue::size()
{
	return QUEUESIZE-(q_rear-q_front+1);
}

void queue::displayElement()
{
	if(q_rear==-1)
	{
		cout<<"No element to display"<<endl;
		return;
	}
	cout<<"Element in the queue are:\n";
	for(int i=q_front;i!=q_rear;i=(i+1)%QUEUESIZE)
	{
		cout<<"\nValue: "<<arr[i].value<<"  Priority:"<<arr[i].priority<<" ;" << endl;
	}
	cout<<"\nValue: "<<arr[q_rear].value<<"  Priority:"<<arr[q_rear].priority<<" ;" <<endl;
}
int main(){
		queue myqueue;
		int val,pr;
	    int choice;
	    while(1)
	    {
	    	cout<<"1.Insert\n";
	    	cout<<"2.Delete\n";
	    	cout<<"3.Display\n";
	    	cout<<"4.Quit\n";
	    	cout<<"Enter your choice:";
		    cin>>choice;
			switch(choice)
			{
			case 1:
				if(myqueue.is_full()==false){
					cout<<"\nEnter value to be pushed:";
					cin>>val;
					cout<<"Enter priority of the value to be punched:";
					cin>>pr;
					myqueue.insertElement(val,pr);
				}
	       		else
	               cout<<"Queue is full,can't insert"<<endl;
	            break;
	        case 2:
	        	if(myqueue.is_empty()==false)
	        	{
	        		val=myqueue.deleteElement();
	        		cout<<"\n Delete Elemnet is:"<<val<<endl;
				}
				else
			   		cout<<"\n Queue is empty,can't delete"<<endl;
			    break;
            case 3:
               	myqueue.displayElement();
           	    break;
            case 4:
             	exit(1);
            default:
               	cout<<"Wrong choice\n";
	    }
	}
	return 0;
}
