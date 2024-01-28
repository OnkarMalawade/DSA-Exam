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
	char exp[] = {'<','{','[','(',')',']','}','>','\0'};
	int size = 0;
	int op1, op2, res, i;
	int isValid = 1;
	char test;
	for(i = 0; exp[i] != '\0'; i++){
		test = exp[i];
		char comp;
		if(test == '{' || test == '<' || test == '[' || test == '(' ){
			myStack.push(test);
		}
		else{
			if(myStack.isEmpty() == true){
				isValid = 0;
				break;
			}
			else{
				comp = myStack.pop();
				if(test == '}' && comp != '{'){
					isValid = 0;
					break;
				}
				if(test == '>' && comp != '<'){
					isValid = 0;
					break;
				}
				if(test == ']' && comp != '['){
					isValid = 0;
					break;
				}
				if(test == ')' && comp != '('){
					isValid = 0;
					break;
				}
			}
		}
	}
	if(isValid == 1 && myStack.isEmpty() == true){
		cout << "\nValid Parenthesis!!!";
	}else{
		cout << "\nNot valid Parenthesis!!!";
	}
	return 0;
}
