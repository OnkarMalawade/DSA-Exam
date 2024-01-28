#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
class myBT;
class stack{
	private:
		myBT * arr[25];
		int stack_top;
		int stacksize;
	public:
		stack(){
			stack_top=-1;
			stacksize=25;
		}
	    void push(myBT* val){
	    	stack_top=stack_top+1;
	    	arr[stack_top]=val;
		}
		myBT *pop(){
			myBT* val;
			val=arr[stack_top];
			--stack_top;
			return val;
		}
		bool isempty(){
			if(stack_top==-1){
				return true;
			}
			else{
				return false;
			}
		}
		bool isfull(){
			if(stack_top==stacksize-1){
				return true;
			}
			else{
				return false;
			}
		}
		int size(){
			return stack_top+1;
		}
		void display(){
			if(stack_top==-1){
				cout<<"No elements"<<endl;
				return;
			}
			cout<<"\nelements in stack are: ";
			for (int i=0;i<=stack_top;i++){
					cout<<arr[i]<<" ";
			}
			cout<<endl;
		}
};
class myBT{
	public:
		int data;
		myBT*left;
		myBT*right;
		static int node_count;
		myBT(int dataValue);
		myBT();
		void insert(int dataValue);
		void removeNode(int dataValue);
		void inorder(myBT* r);
		void preorder(myBT* r);
		void postorder(myBT* r);
		int smallest(myBT* r);
		int largest(myBT* r);
		void search(int targetValue);
};
myBT* root;
myBT::myBT(){
	data=0;
	left=NULL;
	right=NULL;
}
myBT::myBT(int val){
	data=val;
	left=NULL;
	right=NULL;
	node_count++;
}

void myBT::insert(int dataValue){
	myBT* temp=new myBT(dataValue);
	myBT*trav=root;
	myBT* hold=NULL;
	if(trav!=NULL){
		while(trav!=NULL){
			hold=trav;
			if(dataValue>=trav->data){
				trav=trav->right;
			}
			else{
				trav=trav->left;
			}
		}
		if(hold->data>dataValue){
			hold->left=temp;
		}
		else{
			hold->right=temp;
		}
	}
	else{
		root=temp;
	}
}
void myBT::inorder(myBT* r){
	myBT* trav=r;
	stack mystack;
	while(trav!=NULL){
		mystack.push(trav);
		trav=trav->left;
	}
	trav=mystack.pop();
	while(trav!=NULL){
		cout<<trav->data<<" ";
		if(trav->right!=NULL){
			trav=trav=trav->right;
			while(trav!=NULL){
				mystack.push(trav);
				trav=trav->left;
			}
		}
		if(mystack.isempty()==false){
			trav=mystack.pop();
		}else{
			trav=NULL;
		}
	}	
}
void myBT::preorder(myBT* r){
	myBT* trav=r;
	stack mystack;
	while(trav!=NULL){
		cout<<trav->data<<" ";
		if(trav->right!=NULL){
			mystack.push(trav->right);
		}
		if(trav->left!=NULL){
			trav=trav->left;
		}
		else{
			if(mystack.isempty()==false){
				trav=mystack.pop();
			}else{
				trav=NULL;
			}
		}
	}
}
void myBT::postorder(myBT* r){
	myBT* previous=r;
	myBT* s=NULL;
	stack mystack;
	mystack.push(r);
	while(mystack.isempty()==false){
		s=mystack.pop();
		if(s->right==NULL && s->left==NULL){
			previous=s;
			cout<<s->data<<" ";
		}
		else{
			if(s->right==previous || s->left==previous){
				previous=s;
				cout<<s->data<<" ";
			}
			else{
				mystack.push(s);	
				if(s->right!=NULL){
					mystack.push(s->right);
				}
				if(s->left!=NULL){
					mystack.push(s->left);
				}
			}
		}
	}
}
int myBT::smallest(myBT* r){
	myBT * trav=r;
	while(trav->left!=NULL){
		trav=trav->left;
	}
	return trav->data;
}
int myBT::largest(myBT* r){
	myBT * trav=r;
	while(trav->right!=NULL){
		trav=trav->right;
	}
	return trav->data;
}
void myBT::search(int targetValue){
	myBT*trav=root;
	bool flag=0;
	while(trav!=NULL){
		if(targetValue<trav->data){
			trav=trav->left;
		}
		else if(targetValue>trav->data){
			trav=trav->right;
		}
		else{
			flag=1;
			break;
		}
	}
	if(flag==1){
		cout<<"\nelement found";
	}	
	else{
		cout<<"\nelement is not found";		
	}
}
void myBT::removeNode(int dataValue){
	myBT* trav=root;
	myBT* hold=root;
	myBT* temp=NULL;
	bool findflag=false;
	bool isleft=false;
	while(trav!=NULL){
		if(dataValue<trav->data){
			hold=trav;
			trav=trav->left;
			isleft=true;
		}
		else if(dataValue>trav->data){
			hold=trav;
			trav=trav->right;
			isleft=false;
		}
		else{
			findflag=true;
			break;
		}
	}
	if(findflag==true){
		if(trav->left==NULL && trav->right==NULL){
			free(trav);
			cout<<"\nelement deleted";
			if(isleft==true){
				hold->left=NULL;
			}
			else{
				hold->right=NULL;
			}
		}
		else if(trav->left==NULL && trav->right!=NULL){
			if(isleft==true){
				hold->left=trav->right;
			}
			else{
				hold->right=trav->right;
				free(trav);
				cout<<"\nelement deleted";
			}
		}
		else if(trav->left!=NULL && trav->right==NULL){
			if(isleft==true){
				hold->left=trav->left;
			}
			else{
				hold->right=trav->left;
				free(trav);
				cout<<"\nelement deleted";
			}
		}
		else{
			int tempLarge=trav->left->largest(trav->left);
			root->removeNode(tempLarge);
			trav->data=tempLarge;
			cout<<"\nelement deleted";
		}	
	}
	else
		cout<<"\nelement is not found";
}
int myBT::node_count=0;
int main(){
	root->insert(30);
	root->insert(15);
	root->insert(45);
	root->insert(10);
	root->insert(20);

	cout<<"\ninorder: ";
	root->inorder(root);
	cout<<"\npreorder: ";
	root->preorder(root);
	cout<<"\npostorder: ";
	root->postorder(root);
	cout<<"\nsmallest element is: ";
	root->smallest(root);
	cout<<"\nlargest element is: ";
	root->largest(root);
	cout<<"\nsearch 45: ";
	root->search(45);
	cout<<"\nremoving element 15: ";
	root->removeNode(15);
	cout<<"\ninorder: ";
	root->inorder(root);	
	getch();
	return 0;
}










