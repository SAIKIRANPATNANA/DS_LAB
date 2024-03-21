#include <stdio.h>
int compare_count = 0;
int swap_count = 0;
void selectionSort(int* array, int n){
    for(int i=0; i<n; i++){
        int min_idx = i;
        for(int j=i+1; j<n; j++){
            if(array[min_idx]>array[j]){
                compare_count++;
                min_idx = array[j];
            }
        }if(min_idx!=i){
            swap_count++;
            array[i] = array[i]^array[min_idx];
            array[min_idx] = array[i]^array[min_idx];
            array[i] = array[i]^array[min_idx];
        }
    }return;
}int main(){
    int array[] = {10,9,8,7,6,5,4,3,2,1};
    int n = sizeof(array)/sizeof(array[0]);
    selectionSort(array, n);
    printf("No. of comparisons performed: %d\n",compare_count);
    printf("No. of swaps performed: %d\n",swap_count);
    for(int i=0; i<n; i++){
        printf("%d ", array[i]);
    }printf("\n");
}