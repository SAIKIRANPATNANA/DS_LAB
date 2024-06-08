#include <stdio.h>
int heap[100];
// heap[0] = -1;
int t = 0;
void insertInHeap(int value){
    t++;
    int n = t;
    heap[n] = value;
    while(n/2>0 && heap[n/2]>heap[n]){
        int temp = heap[n/2];
        heap[n/2] = heap[n];
        heap[n] = temp;
        n /= 2;
    }return;
}void deleteInHeap(){
    heap[1] = heap[t];
    heap[t] = -1;
    t--;
    int n = 1;
    while(n*2<=t || n*2+1<=t){
        if(n*2<=t && n*2+1<=t && heap[n*2]<heap[n*2+1] && heap[n]>heap[n*2]){
            int temp = heap[n];
            heap[n] = heap[n*2];
            heap[n*2] = temp;
            n = n*2;
        }else if(n*2<=t && n*2+1<=t && heap[n*2]>heap[n*2+1] && heap[n]>heap[n*2+1]){
            int temp = heap[n]; 
            heap[n] = heap[n*2+1];
            heap[n*2+1] = temp;
            n = n*2+1;
        }else if(n*2<=t && heap[n*2]<heap[n]){
            int temp = heap[n]; 
            heap[n] = heap[n*2];
            heap[n*2] = temp;
            n = n*2;
        }
    }return;
}void heapify(int* heap, int t){
    int n = t/2;
    while(n>0){
        if(n*2<=t && n*2+1<=t && heap[n*2]<heap[n*2+1] && heap[n]>heap[n*2]){
            int temp = heap[n];
            heap[n] = heap[n*2];
            heap[n*2] = temp;
        }else if(n*2<=t && n*2+1<=t && heap[n*2]>heap[n*2+1] && heap[n]>heap[n*2+1]){
            int temp = heap[n]; 
            heap[n] = heap[n*2+1];
            heap[n*2+1] = temp;
        }else if(n*2<=t && heap[n*2]<heap[n]){
            int temp = heap[n]; 
            heap[n] = heap[n*2];
            heap[n*2] = temp;
        }n--;
    }n=2;
    while(n*2<=t || n*2+1<=t){
        if(n*2<=t && n*2+1<=t && heap[n*2]<heap[n*2+1] && heap[n]>heap[n*2]){
            int temp = heap[n];
            heap[n] = heap[n*2];
            heap[n*2] = temp;
        }else if(n*2<=t && n*2+1<=t && heap[n*2]>heap[n*2+1] && heap[n]>heap[n*2+1]){
            int temp = heap[n]; 
            heap[n] = heap[n*2+1];
            heap[n*2+1] = temp;
        }else if(n*2<=t && heap[n*2]<heap[n]){
            int temp = heap[n]; 
            heap[n] = heap[n*2];
            heap[n*2] = temp;
        }n++;
    }return;
}void heapSort(int *heap, int t){
    while(t>0){
        heapify(heap,t);
        int temp = heap[1];
        heap[1] = heap[t];
        heap[t] = temp;
        t--;
    }return;
}int main(){
    insertInHeap(12);
    insertInHeap(11);
    insertInHeap(13);
    insertInHeap(5);
    insertInHeap(6);
    insertInHeap(7);
    for(int i=1; i<=t; i++){
        printf("%d ",heap[i]);
    }deleteInHeap();
    printf("\n");
    for(int i=1; i<=t; i++){
        printf("%d ",heap[i]);
    }int array[] = {-1,12,11,13,5,6,7};
    heapSort(array, 6);
    printf("\n");
    for(int i=1; i<=6; i++){
        printf("%d ",array[i]);
    }return 0;
}