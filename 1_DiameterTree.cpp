#include <iostream>
using namespace std;
class node{
    public :
    int data;
node*left , *right;
node(int d){
    data = d;
    left = right = NULL;
}
};
node* buildTree(){
    int data ;
    cin >> data ;
if(data == -1) return NULL;
node*root = new node(data);
root ->left = buildTree();
root->right = buildTree();
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
     cout << root ->data << " ";
    inorder(root->right);
}
void postorder(node*root){
    if(!root) return;
   
    postorder(root->left);
    postorder(root->right);
     cout << root ->data << " ";
}
int height(node*root){
    if(!root ) return 0 ;
    int left = height(root->left);
    int right = height(root->right);
    return max(left , right)+1;
}
int countnode(node*root){
    if(!root) return 0;
    return countnode(root->left) +countnode(root->right) +1;
}
int diameter(node*root){
    if(!root) return 0;
    int op1 = height(root->left) + height(root->right);
    int op2 = diameter(root->left);
    int op3 = diameter(root->right);
    return max(op1 , max(op2, op3));
}

// 8 10 1 -1 -1 6 4 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
int main(){
    node*root = buildTree();
    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
    cout << endl;

cout << "height : " << height(root) << endl;
cout << "count node : " << countnode(root) << endl;
cout << "diameter : " << diameter(root) << endl;
    return 0;
}