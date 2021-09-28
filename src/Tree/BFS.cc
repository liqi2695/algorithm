#include "treenode.h"

void BFS(TreeNode* root){
    if(root == NULL) return;
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty()){
        TreeNode* cur = que.front();
        que.pop();
        cout << cur->val << endl;
        if(cur->left) 
            que.push(cur->left);
        if(cur->right)
            que.push(cur->right);
    }
}


int maxWidth(TreeNode* root){
    if(root == NULL) return -1;
    queue<TreeNode*> que;
    que.push(root);
    map<TreeNode*, int> levelMap;
    levelMap.insert(pair<TreeNode*,int>(root,1));
    //将头节点插入map中，此时层数为1层（map的作用就是用来记住某个节点的层数）
    int curLevel = 0; //当前层数
    int curLevelNodes = 0; //当前层的节点个数
    int Max = INT_MIN; //最大值先去最小数
    while(!que.empty()){
        TreeNode* cur = que.front();
        que.pop();
        //得到此节点的层数
        auto curNode = levelMap.find(cur);
        int curNodeLevel = curNode->second;
        //判断此节点的层数是否与curlevel相同
        //若不相同，则一定是进入了下一层，那么就要进行结算找max
        if(curNodeLevel == curLevel){
            curLevelNodes++;
        } else { 
            Max = max(Max, curLevelNodes);
            curLevel++; //层数++
            curLevelNodes = 1;
            //此时已经进入下一层的第一个节点了，那么curLevelNodes置1
        }
        //为了保证所有节点的层数都在levelMap中有记录，
        //那么就在入队的时候，要记录该节点的层数
        if(cur->left) {
            levelMap.insert(pair<TreeNode*, int>(cur->left, curLevel+1));
            //这里注意是curLevel+1，因为curLevel是cur的层数，
            //而这里cur已经指向了其左子树，所以层数要+1
            que.push(cur->left);
        }
        if(cur->right) {
            levelMap.insert(pair<TreeNode*,int>(cur->right,curLevel+1));
            que.push(cur->right);
        }
    }
    return Max;
}





void DFS(TreeNode* root){

}