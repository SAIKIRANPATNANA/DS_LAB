#include <stdio.h>
#include <stdlib.h>
struct DNode{
    struct DNode* next;
    struct DNode* prev;
    int val;
}typedef DNode;
DNode* Dhead = NULL;
void addDNodeEnding(int value){
    DNode* newDNode = (DNode*)malloc(sizeof(DNode));
    newDNode->next = NULL;
    newDNode->val = value;
    if(Dhead == NULL) {
        Dhead = newDNode;
        Dhead->prev = NULL;
    }else {
        DNode* temp = Dhead;
        while(temp->next!=NULL){
            temp = temp->next;
        }newDNode->prev = temp;
        temp->next = newDNode;
    }return;
}void addDNodeBeginning(int value){
    DNode* newDNode = (DNode*)malloc(sizeof(DNode));
    newDNode->val = value;
    if(Dhead==NULL) {
        Dhead = newDNode;
        Dhead->prev = NULL;
        Dhead->next = NULL;
    }else {
        Dhead->prev = newDNode;
        newDNode->prev = NULL;
        newDNode->next = Dhead;
        Dhead = newDNode;
    }return;
}void addDNodek(int value, int k){
    DNode* newDNode = (DNode*)malloc(sizeof(DNode));
    newDNode->val = value;
    DNode* temp = Dhead;
    int n = 0;
    while(temp!=NULL){
        temp = temp->next;
        n++;
    }int i=0;
    while(i<k-2){
        temp = temp->next;
        i++;
    }newDNode->next = temp->next;
    newDNode->prev = temp;
    temp->next->prev = newDNode;
    temp->next = newDNode;
    return;
}void deleteDNodeEnding() {
    if(Dhead==NULL){
        return;
    }else {
        DNode* temp = Dhead;
        while(temp->next->next!=NULL){
            temp = temp->next;
        }DNode* dup = temp->next;
        temp->next = temp->next->next;
        free(dup);
    }return;
}void deleteDNodeBeginning(){
    if(Dhead==NULL){
        return;
    }else{
        DNode* temp = Dhead;
        Dhead->next->prev = NULL;
        Dhead = Dhead->next;
        free(temp);
    }return;
}void deleteDNodeK(int k){
    if(Dhead==NULL){
        return;
    }else{
        DNode* temp = Dhead;
        int n = 0;
        while(temp!=NULL){
            temp = temp->next;
            n++;
        }if(k>n){
            return;
        }if(k==1){
            deleteDNodeBeginning();
            return;
        }else if(k==n){
            deleteDNodeEnding();
            return;
        }int i=0;
        temp = Dhead;
        while(i<k-2){
            temp = temp->next;
            i++;
        }DNode* dup = temp->next;
        temp->next->next->prev = temp;
        temp->next = temp->next->next;
        free(dup);
    }return;
}void DNodeTraversal(){
    DNode* temp = Dhead;
    while(temp!=NULL){
        printf("%d ",temp->val);
        temp = temp->next;
    }printf("\n");
    return;
}int main(){
    // enter your stuff here..
    return 0;
}

