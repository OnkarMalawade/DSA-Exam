#include<iostream>
#include<stdlib.h>

#define QUEUESIZE 6

using namespace std;

class queue{
	int arr[QUEUESIZE];
	int qfront;
	int qrear;
	
	public:
		queue(){
			qfront = -1;
			qrear = -1;
		}
		void insertElement(int val){
			if(isEmpty() == true){
				qrear = 0;
				qfront = 0;
				arr[qfront] = val;
			}
			else{
				qrear = (qrear + 1) % QUEUESIZE;
				arr[qrear] = val;
			}
		}
		int deleteElement(){
			int qElement;
			if(qfront == qrear){
				qElement = arr[qfront];
				qrear = -1;
				qfront = -1;
			}
			else{
				qElement = arr[qfront];
				qfront = (qfront + 1) % QUEUESIZE;
			}
			return qElement;
		}
		bool isfull(){
			if((qrear+1) % QUEUESIZE == qfront){
				return true;
			}else{
				return false;
			}
		}
		bool isEmpty(){
			if(qrear == -1){
				return true;
			}else{
				return false;
			}
		}
		int size(){
			if(qrear > qfront){
				return qrear-qfront+1;
			}else{
				return QUEUESIZE-qrear-qfront+1;
			}
		}
		void displayElement(){
			if(qrear == -1){
				cout << "\nQueue is Empty.";
				return;
			}
			cout << "\nElements are in the Queue are ";
			for(int i = qfront; i != qrear; i=(i+1)%QUEUESIZE){
				cout << arr[i] << " ";
			}
			cout << arr[qrear] << " " << endl;
		}		
};

int main(){
	queue myque;
	int val;
	int choice;
	
	while(1){
		cout << "\nPress: \n 1.Insert \n 2.Delete \n 3.Display \n 4.Exit";
		cout << "\nEnter the choice: ";
		cin >> choice;
		switch(choice){
			case 1:
				if(myque.isfull() == false){
					cout << "\nEnter the Value: ";
					cin >> val;
					myque.insertElement(val);
				}
				else{
					cout <<"\nQueue is Full...";
				}
				break;
			case 2:
				if(myque.isEmpty() == false){
					val = myque.deleteElement();
					cout << "\nElement " << val << " deleted from the Queue.";
				}else{
					cout << "\nQueue is Empty.";
				}
				break;
			case 3:
				if(myque.isEmpty() == false){
					myque.displayElement();
				}
				else{
					cout << "\nQueue is Empty.";
				}
				break;
			case 4:
				exit(1);
			default:
				cout << "\nWrong Choice.";
		}
	}
	return 0;
}
