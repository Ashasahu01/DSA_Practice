#include<iostream>
#include<vector>
using namespace std;

class Node {
    public:
        int data;
        Node* left;  //left pointer
        Node* right; //right pointer

    Node(int val){
        data = val;  
        left = right = NULL;  //for every new node pointer points to null
    }
};

static int idx = -1;
Node* buildTree(vector<int> preorder) {
     idx++;

    if(preorder[idx] == -1){  //check whether root having children or not
        return NULL;
    }

    Node* root = new Node(preorder[idx]);

    root->left = buildTree(preorder);  //for left child
    root->right = buildTree(preorder);  //for right child

    return root;
}

//pre order
void preOrder (Node* root) {
    if(root == NULL){
        return;
    }

    cout << root-> data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

//In Order traversal
void inOrder(Node* root){
    if(root == NULL){ // check the subtree till it founds null node
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

//Post Order Traversal
void postOrder(Node* root){
    if(root == NULL){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main() {
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node* root = buildTree(preorder);

    //----- to print root n their child

    // cout << root->data << endl;
    // cout << root->left->data << endl;
    // cout << root->right->data << endl;

    //----Call preOrder func :-

    // preOrder(root);  // => 1 2 3 4 5
    // cout << endl;

    //----call inOrder func :-

    // inOrder(root);  // => 2 1 4 3 5
    // cout << endl;

    //----call postOrder func :-

    postOrder(root);  // => 2 4 5 3 1
    cout << endl;
    return 0;
}