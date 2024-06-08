#include <stdio.h>
#include <stdlib.h>
struct Node{
    int val;
    struct Node* next;
    struct Node* prev;
}typedef Node;
Node* head = NULL;
void addNode(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    if(!head){
        head = newNode;
    }else{
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }return;
}void deleteNode(int value){
    if(!head){
        return;
    }Node* temp = head;
    if(temp->val == value){
        Node* dup = head;
        head->next->prev = NULL;
        head = head->next;
        free(dup);
        return;
    }while(temp){
        if(temp->val == value){
            Node* dup = temp;
            if(temp->next==NULL){ 
                temp->prev->next = NULL;
            }else{
                temp->next->prev = temp->prev;
                temp->prev->next = temp->next;
            }free(dup); break;
        }temp = temp->next;
    }return;
}void dipslayList(){
    if(!head){
        return;
    }Node *temp = head;
    while(temp){
        printf("%d ", temp->val);
        temp = temp->next;
    }printf("\n");
    return;
}int main(){
    addNode(1);
    addNode(2);
    addNode(3);
    dipslayList();
    deleteNode(2);
    addNode(4);
    deleteNode(1);
    dipslayList();
    deleteNode(4);
    dipslayList();
    return 0;
}