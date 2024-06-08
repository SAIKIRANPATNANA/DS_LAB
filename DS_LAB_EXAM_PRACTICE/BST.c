#include <stdio.h>
#include <stdlib.h>
struct Node{
    struct Node* left;
    struct Node* right;
    int value;
}typedef Node;
Node* createNode(int value){
    Node* node =(Node*)malloc(sizeof(Node));
    node->left = NULL;
    node->right = NULL;
    node->value = value;
    return node;
}Node* insertNode(Node* root, int value){
    if(!root){
        root = createNode(value);
    }else if(root->value>value){
        root->left = insertNode(root->left, value);
    }else{
        root->right = insertNode(root->right, value);
    }return root;
}int getMax(Node* root){
    if(!root){
        return -1;
    }int a = getMax(root->left);
    int b = getMax(root->right);
    int max;
    if(root->value>a){
        if(root->value>b){
            max = root->value;
        }else{
            max = b;
        }
    }else{
        if(a>b){
            max = a;
        }else{
            max = b;
        }
    }return max;
}Node* deleteNode(Node* root, int value){
   if(!root){
     return NULL;
   }if(root->value == value){
        if(!root->left && !root->right){
            free(root);
            root = NULL;
        }else if(root->left && root->right){
            Node* temp = root->left;
            while(temp->right){
                temp = temp->right;
            }root->value = temp->value;
            root->left = deleteNode(root->left,temp->value);
        }else{
            if(root->left){
                Node* temp = root;
                root =  root->left;
                free(temp);
            }else{
                Node* temp = root->right;
                root = root->right;
                free(temp);
            }
        }
   }else if(root->value>value){
        root->left = deleteNode(root->left,value);
   }else{
        root->right = deleteNode(root->right,value);
   }return root;
}int getHeight(Node* root){
    if(!root){
        return 0;
    }int a = 0, b = 0;
    if(root->left){
        a = 1+getHeight(root->left);
    }if(root->right){
        b = 1+getHeight(root->right);
    }return a>=b? a: b;
}void inorderRecursively(Node* root){
    Node* st[100];
    int top = -1;
    while(1){
        while(root){
            top++;
            st[top] = root;
            root = root->left;
        }if(top==-1){
            break;
        }root = st[top];
        top--;
        printf("%d ",root->value);
        root = root->right;
    }return;
}void inorderTraversal(Node* root){
    if(!root){
        return;
    }inorderTraversal(root->left);
    printf("%d ",root->value);
    inorderTraversal(root->right);
    return;
}void postOrderTraversal(Node* root){
    if(!root){
        return;
    }inorderTraversal(root->left);
    inorderTraversal(root->right);
    printf("%d ",root->value);
    return;
}int main(){
    Node* root = NULL;
    root = insertNode(root,10);
    root = insertNode(root,5);
    root = insertNode(root,15);
    root = insertNode(root,3);
    root = insertNode(root,7);
    root = insertNode(root,12);
    printf("%d\n",getHeight(root));
    inorderRecursively(root);
    printf("\n");
    inorderTraversal(root);
    printf("\n");
    root = deleteNode(root,15);
    inorderTraversal(root);
    printf("\n");
    root = deleteNode(root,12);
    inorderTraversal(root);
    printf("\n");
    root = deleteNode(root,10);
    inorderTraversal(root);
    printf("\n");
    printf("%d\n",getHeight(root));
    return 0;
}