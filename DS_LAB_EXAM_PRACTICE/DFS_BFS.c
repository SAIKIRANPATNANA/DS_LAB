#include <stdio.h>
#include <stdlib.h>
#define max_size 100    
struct Node{
    int value;
    struct Node *next;
}typedef Node;
struct Graph{
    Node* adjList[max_size];
    int n;
}typedef Graph;
Node* createNode(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}Graph* createGraph(int n){
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->n = n;
    for(int i=0; i<n; i++){
        graph->adjList[i] = NULL;
    }return graph;
}void addEdge(Graph* graph, int src, int destiny){
    Node* newNode = createNode(destiny);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
    newNode = createNode(src);
    newNode->next = graph->adjList[destiny];
    graph->adjList[destiny] = newNode;
    return;
}void dfs(Graph* graph, int start, int *flag){
    printf("%d\n", start);
    flag[start] = 0;
    Node* neighbor = graph->adjList[start];
    while(neighbor){
        if(flag[neighbor->value]){
            dfs(graph,neighbor->value,flag);
        }neighbor = neighbor->next;
    }return;
}int front = -1, back = -1, size = 0;
int Q[max_size];
void pushQ(int value){
    if(front==-1){
        front++;
    }Q[++back] = value;
    size++;
    return;
}void popQ(){ 
    Q[front] = -1;
    front++;
    size--;
    return;
}void bfs(Graph* graph, int start){
    pushQ(start);
    int flag[graph->n];
    for(int i=0; i<graph->n; i++){
        flag[i] = 1;
    }flag[start] = 0;
    while(front==-1 || size){
        printf("%d\n", Q[front]);
        Node* neighbor = graph->adjList[Q[front]];
        while(neighbor){
            if(flag[neighbor->value]){
                pushQ(neighbor->value);
                flag[neighbor->value] = 0;
            }neighbor = neighbor->next;
        }popQ();
    }return;
}int main(){
    Graph*  graph = createGraph(4);
    addEdge(graph,0,1);
    addEdge(graph,0,2);
    addEdge(graph,1,2);
    addEdge(graph,2,3);  
    int flag[4];    
    for(int i=0; i<4; i++){
        flag[i] = 1;
    }dfs(graph,0,flag);
    printf("\n");
    bfs(graph,0);
    return 0;
}