#include <stdio.h>
#include <stdlib.h>
#define max 100
struct Node{
    struct Node* next;
    struct Node* prev;
    int val;
}typedef Node;
Node* front = NULL;
Node* rear = NULL;
int size = 0;
void insert(int value){
    Node* newNode = (Node*)malloc(sizeof(struct Node));
    newNode->val = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    if(!front){
        front = newNode;
        rear = newNode;
        size++; 
    }else{
        newNode->prev = rear;
        rear->next = newNode;
        rear = newNode;
        size++;
    }return;
}void remove(){
    if(!front){
        return;
    }else{
        Node* dup = front;
        // front->next->prev = NULL;
        front = front->next;
        free(dup);
        size--;
    }return ;
}void display(){
    if(!front) return;
    Node* temp = front;
    while(temp){
        printf("%d ",temp->val);
        temp = temp->next;
    }printf("\n");
    return;
}int main(){
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    display();
    remove();
    remove();
    display();
    insert(5);
    insert(6);
    display();
    return 0;
}