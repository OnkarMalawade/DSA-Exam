#include<iostream>
#include<conio.h>
#include<stdlib.h>

#define STACKSIZE 5

using namespace std;

class stack{
	int arr[STACKSIZE];
	int stack_top;
	
	public:
		stack(){
			stack_top = -1;
		}
		void push(int val){
			stack_top = stack_top+1;
			arr[stack_top] = val;
		}
		int pop(){
			int val;
			val = arr[stack_top];
			stack_top--;
			return val;
		}
		bool isEmpty(){
			if(stack_top == -1){
				return true;
			}else{
				return false;
			}
		}
		bool isFull(){
			if(stack_top == STACKSIZE-1){
				return true;
			}else{
				return false;
			}
		}
		int size(){
			return stack_top+1;
		}
		void display(){
			if(stack_top == -1){
				cout << "Not any Element present in the Stack";
			}
			else{
				cout << "Elements in the Stack is: ";
				for(int i = 0 ; i <= stack_top; i++){
					cout << arr[i] << " ";
				}
				cout << endl;
			}
		}
};

int main(){
	stack myStack;
	int val;
	int choice;
	while(1){
		cout <<"\n Press:\n   1.Push\n   2.Pop\n   3.Display\n   4.Exit";
		cout << "\nEnter the Choice: ";
		cin >> choice;
		switch(choice){
			case 1:
				if(myStack.isFull() == false){
					cout << "\nEnter Value:";
					cin >> val;
					myStack.push(val);
				}else{
					cout << "\nStack is Full.";
				}
				break;
			case 2:
				if(myStack.isEmpty() == false){
					val = myStack.pop();
					cout << "\nValue is " << val;
				}
				else{
					cout << "\nStack is Empty.";
				}
				break;
			case 3:
				myStack.display();
				break;
			case 4:
				exit(1);
		}	
	}
	return 0;
}
