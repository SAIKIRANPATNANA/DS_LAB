#include <stdio.h>
#include <stdlib.h>
struct Node {
    struct Node* next;
    int val;
}typedef Node;
Node* head = NULL;
void addCNodeBeginning(int value){
  Node* newNode = (Node*)malloc(sizeof(Node));
    if(head==NULL){
        head = newNode;
        head->next = head;
    }else {
        Node* temp = head;
        while(temp->next!=head){
        temp = temp->next;
    }temp->next = newNode;
        newNode->next = head;
    }return;
}void addCNodeEnding(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(head==NULL){
        head = newNode;
        head->next = head;
    }else {
        Node* temp = head;
        do {
            temp = temp->next;
        }while(temp->next != head);
        newNode->next = temp->next;
        temp->next = newNode;
    }return;
}void addCNodeK(int value, int k){
    Node* newNode = (Node*)malloc(sizeof(Node));
    Node* temp = head;
    int n = 0;
    do{
        temp = temp->next;
        n++;
    }while(temp->next!=head);
    if(k==1){
        addCNodeBeginning(value);
    }else if(k==n+1){
        addCNodeEnding(value);
    }else{
        int i = 0;
        while(i<k-2){
            temp = temp->next;
            i++;
        }newNode->next = temp->next;
        temp->next = newNode;
    }return;
}void deleteCNodeBeginning(){
    Node* temp = head;
    if(head==NULL){
        return;
    }else{
        do {
          temp = temp->next;
        }while(temp->next!=head);
    }Node* dup = head;
    temp->next = head->next;
    head = head->next;
    free(dup);
    return;
}void deleteCNodeEnding(){
    if(head==NULL){
        return;
    }else {
        Node* temp = head;
        do {
            temp = temp->next;
        }while(temp->next->next!=head);
        Node* dup = temp->next;
        temp->next = head;
        free(dup);
    }return;
}void deleteCNodeK(int k){
    if(head==NULL){
        return;
    }else {
        Node* temp = head;
        int n = 0;
        do{
            temp = temp->next;
            n++;
        }while(temp!=head);
        if(k>n){
            return;
        }else if(k==1){
            deleteCNodeBeginning();
            return;
        }else if(k==n){
            deleteCNodeEnding();
            return;
        }else{
            Node* temp = head;
            int i = 0;
            while(i<k-2){
                i++;
                temp = temp->next;
            }Node* dup = temp->next;
            temp->next = temp->next->next;
            free(dup);
        }
    }return;
}void createCircle(){
    if(head == NULL){
        return;
    }else{
        Node* temp = head;
        do {
            temp = temp->next;
        }while(temp->next!=NULL);
        temp->next = head;
    }return;
}void CNodeTraversal(){
    Node* temp = head;
    do{
        printf("%d ", temp->val);
        temp = temp->next;
    }while(temp!=head);
    printf("\n");
    return;
}int main() {
    // enter your stuff here...
    return 0;
}