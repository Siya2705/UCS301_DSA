#include <iostream>
using namespace std;
struct Node{
	int data;
	Node* left;
	Node* right;
};
Node* create(int data){
	Node* newNode=new Node();
	newNode->data=data;
	newNode->left=nullptr;
	newNode->right=nullptr;
	return newNode;	
}
void preorder(Node* root){
	if(root==nullptr){
		return;
	}
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
void inorder(Node *root){
	if(root==nullptr){
		return;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
	
}
void postorder(Node *root){
	if(root==nullptr){
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}
Node* Tree(){
	int data;
	cout<<"Enter data:";
	cin>>data;
	if(data==-1){
		return nullptr;
		
	}
	Node *root=create(data);
	cout<<"Enter left child of "<< data<<endl;
	root->left=Tree();
	cout<<"Enter right child of "<< data<<endl;
	root->right=Tree();
	return root;
}
int main(){
	Node* root=Tree();
	cout<<"Preorder Traversal"<<endl;
	preorder(root);
	cout<<endl;
	cout<<"Inorder Traversal"<<endl;
	inorder(root);
	cout<<endl;
	cout<<"Postorder Traversal"<<endl;
	postorder(root);
	cout<<endl;
	return 0;
}
