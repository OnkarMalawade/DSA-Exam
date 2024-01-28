#include<iostream>
#include<conio.h>
using namespace std;

class node{
	public:
		int data;
		node* left;
		node* right;
		
		node(int data){
			this -> data = data;
			this -> left = NULL;
			this -> right = NULL;
		}
};

node* buildNode(node* root){
	cout << "\nEnter data: " << endl;
	int data;
	cin >> data;
	root = new node(data);
	
	if(data == -1){
		return NULL;
	}
	
	cout << "\n Enter Left side data: " << endl;
	root -> left = buildNode(root->left);
	cout << "\n Enter right side data: " << endl;
	root -> right = buildNode(root->right);
	return root;
}
void inorder(node* root){
	if(root == NULL){
		return;
	}
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

void preorder(node* root){
	if(root == NULL){
		return;
	}
	cout << root->data <<" ";
	preorder(root->left);
	preorder(root->right);
}

void postorder(node* root){
	if(root == NULL){
		return;
	}	
	postorder(root->left);
	postorder(root->right);
	cout << root->data <<" ";
}

int main(){
	node* root = NULL;
	root = buildNode(root);
	return 0;
}
