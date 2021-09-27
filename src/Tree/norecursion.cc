#include <iostream>
#include <stack>
using namespace std;

typedef struct Node{
    int val;
    Node* left, *right;
}TreeNode;


void myprint(TreeNode* root){
    cout << root->val << endl;
}

void preorder(TreeNode* root){
    if(root == NULL) return;
    stack<TreeNode*> s; 
    s.push(root);
    while(!s.empty()){
        TreeNode* temp = s.top();
        myprint(temp);
        s.pop();
        if(temp->left) 
            s.push(temp->left);
        if(temp->right)
            s.push(temp->right);
    }
}
void postorder(TreeNode* root){
    if(root == NULL) return;
}


void inorder(TreeNode* root){
    if(root == NULL) return;
    stack<TreeNode*> s;
    s.push(root);
    TreeNode* p = root;
    while(!s.empty() || p){
        while(p){
            s.push(p);
            p = p->left;
        } // 每次左走到底
        if(!s.empty()){
            p = s.top();
            s.pop();
            myprint(p);
            p = p->right;
        } 
        //肯定有个时刻p为空，那么这个时候就弹出并打印
        //然后再去栈顶结点的右子树，继续
    }
}