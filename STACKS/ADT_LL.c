#include <stdio.h>
#include <stdlib.h>
struct stack{
    struct stack* next;
    int val;
}typedef stack;
stack* Top = NULL;
void Push(int x){
    stack* st = (stack*)malloc(sizeof(stack));
    st->val = x;
    if(Top==NULL){
        Top = st;
        Top->next = NULL;
    }else{
        st->next = Top;
        Top = st;
    }return;
}void Pop(){
    if(Top==NULL){
        printf("empty stack!\n");
        return;
    }stack* dup = Top;
    Top = Top->next;
    free(dup);
    return;
}int top(){
    if(Top!=NULL){
        return Top->val;
    }printf("empty stack\n");
    return -1;
}void display(){
    if(Top==NULL){
        printf("empty stack!\n");
        return;
    }stack* st = Top;
    while(st!=NULL){
        printf("%d ",st->val);
        st = st->next;
    }printf("\n");
    return;
}int main(){
    // enter your stuff here..!
    return 0;
}
