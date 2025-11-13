#include <iostream>
using namespace std;
#define MAX 100
void preorder(int tree[],int index,int n){
	if (index>=n||tree[index]==-1){
		return;
	}
	cout<<tree[index]<<" ";
	preorder(tree,2*index+1,n);
	preorder(tree,2*index+2,n);
	
}
void inorder(int tree[],int index,int n){
	if(index>=n||tree[index]==-1){
		return;
	}
	inorder(tree,2*index+1,n);
	cout<<tree[index]<<" ";
	inorder(tree,2*index+2,n);
}
void postorder(int tree[],int index,int n){
	if(index>=n||tree[index]==-1){
		return;
	}
	postorder(tree,2*index+1,n);
	postorder(tree,2*index+2,n);
	cout<<tree[index]<<" ";	
}
int main(){
	int tree[MAX];
	int n;
	cout<<"Enter number of elements:";
	cin>>n;
	cout<<"Enter Tree elements:"<<endl;
	for(int i=0;i<n;i++){
		cin>>tree[i];
	}
	
	cout<<"Preorder Traversal"<<endl;
	preorder(tree,0,n);
	cout<<endl;
	cout<<"Inorder Traversal"<<endl;
	inorder(tree,0,n);
	cout<<endl;
	cout<<"Postorder Traversal"<<endl;
	postorder(tree,0,n);
	cout<<endl;
}
