#include <stdio.h>
#include <stdlib.h>
struct TreeNode{
    struct TreeNode* left;
    struct TreeNode* right;
    int val;
}typedef TreeNode;
TreeNode* addTreeNode(int val){
    TreeNode* newTreeNode = (TreeNode*) malloc(sizeof(TreeNode));
    newTreeNode->val = val;
    newTreeNode->right = NULL;
    newTreeNode->left = NULL;
    return newTreeNode;
}void PreorderTraversal(TreeNode* root){
    if(!root){
        return;
    }printf("%d ",root->val);
    PreorderTraversal(root->left);
    PreorderTraversal(root->right);
    return;
}void PostorderTraversal(TreeNode* root){
    if(!root){
        return;
    }PostorderTraversal(root->left);
    PostorderTraversal(root->right);
    printf("%d ",root->val);
    return;
}void InorderTraversal(TreeNode* root){
    if(!root){
        return;
    }InorderTraversal(root->left);
    printf("%d ",root->val);
    InorderTraversal(root->right);
    return;
}int getMax(TreeNode* root){
    if(!root){
        return 0;
    }int max = root->val;
    int right = getMax(root->right);
    int left = getMax(root->left);
    if(right<left){
        if(max<left){
            max = left;
        }
    }else{
        if(max<right){
            max = right;
        }
    }return max;
}int getMin(TreeNode* root){
    if(!root){
        return 1000;
    }int min = root->val;
    int right = getMin(root->right);
    int left = getMin(root->left);
    if(right>left){
        if(min>left){
            min = left;
        }
    }else{
        if(min>right){
            min = right;
        }
    }return min;
}int getHeight(TreeNode* root){
    if(!root){
        return 0;
    }int left = 1+getHeight(root->left);
    int right = 1+getHeight(root->right);
    int max = left<right? right : left;
    return max;
}int main() {
    TreeNode* root = NULL;
    root = addTreeNode(5);
    root->right = addTreeNode(8);
    root->left = addTreeNode(3);
    root->right->right = addTreeNode(9);
    root->right->left = addTreeNode(7);
    root->left->right = addTreeNode(4);
    root->left->left = addTreeNode(2);
    PreorderTraversal(root);
    printf("\n");
    InorderTraversal(root);
    printf("\n");
    PostorderTraversal(root);
    printf("\n");
    printf("%d\n",getMax(root));
    printf("%d\n",getMin(root));
    printf("%d\n",getHeight(root)-1);
    return 0;
}