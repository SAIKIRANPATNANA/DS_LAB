#include <stdio.h>
#include <stdlib.h>
#define maxi 100
int st[maxi];
int last = -1;
int n = 0;
void pushSt(int value){
    if(n==maxi){
        printf("St is full\n");
    }else{
        last++; n++;
        st[last] = value;
    }return;
}void popSt(){
    if(last==-1){
        printf("St is empty\n");
    }else{
        printf("%d\n",st[last]);
        st[last] = -1;
        last--; n--;
    }return;
}void displaySt(){
    if(last==-1 || !n){
        printf("St is empty\n");
    }else{
        for(int i=last; i>=0; i--){
            printf("%d ", st[i]);
        }printf("\n");
    }return;
}struct Node{
    int val;
    struct Node* next;
 }typedef Node;
Node* Last = NULL;
int m = 0;
void pushNodeSt(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = value;
    newNode->next = NULL;
    if(Last==NULL){
        Last = newNode; m++;
    }else{
        newNode->next = Last;
        Last = newNode; m++;
    }return;
}void popNodeSt(){
    if(Last==NULL){
        printf("St is empty\n");
    }else{
        printf("%d \n",Last->val);
        Node* temp = Last;
        Last = Last->next;
        free(temp); m--;
    }return;
}void displayNodeSt(){
    if(Last==NULL){
        printf("St is empty\n");
    }else{
        Node* temp = Last;
        while(temp){
            printf("%d ",temp->val);
            temp = temp->next;
        }printf("\n");
    }return;
}int main(){
    pushSt(1);
    pushSt(2);
    displaySt();
    pushSt(3);
    pushSt(4);
    displaySt();
    popSt();
    popSt();
    displaySt();
    pushNodeSt(1);
    pushNodeSt(2);
    displayNodeSt();
    pushNodeSt(3);
    pushNodeSt(4);
    displayNodeSt();
    popNodeSt();
    popNodeSt();
    displayNodeSt();
    return 0;
}