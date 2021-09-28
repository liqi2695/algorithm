#include "treenode.h"

/*
--------------------------
coder:LQ
如何判断二叉树为完全二叉树？
1.任意一个节点，有右无左，肯定不是
2.在不违反1条件下，如果遇到了一个节点不双全（即左右子树不同时存在）
后面则都必须为叶节点，否则就不是完全二叉树
--------------------------
*/
bool isCompBinaryTree(TreeNode* root){
    if(root == NULL) return true;
    queue<TreeNode*> Queue;
    Queue.push(root);
    bool isAlone = false;
    while(!Queue.empty()){
        TreeNode* cur = Queue.front();
        Queue.pop();

        //神之一手
        if(
            //当曾经碰到过叶子不全的节点，并且当前节点居然有孩子，那么肯定不是完全二叉树
            (isAlone && (cur->left != nullptr || cur->right != nullptr))
            ||
            //有右无左，直接不是
            (cur->left == nullptr && cur->right != nullptr)
        ) {
            return false;
        }

        if(cur->left){
            Queue.push(cur->left);
        } 
        if(cur->right){
            Queue.push(cur->right);
        }
        //当遇到一个节点不双全
        if(cur->left == nullptr || cur->right == nullptr){
            isAlone = true;
        }
    }
}