#include<iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
};

void enqueue (Node ** head, int data)
{

  Node *new_node = new Node ();

  // assign data value
  new_node->data = data;
  // change the next node of this new_node 
  // to current head of Linked List
  new_node->next = *head;

  //changing the new head to this newly entered node
  *head = new_node;

}

void dequeue (Node ** head)
{
  Node *temp = *head;

  // if there are no nodes in Linked List can't delete
  if (*head == NULL)
    {
      cout << ("Linked List Empty, nothing to delete");
      return;
    }

  // move head to next node
  *head = (*head)->next;
  //cout<< ("Deleted: %d\n", temp->data);
  delete (temp);
}

void display (Node * node)
{

  //as linked list will end when Node is Null
  while (node != NULL)
    {
      cout << node->data << " ";
      node = node->next;
    }
  cout << endl;
}

int main ()
{
   Node *head = NULL;
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
		 	enqueue (&head, p);
		 	break;
         case 2: 
		 	dequeue (&head);
		 	cout << "\nAfter Element removed: ";
         	break;
         case 3: 
         	cout << "\nDisplay Elements: ";
		 	display (head);
         	break;
         case 4: cout<<"Exit"<<endl;
         	break;
         default: cout<<"Invalid choice"<<endl;
      }
   } while(ch!=4);
   return 0;
}
