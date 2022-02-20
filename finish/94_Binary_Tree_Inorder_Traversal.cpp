/*
Given the root of a binary tree, return the inorder traversal of its nodes' values.

不需要将左右返回的vector进行合并，因为他们都会加入到private的result中
*/
#include <vector>
#include <iostream>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// TreeNode* generateTree(vector<>)

class Solution {
private:
    std::vector<int> result;
public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr)
            return result;
        inorderTraversal(root->left);
        result.push_back(root->val);
        inorderTraversal(root->right);
        return result;    
    }
};