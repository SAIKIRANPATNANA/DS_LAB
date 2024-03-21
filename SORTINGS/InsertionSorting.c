#include <stdio.h>
int compare_count = 0;
int swap_count = 0;
void insertionSort(int* array,int n){
    for(int i=1; i<n; i++){
        int j=i-1;
        int ele = array[i];
        while(array[j]>ele && j>=0){
            array[j+1] = array[j];
            j--;
            compare_count++;
        }array[j+1] = ele;
    }return;
}int main(){
    int array[] = {10,9,8,7,6,5,4,3,2,1};
    int n = sizeof(array)/sizeof(array[0]);
    insertionSort(array, n);
    printf("No. of comparisons performed: %d\n",compare_count);
    printf("No. of swaps performed: %d\n",swap_count);
    for(int i=0; i<n; i++){
        printf("%d ", array[i]);
    }printf("\n");
}