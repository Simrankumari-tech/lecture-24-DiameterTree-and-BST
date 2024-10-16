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
     cout << root ->data << " ,";
    inorder(root->right);
}
void postorder(node*root){
    if(!root) return;
   
    postorder(root->left);
    postorder(root->right);
     cout << root ->data << " ,";
}


int pre[] ={ 8 ,10 ,1, 6, 4 , 7 , 3,14 ,13 };
int k= 0;
node*createtrees(int*in , int s, int e){
    if(s>e) return NULL;
    node*root = new node(pre[k]);
    k++;
    int i;
    for(int j= s; j<=e; j++){
        if(in[j] == root->data){
            i = j;
            break;
        }
    }
    root ->left = createtrees(in , s , i-1);
    root->right = createtrees(in , i+1 , e);
    return root ;
}

// 8 10 1 -1 -1 6 4 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
int main(){
   
int in[] ={1, 10 , 4 , 6 , 7 , 8 , 3 , 13 ,14};
int n = sizeof(in) / sizeof(int);
node*root = createtrees(in , 0 , n-1);
 
    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);


    return 0;
}