#include <stdio.h>
#include <stdlib.h>
#define maxi 100
int Q[100];
int front = -1, back = -1, n = 0;
void pushQ(int value){
    if(n==maxi){
        printf("Q is full");
        return;
    }else if(front==-1){
        front++;
    }back++; n++;
    Q[back] = value;
    return;
}void popQ(){
    if(front==-1){
        printf("Q is empty");
        return;
    }printf("%d\n",Q[front]);
    front++; n--;
    return;
}void displayQ(){
    if(front==-1){
        printf("Q is empty");
    }for(int i=front; i<=back; i++){
        printf("%d ",Q[i]);
    }printf("\n");
    return;
}struct Node{
    int val;
    struct Node* next;
    struct Node* prev;
}typedef Node;
int m = 0;
Node* Front = NULL;
Node* Back = NULL;
void pushNodeQ(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->prev = NULL;
    newNode->next = NULL;
    newNode->val = value;
    if(Front==NULL && Back==NULL){
        Front = newNode;
        Back = newNode;
    }else{
        Back->next = newNode;
        newNode->prev = Back;
        Back = newNode;
        m++;
    }return;
}void popNodeQ(){
    if(Front==NULL && Back==NULL){
        printf("Q is empty\n");
    }else{
        Front->next->prev = NULL;
        Node* temp = Front;
        printf("%d\n", temp->val);
        Front = Front->next;
        free(temp);
        m--;
    }return;
}void displayNodeQ(){
    if(Front==NULL && Back==NULL){
        printf("Q is empty\n");
        return;
    }Node* temp = Front;
    while(temp!=Back){
        printf("%d ",temp->val);
        temp = temp->next;
    }printf("%d \n",temp->val);
    return;
}int main(){
    // pushQ(1);
    // pushQ(2);
    // displayQ();
    // pushQ(3);
    // pushQ(4);
    // displayQ();
    // popQ();
    // popQ();
    // displayQ();
    pushNodeQ(1);
    pushNodeQ(2);
    displayNodeQ();
    pushNodeQ(3);
    pushNodeQ(4);
    displayNodeQ();
    popNodeQ();
    popNodeQ();
    displayNodeQ();
    return 0;
}