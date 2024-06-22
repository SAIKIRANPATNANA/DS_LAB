#include <stdio.h>
#include <stdlib.h>
#define maxi 100
struct Node{
    struct Node* next;
    int val;
}typedef Node;
Node* graph[maxi];
void insertEdge(int a, int b){
    Node* newNode1 = (Node*)malloc(sizeof(struct Node));
    newNode1->val = b;
    newNode1->next = graph[a];
    graph[a] = newNode1;
    Node* newNode2 = (Node*)malloc(sizeof(struct Node));
    newNode2->val = a;
    newNode2->next = graph[b];
    graph[b] = newNode2;
    return;
}void dfs(int value, int* flag){
    printf("%d ", value);   
    flag[value] = 0;
    Node* temp = graph[value];
    while(temp){
        if(flag[temp->val]) dfs(temp->val, flag);
        temp = temp->next;
    }return;
}int q[maxi];
int front = -1, rear = -1, size = 0;
void pushQ(int val){
    if(front==-1 && rear==-1){
        front++; rear++;
        q[rear] = val;
    }else{
        q[++rear] = val;
    }size++;
    return;
}int popQ(){
    if(front==-1){
        return -1;
    }int value = q[front];
    q[front] = -1;
    front++; size--;
    return value;
}void bfs(int start, int n){
    pushQ(start);
    int flag[maxi];
    for(int i=0; i<n; i++){
        flag[i] = 1;
    }flag[start] = 0;
    while(size){
        int value = popQ();
        Node* temp = graph[value];
        while(temp){
            if(flag[temp->val]){
                flag[temp->val] = 0;
                pushQ(temp->val);
            }temp = temp->next;
        }printf("%d ", value);
   }return;
}int main(){
    int n,e;
    scanf("%d %d", &n,&e);
    while(e){
        int a,b;
        scanf("%d %d", &a,&b);
        insertEdge(a,b);
        e--;
    }int flag[n];
    for(int i=0; i<n; i++){
        flag[i] = 1;
    }dfs(0,flag);
    printf("\n");
    bfs(0,n);
    printf("\n");
    return 0;
}