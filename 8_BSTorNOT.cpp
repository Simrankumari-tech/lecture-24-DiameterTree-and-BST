#include<bits/stdc++.h>
using namespace std;
class node{
public :
int data ;
node*left , *right ;
node(int d){
data = d;
right =left = NULL;
}
};

node*Insertatbst(node*root , int data){
    if(!root){
        root = new node(data);
        return root;
    }

    // recursive case
    if(data <= root ->data){
        root ->left = Insertatbst(root->left , data);
    }
    else{
        root->right = Insertatbst(root->right , data);
    }
    return root;
}
bool isBST(node*root , int mi= INT_MIN , int mx= INT_MAX){
if(!root) return true ;
if(root->data >= mi and root->data <= mx and isBST (root->left, mi, root->data) 
       and isBST(root->right , root->data , mx)) return true;

       else return false;
}
node*BuildTree (){
    node* root = NULL;
  int data;
   cin >> data ;
   
   while (data != -1 ) {
   
    root  = Insertatbst(root , data);

    cin >> data ;

   }
   return root;
}
void preorder(node*root){
    if(!root) return ;
    cout << root->data << "  "; 
    preorder(root ->left);
    preorder(root ->right ) ;

}
void inorder(node*root){
    if(!root ) return ;
    inorder(root->left);
    cout << root ->data << "  ";
    inorder(root->right);

}
void postorder(node*root){
    if(!root) return ;
    postorder(root->left );
    postorder(root->right);
    cout << root ->data << "  ";
}

// 8 3 10 1 6 14 4 7 13 -1
int main(){
    node*root = BuildTree();
    preorder(root);
    cout << endl;
    inorder(root );
cout << endl;
postorder(root);
cout << endl;

if(isBST(root)) cout << "bst hai " ;
else cout << "nhi hai" ;
return 0;
}