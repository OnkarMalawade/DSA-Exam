#include<iostream>
#include<stdlib.h>
#include<conio.h>

#define STACKSIZE 10

using namespace std;

class stack {
private:
    int arr[STACKSIZE];
    int stack_top;

public:
    stack();
    void push(int x);
    int pop();
    bool is_Empty();
    bool is_Full();
    int size();
    void display();
};

stack::stack() {
    stack_top = -1; 
}

void stack::push(int val) {
    stack_top = stack_top + 1;
    arr[stack_top] = val;
}

int stack::pop() {
    int val;
    val = arr[stack_top];
    --stack_top;
    return val;
}

bool stack::is_Empty() {
    if (stack_top == -1)
        return true;
    else
        return false;
}

bool stack::is_Full() {
    if (stack_top == STACKSIZE - 1) 
        return true;
    else
        return false;
}

int stack::size() {
    return stack_top + 1;
}

void stack::display() {
    if (stack_top == -1)
        return;
    cout << "\nElements in the stack are";
    for (int i = 0; i <= stack_top; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    system("cls");
    stack mystack;
    int val;
    int choice;
    while (1) { 
        cout << "1. Push\n";
        cout << "2. Pop\n"; 
        cout << "3. Display\n";
        cout << "4. Quit\n";
        cin >> choice;
        switch (choice) {
        case 1:
            if (mystack.is_Full() == false) {
                cout << "Enter Value to Push" << endl;
                cin >> val;
                mystack.push(val);
            }
            else {
                cout << "Stack is Full You Can't Insert " << val << endl;
            }
            break;
        case 2:
            if (mystack.is_Empty() == false) {
                val = mystack.pop();
                cout << "Popped value: " << val << endl;
            }
            else {
                cout << "Stack is Empty You Can't Delete" << endl;
            }
            break;
        case 3:
            mystack.display();
            break;
        case 4:
            exit(1);
        default:
            cout << "Wrong Choice ";
            break;
        }
    }
    getch();
    return 0;
}
