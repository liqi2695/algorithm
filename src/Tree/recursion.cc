#include <iostream>
using namespace std;

typedef struct Node{
    int val;
    Node* left, *right;
}TreeNode;


void inorder(TreeNode* root){
    if(root  == NULL)
        return;
    //前序
    inorder(root->left);
    //中序
    inorder(root->right);
    //后序
}



int main()
{

}