#include <stdio.h>
int swap_count = 0;
int compare_count = 0;
int getPivot(int* array, int l, int h){
    int p = l;
    int i = l;
    int j = h;
    while(i<j){
         while(array[i]<=array[p]){
            compare_count++;


            i++;
        }while(array[j]>array[p]){
            compare_count++;
            j--;
        }if(i<j){
            int temp = array[i];
            array[j] = array[j];
            array[j] = temp;
            swap_count++;
        }
    }int temp = array[p];
    array[p] = array[j];
    array[j] = temp;
    swap_count++;
    return j;
}void quickSort(int* array, int l, int h){
    if(l<h){
        int p = getPivot(array, l, h);
        quickSort(array, l, p-1);
        quickSort(array, p+1, h);
    }return;
}int main(){ 
    int array[] = {10,9,8,7,6,5,4,3,2,1};
    int n = sizeof(array)/sizeof(array[0]);
    quickSort(array,0,n-1);
    printf("No. of comparisons performed: %d\n",compare_count);
    printf("No. of swaps performed: %d\n",swap_count);
    for(int i=0; i<n; i++){
        printf("%d ", array[i]);
    }printf("\n");
    return 0;
}