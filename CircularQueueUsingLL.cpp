//Circular queue  C++ program 
#include<iostream>

using namespace std;

class Node
{
public:
  int data;
  Node *next;
};

class CircularQueue
{
private:
  Node * front;
  Node *rear;

public:
    CircularQueue ()
  {
    front = rear = NULL;
  }

  void enqueue (int data)
  {
    Node *newNode = new Node ();
    newNode->data = data;
    newNode->next = NULL;

    if (front == NULL)
      {
	front = rear = newNode;
	rear->next = front;
      }
    else
      {
	rear->next = newNode;
	rear = newNode;
	rear->next = front;
      }

    cout << data << " has been enqueued." << endl;
  }

  void dequeue ()
  {
    if (front == NULL)
      {
	cout << "Queue is empty." << endl;
      }
    else if (front == rear)
      {
	Node *temp = front;
	front = rear = NULL;
	delete temp;
      }
    else
      {
	Node *temp = front;
	front = front->next;
	rear->next = front;
	delete temp;
      }
  }

  void display ()
  {
    if (front == NULL)
      {
	cout << "Queue is empty." << endl;
      }
    else
      {
	Node *temp = front;
	cout << "Circular Queue: ";
	do
	  {
	    cout << temp->data << " ";
	    temp = temp->next;
	  }
	while (temp != front);
	cout << endl;
      }
  }
};

int main ()
{
  		CircularQueue q;
		int ch,p;
	   cout<<"1) Insert element to queue"<<endl;
	   cout<<"2) Delete element from queue"<<endl;
	   cout<<"3) Display all the elements of queue"<<endl;
	   cout<<"4) Exit"<<endl;
	   do {
	      cout<<"Enter your choice : "<<endl;
	      cin>>ch;
	      switch (ch) {
	         case 1:  
	         	cout << "\nEnter Element: ";
	         	cin >> p;
			 	q.enqueue(p);
			 	break;
	         case 2: 
			 	q.dequeue();
			 	cout << "\nAfter Element removed: ";
	         	break;
	         case 3: 
	         	cout << "\nDisplay Elements: ";
			 	q.display();
	         	break;
	         case 4: 
			 	cout<<"Exit"<<endl;
	         	break;
	         default: 
			 	cout<<"Invalid choice"<<endl;
	      }
	   } while(ch!=4);
	  return 0;
}
