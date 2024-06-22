#include <stdio.h>
#include <stdlib.h>
#define maxi 100
struct Node{
    struct Node* left;
    struct Node* right;
    int val;
}typedef Node;
Node* insertNode(Node* root, int value){
    Node* newNode = (Node*)malloc(sizeof(struct Node));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->val = value;
    if(!root){
        root = newNode;
    }else if(root->val>=value){
        root->left = insertNode(root->left,value);
    }else{
        root->right = insertNode(root->right,value);
    }return root;
}Node* deleteNode(Node* root, int value){
    if(!root){
        return NULL;
    }else if(root->val>value){
        root->left = deleteNode(root->left,value);
    }else if(root->val<value){
        root->right = deleteNode(root->right,value);
    }else{
        if(!root->left && !root->right){
            Node* dup = root;
            root = NULL;
            free(dup);
        }else if(root->right && root->left){
            Node* temp = root->left;
            while(temp->right){
                temp = temp->right;
            }root->val = temp->val;
            root->left = deleteNode(root->left,temp->val);
        }else if(root->left){
            Node* dup = root;
            root = root->left;
            free(dup);
        }else{
            Node* dup = root;
            root = root->right;
            free(dup);
        }
    }return root;
}void postOrder(Node* root){
    if(!root){
        return;
    }postOrder(root->left);
    postOrder(root->right);
    printf("%d ",root->val);
    return;
}void inOrderRecursive(Node* root){
    Node* st[maxi];
    int top = -1;
    while(1){
        while(root){
            st[++top] = root;
            root = root->left;
        }if(top == -1){
            break;
        }root = st[top--];
        printf("%d ", root->val);
        root = root->right;
    }return;
}int main(){
    Node* root = NULL;
    root = insertNode(root,10);
    root = insertNode(root,5);
    root = insertNode(root,15);
    root = insertNode(root,3);
    root = insertNode(root,7);
    root = insertNode(root,12);
    root = insertNode(root,20);
    postOrder(root);
    printf("\n");
    inOrderRecursive(root);
    printf("\n");
    root = deleteNode(root,10);
    postOrder(root);
    printf("\n");
    inOrderRecursive(root);
    printf("\n");
    root = deleteNode(root,20);
    postOrder(root);
    printf("\n");
    inOrderRecursive(root);
    printf("\n");
    root = deleteNode(root,7);
    inOrderRecursive(root);
    printf("\n");
    postOrder(root);
    printf("\n");
    return 0;
}