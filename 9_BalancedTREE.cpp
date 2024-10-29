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

class Pair{
public :
int height ;
bool balanced ;
};
Pair isbalanced(node*root){
    Pair p;
if(!root){
    p.height = 0;
    p.balanced= true;
    return p;
}
Pair left = isbalanced(root->left);
Pair right = isbalanced(root->right);
p.height = max(left.height , right.height )+1;

if(abs(left.height -right.height ) <=1 and left.balanced and right.balanced) p.balanced= true;
else p.balanced = false;
return p;
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

Pair p = isbalanced(root);
if(p.balanced) cout << "balanced hbai" ;
else cout << " nahi hai " ;

return 0;
}