#include <stdio.h>
#include <stdlib.h>
struct Node{
    int val;
    struct Node* next;
}typedef Node;
Node* head = NULL;
void addNode(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = value;
    newNode->next = NULL;
    if(!head){
        head = newNode;
    }else{
        newNode->next = head;
        head = newNode;
    }return;
}void deleteNode(int value){
    if(!head){
        return;
    }Node* temp = head;
    if(temp->val == value){
        Node* dup = head;
        head = head->next;
        free(dup);
        return;
    }while(temp->next){
        if(temp->next->val == value){
            Node* dup = temp->next;
            if(temp->next->next==NULL){ 
                temp->next = NULL;
            }else{
                temp->next = temp->next->next;
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