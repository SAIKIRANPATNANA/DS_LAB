// #include <stdio.h>
// #include <stdlib.h>
// struct Node {
//     int val;
//     struct Node* next;
// }typedef Node;
// Node* addNode(Node* head, int value){
//     Node* newNode = (Node*)malloc(sizeof(Node));
//     newNode->next = NULL;
//     newNode->val = value;
//     if(head==NULL) {
//         head = newNode;
//     }else{
//         Node* temp = head;
//         while(temp->next!=NULL){
//             temp = temp->next;
//         }temp->next = newNode;
//     }return head;
// }Node* deleteNode(Node* head, int value){
//     Node* temp = head;
//     if(temp->val == value){
//         Node* dup = temp;
//         head = temp->next;
//         free(dup);
//         return head;
//     }while(temp->next!=NULL){
//         if(temp->next->val == value){
//             Node* dup = temp->next;
//             temp->next = temp->next->next;
//             free(dup);
//         }
//     }return head;
// }void displayNodes(Node* head){
//     Node* temp = head;
//     while(temp!=NULL){
//         printf("%d ", temp->val);
//         temp = temp->next;
//     }printf("\n");
//     return;
// }int main() {
//     Node* head = NULL;
//     int n = 3;
//     while(n--){
//         int x;
//         scanf("%d",&x);
//         head = addNode(head,x);
//     }displayNodes(head);
//     head = deleteNode(head,1);
//     displayNodes(head);
//     head = deleteNode(head,2);
//     displayNodes(head);
//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>
struct Node {
    struct Node* next;
    int val;
}typedef Node;
Node* head = NULL;
void addNodeEnding(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->val = value;
    if(head==NULL) {
        head = newNode;
    }else {
        Node* temp = head;
        while(temp->next!=NULL) {
            temp = temp->next;
        }temp->next = newNode;
    }return;
}void addNodeBeginning(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = value;
    if(head==NULL){
        head = newNode;
        head->next = NULL;
    }else {
        newNode->next = head;
        head = newNode;
    }return;
}void addNodeK(int value,int k) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = value;
    int n = 0;
    Node* temp = head;
    while(temp!=NULL) {
        temp = temp->next;
        n++;
    }temp = head;
    int i = 0;
    while(i<k-2) {
        temp = temp->next;
        i++;
    }newNode->next = temp->next;
    temp->next = newNode;
    return;
}void deleteNodeBeginning(){
    if(head==NULL) {
        return;
    }else {
        Node* temp = head;
        head = head->next;
        free(temp);
    }return;
}void deleteNodeEnding() {
    if(head==NULL) {
        return;
    }else{
        Node* temp = head;
        while(temp->next->next!=NULL){
            temp = temp->next;
        }Node* dup = temp->next;
        temp->next = temp->next->next;
        free(dup);
    }return ;
}void deleteNodeK(int k) {
    int n = 0;
    Node* temp = head;
    while(temp!=NULL){
        temp = temp->next;
        n++;
    }if(k>n) {
        return;
    }if(k==1) {
       deleteNodeBeginning();
       return;
    }if(k==n){
        deleteNodeEnding();
        return;
    }else{
        temp = head;
        int i = 0;
        while(i<k-2){
            temp = temp->next;
            i++;
        }Node* dup = temp->next;
        temp->next = temp->next->next;
        free(dup);
    }return;
}void nodeTraversal(){
    Node* temp = head;
    while(temp!=NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }printf("\n");
}int main(){
    // enter your stuff here...
    return 0;
}