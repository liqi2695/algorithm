#### [95. 不同的二叉搜索树 II](https://leetcode-cn.com/problems/unique-binary-search-trees-ii/)



**解题思路**：

​	对于此题来说，任何一个数1~n都是可以当树的root节点的。那么不妨去i在1~n之间，那么从1到i-1为左子树选择集合，i+1到n为右子选择集合。然后再在左子树和右子树集合中选一个数来做左子树和右子树。

**代码实现**：

```cc
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int start,int end){
        if(start > end)
            return {nullptr};
        vector<TreeNode*> allTrees;
        for(int i = start; i <= end; i++){
            //取所有的左子树和右子树的集合
            vector<TreeNode*> leftTrees = generateTrees(start, i - 1);
            vector<TreeNode*> rightTrees = generateTrees(i + 1, end);

            for(auto p_left : leftTrees){
                for(auto p_right : rightTrees){
                    TreeNode* curRoot = new TreeNode(i);
                    curRoot->left = p_left;
                    curRoot->right = p_right;
                    allTrees.emplace_back(curRoot);
                }
            }
        }
        return allTrees;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(!n) return {};
        return generateTrees(1,n);
    }
};
```

