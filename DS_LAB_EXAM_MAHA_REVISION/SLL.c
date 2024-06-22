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
}void addAtEnd(int val){
    Node* newNode = (Node*) malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->next = NULL;
    if(!head){
        head = newNode;
    }else{
        Node* temp = head;
        while(temp->next){
            temp = temp->next;
        }temp->next = newNode;
    }return;
}void addAtK(int val, int k){
    Node* newNode = (Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->next = NULL;
    if(!head){
        head = newNode;
    }else{
        int n = getLength();
        if(k==1){
            addAtStart(val);
        }else if(k==n+1){
            addAtEnd(val);
        }else{
            Node* temp = head;
            for(int i=0; i<k-2; i++){
                temp = temp->next;
            }newNode->next = temp->next;
            temp->next = newNode;
        }
    }return;
}void deleteAtStart(){
    if(!head){
        return;
    }else{
        Node* dup = head;
        head = head->next;
        free(dup);
    }return;
}void deleteAtEnd(){
    if(!head){
        return;
    }else{
        Node* temp = head;
        while(temp->next->next){
            temp = temp->next;
        }Node* dup = temp->next;
        temp->next = NULL;
        free(dup);
    }return;
}void deleteAtK(int k){
    if(!head){
        return;
    }else{
        int n = getLength();
        if(k==1){
            deleteAtStart();
        }else if(k==n){
            deleteAtEnd();
        }else{
            Node* temp = head;
            for(int i=0; i<k-2; i++){
                temp = temp->next;
            }Node* dup = temp->next;
            temp->next = temp->next->next;
            free(dup);
        }
    }return;
}void deleteVal(int val){
    Node* temp = head;
    int k = 1;
    while(temp && temp->val!=val){
        k++;
        temp = temp->next;
    }deleteAtK(k);
    return;
}void traverse(){
    if(!head) return;
    Node* temp = head;
    while(temp){
        printf("%d ",temp->val);
        temp = temp->next;
    }printf("\n");
}int main(){
    addAtStart(1);
    traverse();
    addAtEnd(2);
    traverse();
    addAtK(3,2);
    traverse();
    // deleteAtStart();
    // traverse();
    // deleteAtEnd();
    // traverse();
    // deleteAtK(1);
    // traverse();
    deleteVal(1);
    traverse();
    deleteVal(2);
    traverse();
    deleteVal(3);
    traverse();
    return 0;
}