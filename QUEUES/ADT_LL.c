#include <stdio.h>
#include <stdlib.h>
struct Queue{
    int val;
    struct Queue* next;
}typedef Queue;
Queue* q = NULL;
void Push(int val){
    Queue* new_q = (Queue*) malloc(sizeof(Queue));
    new_q->val = val;
    new_q->next = NULL;
    if(q==NULL){
        q = new_q;
    }else{
        Queue* temp_q = q;
        while(temp_q->next!=NULL){
            temp_q = temp_q->next;
        }temp_q->next = new_q;
    }return;
}int Front(){
    if(q==NULL){
        printf("q is empty..!\n");
        return -1;
    }return q->val;
}void Pop(){
    if(q==NULL){
        printf("q is empty..!\n");
    }else{
        Queue* temp_q = q;
        q = q->next;
        free(temp_q);
    }return;
}void Display(){
    if(q==NULL){
        printf("q is empty..!\n");
        return;
    }else{
        Queue* temp_q = q;
        while(temp_q!=NULL){
            printf("%d ", temp_q->val);
            temp_q = temp_q->next;
        }printf("\n");
    }return;
}int no_of_elements(){
    if(q==NULL){
        return 0;
    }int n = 0;
    Queue* temp_q = q;
    while(temp_q!=NULL){
        n++;
        temp_q = temp_q->next;
    }return n;
}int sum_of_elements(){
    if(q==NULL){
        return 0;
    }int sum = 0;
    Queue* temp_q = q;
    while(temp_q!=NULL){
        sum += temp_q->val;
        temp_q = temp_q->next;
    }return sum;
}int main() {
   for(int i=1; i<=5; i++){
        Push(i);
    }Display();
    Pop();
    Display();
    Push(1);
    Display();
    printf("%d\n", Front());
    Pop();
    Display();
    Push(2);
    Display();
    printf("%d\n", no_of_elements());
    printf("%d\n", sum_of_elements());
    return 0;
}