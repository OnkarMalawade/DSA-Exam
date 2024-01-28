#include<iostream>
using namespace std;
#define QSize 5
class queue{
	int arr[QSize];
	int qfront;
	int qrear;
	int size = 0;
	
	public:
		queue(){
			qfront = -1;
			qrear = -1;
		}
		void insertRear(int val){
			if(isFull()== true){
				cout << "Queue is Full";
			}
			else if(isEmpty()==true){
				qrear = 0;
				qfront = 0;
				arr[qrear] = val;
				size++;
			}
			else{
				qrear = (qrear + 1)%QSize;
				arr[qrear] = val;
				size++;
			}
		}
		void insertFront(int val){
			if(isFull() == true){
				cout << "Queue is Full";
			}
			else if(isEmpty()==true){
				qrear = 0;
				qfront = 0;
				arr[qrear] = val;
				size++;
			}
			else{
				qfront = (qfront-1+QSize) % QSize;
				arr[qfront] = val;
				size++;
			}
		}
		void deleteElementfront()
		{
			int q_element;
			q_element=arr[qfront];
			if(isEmpty()==true)
			{
				cout<<"Queue is empty, can not delete" <<endl;
			}
			else if(qfront==qrear)
			{
				q_element=arr[qfront];
				qrear=-1;
				qfront=-1;
				cout<<"\n Delete Element is: "<<q_element<<endl;
				size--;
			}
			else
			{
				q_element=arr[qfront];
				qfront=(qfront+1)%QSize;
				cout<<"\n Deleted Element is: "<<q_element<<endl;
				size--;
			}
		}
		void deleteElementrear()
		{
			int q_element;
			q_element=arr[qfront];
			
			if(isEmpty()==true)
			{
				cout<<"\n Queue is empty, can not delete"<<endl;
			}
			else if(qfront==qrear)
			{
				q_element=arr[qrear];
				qrear=-1;
				qfront=-1;
				cout<<"\n Delete Element is: "<<q_element<<endl;
				size--;
			}
			else
			{
				q_element=arr[qrear];
				qrear=(qrear-1+QSize)%QSize;
				cout<<"\n Deleted Element is: "<<q_element<<endl;
				size--;
			}
		}
		bool isEmpty()
		{
			if(qrear==-1)
				return true;
			else 
				return false;
		}
		bool isFull()
		{
			if((qrear+1)%QSize == qfront)
				return true;
			else
				return false;
		}
		int size1()
		{
			return size;
		}
		void displayElement()
		{
			if(qrear==-1)
			{
				cout<<"No element to display"<<endl;
				return;
			}
			cout<<"Element in the queue are: ";
			for(int i=qfront;i!=qrear;i=(i+1)%QSize)
			{
				cout<<arr[i]<<" ";
			} 
			cout<<arr[qrear]<<" ";
			cout<<endl;
		}
};

int main()
{
	queue myqueue;
	int val;
	int choice;
	while(1)
	{
		cout<<"1. Insert at Front: \n";
		cout<<"2. Insert at Rear: \n";
		cout<<"3. Delete at Front: \n";
		cout<<"4. Delete at Rear: \n";
		cout<<"5. Display: \n";
		cout<<"6. Size: \n";
		cout<<"7. Exit \n";
		cout<<"Enter Choice ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Enter the value:";
				cin>>val;
				myqueue.insertFront(val);
				break;
			case 2:
				cout<<"Enter the Value: ";
				cin>>val;
				myqueue.insertRear(val);
				break;
			case 3:
				myqueue.deleteElementfront();
				break;
			case 4:
				myqueue.deleteElementrear();
				break;		
			case 5:
				myqueue.displayElement();
				break;
			case 6:
				cout << "Size of the Queue:" << myqueue.size1()<<endl;
				break;
			case 7:
				exit(0);
			default:
				cout<<"Wrong Choice!!! ";			
		}
	}
	return 0;
}

