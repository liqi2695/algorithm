#include "treenode.h"

//判断是否为二叉搜索树,即中序遍历后为递增序列
int preValue = INT_MIN;
bool isBST(TreeNode* root){
    if(root == NULL) return true;
    bool leftBst = isBST(root->left);
    if(!leftBst){
        return false;
    }
    //这里将原来中序遍历打印的代码变成比较
    if(preValue > root->val){
        return false;
    } else {
        preValue = root->val;
    }
    return isBST(root->right);
}
//非递归方法中序遍历判断 