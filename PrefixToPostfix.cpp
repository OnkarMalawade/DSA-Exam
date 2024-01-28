#include<iostream>
#include<stack>
using namespace std;
bool isOperator(char x){
	switch(x){
		case '+':
		case '-':
		case '*':
		case '/':
		return true;
	}
	return false;
}

string prefixConvertToPostfix(string prefix){
	stack <string> expression;
	int length = prefix.size();
	
	for(int i = length-1; i >= 0; i--){
		if(isOperator(prefix[i])){
			string op1 = expression.top();
			expression.pop();
			string op2 = expression.top();
			expression.pop();
			string temp = op1 + op2 + prefix[i];
			expression.push(temp);
		}
		else{
			expression.push(string(1,prefix[i]));
		}
	}
	return expression.top();
}

int main(){
	string prefix = "+/ab/cd";
	cout << "\nPrefix: " << prefix;
	cout << "\nPostfix: " << prefixConvertToPostfix(prefix);
	return 0;
}
