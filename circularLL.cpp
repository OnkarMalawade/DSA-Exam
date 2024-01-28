#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    //Constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
    ~Node(){
        int value = this -> data;
        if(this -> next != NULL){
            delete next;
            next = NULL;
        }
        cout << "Memory is free for node with Data "<< value << endl;
    }
};
void insertAtNode(Node* &tail,int element,int d){
    //Assuming Elenet is present in the LL
    if(tail == NULL)// Empty LL   
    {
        Node* newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode;
    }
    else{
        //Non Empty LL
        //Assuming element is present in the LL
        Node* curr = tail;

        while(curr -> data != element){
            curr =curr -> next;
        }
        //element found -> curr is representing element wala node
        Node * temp = new Node(d);
        temp -> next = curr -> next;
        curr -> next = temp;
    }
}
void deleteCLL(Node* &tail,int value){
    //empty LL
    if(tail == NULL){
        cout << "List is Empty,Please Check Again"<<endl;
        return;
    }
    else{
        //Non empty LL

        //assuming that value present in the LL
        Node* prev = tail;
        Node* curr = prev -> next;
        
        while(curr -> data != value){
            prev = curr;
            curr =curr-> next;

        }
        prev -> next= curr-> next;
        //1 node Asel Tr
        if(curr == prev){
            tail = NULL;
        }
        if(tail == curr){
            tail = prev;
        }
        curr -> next = NULL;
        delete curr;
    }

}
void printLL(Node* tail){
	Node* temp =tail;
    cout << " Data: [  ";
    if(tail == NULL){
        cout << "Nothing in the Node List";
    }
    do{
        cout << tail -> data <<"  ";
        tail = tail -> next;
    }while(tail != temp);
    cout << "] " << endl;
}
int main(){
    Node* tail =NULL;
    
    insertAtNode(tail,5,3);
    printLL(tail);

    insertAtNode(tail,3,8);
    printLL(tail);

    insertAtNode(tail,8,9);
    printLL(tail);

    insertAtNode(tail,9,5);
    printLL(tail);

    insertAtNode(tail,5,1);
    printLL(tail);
    
    insertAtNode(tail,5,90);
    printLL(tail);

	int p;
	cout << "\nEnter Element you want remove from the Linked List: ";
	cin>>p;
    deleteCLL(tail,p);
    printLL(tail);
    
    int pos,ele;
	cout << "\nEnter Element you want insert position from the Linked List: ";
	cin>>pos;
	cout << "\nEnter Element you want insert value from the Linked List: ";
	cin>>ele;
    insertAtNode(tail,ele,pos);
    printLL(tail);

	cout << "\nEnter Element you want remove from the Linked List: ";
	cin>>p;
    deleteCLL(tail,p);
    printLL(tail);

    return 0;
}

