#include <iostream>
using namespace std;

#define MAX 100

// ------------ ARRAY BASED TREE ------------
void preorderArr(int tree[], int index, int n){
    if(index >= n || tree[index] == -1) return;
    cout << tree[index] << " ";
    preorderArr(tree, 2*index + 1, n);
    preorderArr(tree, 2*index + 2, n);
}

void inorderArr(int tree[], int index, int n){
    if(index >= n || tree[index] == -1) return;
    inorderArr(tree, 2*index + 1, n);
    cout << tree[index] << " ";
    inorderArr(tree, 2*index + 2, n);
}

void postorderArr(int tree[], int index, int n){
    if(index >= n || tree[index] == -1) return;
    postorderArr(tree, 2*index + 1, n);
    postorderArr(tree, 2*index + 2, n);
    cout << tree[index] << " ";
}

// ------------ POINTER BASED TREE ------------
struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* create(int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

void preorder(Node* root){
    if(root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root){
    if(root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

Node* buildTree(){
    int data;
    cin >> data;
    if(data == -1) return nullptr;
    Node* root = create(data);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}


int main(){

    cout << "ARRAY-BASED TREE\n";
    int tree[MAX], n;

    cout << "Enter number of elements: ";
    cin >> n;

    if(n > 0){
        cout << "Enter root node: ";
        cin >> tree[0];

        for(int i = 0; i < n; i++){
            if(tree[i] == -1) continue;

            cout << "Enter left child of " << tree[i] << ": ";
            cin >> tree[2*i + 1];

            cout << "Enter right child of " << tree[i] << ": ";
            cin >> tree[2*i + 2];
        }

        cout << "\nPreorder: ";
        preorderArr(tree, 0, n);
        cout << "\nInorder: ";
        inorderArr(tree, 0, n);
        cout << "\nPostorder: ";
        postorderArr(tree, 0, n);
        cout << "\n\n";
    }

    cout << "POINTER-BASED TREE\n";
    cout << "Enter tree data (-1 for NULL):\n";
    Node* root = buildTree();

    cout << "\nPreorder: ";
    preorder(root);
    cout << "\nInorder: ";
    inorder(root);
    cout << "\nPostorder: ";
    postorder(root);
    cout << endl;

    return 0;
}
