#include <stdio.h>
#define maxi 5
int CQ[maxi];
int front = -1, rear = -1;
void pushCQ(int value){
    if((rear+1)%maxi == front){
        printf("CQ is full\n");
    }else{
        if(front == -1 && rear==-1){
            front++; rear++;
            CQ[rear] = value;
        }else{
            rear = (rear+1)%maxi;
            CQ[rear] = value;
        }
    }return;
}void popCQ(){
    if(front == -1 && front == -1){
        printf("CQ is empty\n");
    }else if(front == rear){
        printf("%d\n",CQ[front]);
        rear = -1;
        front = -1;
    }else{
        printf("%d\n",CQ[front]);
        front = (front+1)%maxi;
    }return;
}void displayCQ(){
    int i = front;
    while(i!=rear){
        printf("%d\n",CQ[i]);
        i = (i+1)%maxi;
    }printf("%d\n",CQ[i]);//keep in mind
    return;
}int main(){
    pushCQ(1);
    pushCQ(2);
    pushCQ(3);
    displayCQ();
    pushCQ(4);
    displayCQ();
    popCQ();
    popCQ();
    return 0;
}