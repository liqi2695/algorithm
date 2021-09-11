#include "frame.h"

//几种遍历的框架

//数组的遍历
void traverse(vector<int> arr){
    for(int i = 0; i < arr.size(); i++)
        cout<<arr[i]<<endl;
}

//链表的遍历   迭代 / 递归
typedef struct node{
    int val;
    node *next;
}ListNode;

void traverse_list(ListNode *head){
    ListNode *p;
    for(p = head; p != NULL; p = p->next)
        cout<<p->val<<endl;
}

void traverse_list_re(ListNode *head){
    traverse_list_re(head->next);
}

//二叉树的遍历
typedef struct node{
    int val;
    node *left,*right;
}TreeNode;

void traverse_binary(TreeNode *root){
    traverse_binary(root->left);
    traverse_binary(root->right);
}



//N叉树的遍历
typedef struct node
{
    int val;
    vector<node*> children;
}TreeNode_n;

void traverse_n(TreeNode_n *root){
    for(auto child : root->children)
        traverse_n(child);
}