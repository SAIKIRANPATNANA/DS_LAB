#include <stdio.h>
int compare_count = 0;
int swap_count = 0;
void bubbleSort(int* array, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(array[j]>array[j+1]){
                array[j] = array[j]^array[j+1];
                array[j+1] = array[j]^array[j+1];
                array[j] = array[j]^array[j+1];
                swap_count++;
            }compare_count++;
        }
    }return;
}int main(){
    int array[] = {10,9,8,7,6,5,4,3,2,1};
    int n = sizeof(array)/sizeof(array[0]);
    bubbleSort(array, n);
    printf("No. of comparisons performed: %d\n",compare_count);
    printf("No. of swaps performed: %d\n",swap_count);
    for(int i=0; i<n; i++){
        printf("%d ", array[i]);
    }printf("\n");
}