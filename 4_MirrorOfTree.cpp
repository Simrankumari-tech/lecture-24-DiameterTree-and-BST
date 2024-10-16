#include <bits/stdc++.h>
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



void levelOrder(node*root){
queue < node*> q;
q.push(root);
q.push(NULL);
while(!q.empty()){
    node*x = q.front();
    q.pop ();
        if(x!= NULL){
            cout << x->data << " " ;
            if(x->left ) q.push(x->left);
            if(x->right) q.push(x->right) ;
        }
        else{
            cout << endl;
            if(!q.empty()) q.push(NULL);
        }
}
}
void mirror(node*root){
    if(!root ) return ;
    swap(root->left , root->right);
    mirror(root->left);
    mirror(root->right) ;
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


levelOrder(root);
cout << endl;
mirror(root);
levelOrder(root);
    return 0;
}