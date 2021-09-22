#include <iostream>
using namespace std;

typedef struct node{
    int val;
    node* left,*right;
}TreeNode;

void preorder(TreeNode* node){
    if(node != nullptr){
        return;
    }
    
}