#include <stdio.h>
#include <stdlib.h>
struct Node{
    int val;
    Node* next;
}typedef Node;
Node* head = NULL;
int getLength(){
    int n = 0;
    Node* temp = head;
    while(temp){
        n++;
        temp = temp->next;
    }return n;
}void addAtStart(int val){
    Node* newNode = (Node*) malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->next = NULL;
    if(!head){
        head = newNode;
    }else{
        newNode->next = head;
        head = newNode;
    }return;
}void deleteAtStart(){
    if(!head){
        return;
    }else{
        Node* dup = head;
        head = head->next;
        free(dup);
    }return;
}void traverse(){
    if(!head) return;
    Node* temp = head;
    while(temp){
        printf("%d ",temp->val);
        temp = temp->next;
    }printf("\n");
}int main(){
    addAtStart(1);
    addAtStart(2);
    addAtStart(3);
    traverse();
    printf("%d\n",getLength());
    deleteAtStart();
    traverse();
    printf("%d\n",getLength());
    return 0;
}