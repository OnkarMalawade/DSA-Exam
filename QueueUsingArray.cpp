#include<iostream>
#include<stdlib.h>

#define QUEUESIZE 10

using namespace std;

class queue{
	int arr[QUEUESIZE];
	int qfront;
	int qrear;
	
	public:
		queue(){
			qfront =  0;
			qrear = -1;
		}
		void insertElement(int val){
			qrear = qrear + 1;
			arr[qrear] = val;
		}
		int deleteElement(){
			int qElement;
			qElement = arr[qfront];
			qfront += 1;
			return qElement;
		}
		bool isEmpty(){
			if(qrear == -1 || qfront > qrear){
				return true;
			}
			else{
				return false;
			}
		}
		bool isfull(){
			if(qrear == QUEUESIZE - 1){
				return true;
			}
			else{
				return false;
			}
		}
		int size(){
			return qrear;
		}
		void displayElement(){
			cout << "\nElements of Queue:";
			for(int i = qfront; i != qrear; i++){
				cout << arr[i] << " ";
			}
			cout << endl;
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
