#include <stdio.h>
#define maxi 5
int cq[maxi];
int front = -1, rear = -1, size = 0;
void insert(int val){
    if(front==-1 && rear==-1){
        front++; rear++;
        cq[rear] = val;
        size ++;
    }else if((rear+1)%maxi == front){
        return;
    }else{
        rear = (rear+1)%maxi;
        cq[rear] = val;
        size++;
    }
}void remove(){
    if(front==-1 && rear==-1){
       return;
    }else if(rear == front){
        cq[rear] = -1;
        rear = -1; front = -1;
        size--;
    }else{
        cq[front] = -1;
        front = (front+1)%maxi;
        size--;
    }return;
}void traverse(){
    if(front==-1 && rear==-1){
        return;
    }else{
       for(int i=front; i!=rear; i = (i+1)%maxi){
            printf("%d ", cq[i]);
       }printf("%d \n",cq[rear]);
    }return;
}int main(){
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    traverse();
    remove();
    remove();
    traverse();
    remove();
    remove();
    insert(6);
    insert(7);
    traverse();
    return 0;
}

