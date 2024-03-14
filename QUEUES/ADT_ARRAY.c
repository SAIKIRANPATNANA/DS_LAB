#include <stdio.h>
int front = -1;
int back = -1;
int q[100];
void Push(int val){
    if(front==-1){
        front++;
    }back++;
    q[back] = val;
    return;
}int Front(){
    if(front==-1){
        printf("queue is empty..!\n");
        return -1;
    }return q[front];
}void Pop(){
    if(front==-1){
        printf("queue is empty..!\n");
        return;
    }else{
        for(int i=1; i<back; i++){
            q[i-1] = q[i];
            q[i] = q[i+1];
        }q[back] = -1;
        back--;
    }
}void Display(){
    if(front==-1){
        printf("queue is empty..!\n");
    }else {
        for(int i=0; i<=back; i++){
            printf("%d ",q[i]);
        }printf("\n");
    }
}int no_of_elements(){
    if(front==-1){
        return 0;
    }return back-front+1;
}int sum_of_elements(){
    int sum = 0;
    if(front==-1){
        return 0;
    }for(int i=front; i<=back; i++){
        sum += q[i];
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