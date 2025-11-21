#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data){
    Node* n = new Node();
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

Node* insertNode(Node* root, int data){
    if(root == NULL) return createNode(data);
    if(data < root->data) root->left = insertNode(root->left, data);
    else root->right = insertNode(root->right, data);
    return root;
}

// (a) Recursive Search
Node* searchRecursive(Node* root, int key){
    if(root == NULL || root->data == key) return root;
    if(key < root->data) return searchRecursive(root->left, key);
    return searchRecursive(root->right, key);
}

// (a) Non-Recursive Search
Node* searchNonRecursive(Node* root, int key){
    while(root != NULL){
        if(key == root->data) return root;
        else if(key < root->data) root = root->left;
        else root = root->right;
    }
    return NULL;
}

// (b) Maximum element
Node* findMax(Node* root){
    if(root == NULL) return NULL;
    while(root->right != NULL) root = root->right;
    return root;
}

// (c) Minimum element
Node* findMin(Node* root){
    if(root == NULL) return NULL;
    while(root->left != NULL) root = root->left;
    return root;
}

// (d) Inorder Successor
Node* inorderSuccessor(Node* root, int key){
    Node* curr = searchRecursive(root, key);
    if(curr == NULL) return NULL;

    if(curr->right != NULL)
        return findMin(curr->right);

    Node* succ = NULL;
    Node* ancestor = root;
    while(ancestor != curr){
        if(curr->data < ancestor->data){
            succ = ancestor;
            ancestor = ancestor->left;
        } else {
            ancestor = ancestor->right;
        }
    }
    return succ;
}

// (e) Inorder Predecessor
Node* inorderPredecessor(Node* root, int key){
    Node* curr = searchRecursive(root, key);
    if(curr == NULL) return NULL;

    if(curr->left != NULL)
        return findMax(curr->left);

    Node* pred = NULL;
    Node* ancestor = root;
    while(ancestor != curr){
        if(curr->data > ancestor->data){
            pred = ancestor;
            ancestor = ancestor->right;
        } else {
            ancestor = ancestor->left;
        }
    }
    return pred;
}

// ---------------- MAIN ----------------
int main(){
    Node* root = NULL;
    int n, x;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for(int i=0; i<n; i++){
        cin >> x;
        root = insertNode(root, x);
    }

    cout << "\nEnter value to search: ";
    cin >> x;

    Node* r = searchRecursive(root, x);
    Node* nr = searchNonRecursive(root, x);

    cout << "Recursive Search: ";
    if(r) cout << "Found\n"; else cout << "Not Found\n";

    cout << "Non-Recursive Search: ";
    if(nr) cout << "Found\n"; else cout << "Not Found\n";

    Node* mn = findMin(root);
    Node* mx = findMax(root);

    cout << "Minimum: " << (mn ? mn->data : -1) << endl;
    cout << "Maximum: " << (mx ? mx->data : -1) << endl;

    Node* succ = inorderSuccessor(root, x);
    Node* pred = inorderPredecessor(root, x);

    cout << "Inorder Successor: ";
    if(succ) cout << succ->data << endl; else cout << "None\n";

    cout << "Inorder Predecessor: ";
    if(pred) cout << pred->data << endl; else cout << "None\n";

    return 0;
}
