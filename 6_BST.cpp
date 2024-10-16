#include<bits/stdc++.h>
using namespace std;
class node{
    public :
    int data ;
    node*left , *right ;
    node (int d){
        data = d;
        left = right = NULL ;
    }
};
node* InsertinBST(node*root , int data){
    if(!root) {
        root = new node(data);
        return root;
    }
    // recursive case
    if(data <= root->data){
        root ->left = InsertinBST(root->left , data);
    }
    else{
        root->right = InsertinBST(root->right , data);
    }
    return root;
}
node*buildtree(){
    node* root = NULL;
    int data ;
    cin >> data ;
    while(data != -1){
        root = InsertinBST(root , data);
        cin >> data ;
    }
    return root;
}
void preorder(node*root){
    if(!root) return;
    cout << root ->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(node*root){
    if(!root) return;
   
    inorder(root->left);
     cout << root ->data << " ,";
    inorder(root->right);
}
void postorder(node*root){
    if(!root) return;
   
    postorder(root->left);
    postorder(root->right);
     cout << root ->data << " ,";
}
// 8 3 10 1 6 14 4 7 13 -1
int main(){
   
    node*root = buildtree();
    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
}