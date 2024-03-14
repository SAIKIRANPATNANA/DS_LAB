#include <stdio.h>
#include <stdlib.h>
struct DNode{
    struct DNode* next;
    struct DNode* prev;
    int val;
}typedef DNode;
DNode* Dhead = NULL;
void addDCNodeEnding(int value){
    DNode* newDNode = (DNode*)malloc(sizeof(DNode));
    newDNode->next = NULL;
    newDNode->val = value;
    if(Dhead == NULL) {
        Dhead = newDNode;
        Dhead->prev = Dhead;
        Dhead->next = Dhead;
    }else {
        DNode* temp = Dhead;
        do {
            temp = temp->next;
        }while(temp->next!=Dhead);
        temp->next = newDNode;
        newDNode->prev = temp;
        newDNode->next = Dhead;
        Dhead->prev = newDNode;
    }return;
}void addDCNodeBeginning(int value){
    DNode* newDNode = (DNode*)malloc(sizeof(DNode));
    newDNode->val = value;
    if(Dhead==NULL) {
        Dhead = newDNode;
        Dhead->prev = Dhead;
        Dhead->next = Dhead;
    }else {
        newDNode->prev = Dhead->prev;
        Dhead->prev->next = newDNode;
        Dhead->prev = newDNode;
        newDNode->next = Dhead;
        Dhead = newDNode;
    }return;
}void addDCNodek(int value, int k){
    DNode* newDNode = (DNode*)malloc(sizeof(DNode));
    newDNode->val = value;
    DNode* temp = Dhead;
    int n = 0;
    do{
        temp = temp->next;
        n++;
    }while(temp!=Dhead);
    int i=0;
    if(k==1){
        addDCNodeBeginning(value);
        return;
    }else if(k==n){
        addDCNodeEnding(value);
        return;
    }else{
        while(i<k-2){
            temp = temp->next;
            i++;
        }newDNode->next = temp->next;
        newDNode->prev = temp;
        temp->next->prev = newDNode;
        temp->next = newDNode;
    }return;
}void deleteDCNodeEnding() {
    if(Dhead==NULL){
        return;
    }else {
        DNode* temp = Dhead;
        do {
            temp = temp->next;
        }while(temp->next->next!=Dhead);
        DNode* dup = temp->next;
        temp->next->next->prev = temp;
        temp->next = temp->next->next;
        free(dup);
    }return;
}void deleteDCNodeBeginning(){
    if(Dhead==NULL){
        return;
    }else{
        DNode* temp = Dhead;
        Dhead->prev->next = Dhead->next;
        Dhead->next->prev = Dhead->prev;
        Dhead = Dhead->next;
        free(temp);
    }return;
}void deleteDNodeK(int k){
    if(Dhead==NULL){
        return;
    }else{
        DNode* temp = Dhead;
        int n = 0;
        do{
            temp = temp->next;
            n++;
        }while(temp!=Dhead);
        if(k>n){
            return;
        }if(k==1){
            deleteDCNodeBeginning();
            return;
        }else if(k==n){
            deleteDCNodeEnding();
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
}void DCNodeTraversal(){
    DNode* temp = Dhead;
    do{
        printf("%d ",temp->val);
        temp = temp->next;
    }while(temp!=Dhead);
    printf("\n");
    return;
}int main(){
    // enter your stuff here...
    return 0;
}

