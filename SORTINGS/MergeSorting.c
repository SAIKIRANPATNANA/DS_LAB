#include <stdio.h>
int compare_count = 0;
int swap_count = 0;
void merge(int *array, int l, int mid, int h){
    int array_a[mid-l+1];
    int array_b[h-mid];
    int i = 0;
    int k = l;
    int j = 0;
    int t = 0;
    for(int i=l; i<=mid; i++){
        array_a[t] = array[i];
        t++;
    }t = 0;
    for(int i=mid+1; i<=h; i++){
        array_b[t] = array[i];
        t++;
    }while(i<mid-l+1 && j<h-mid){
        if(array_a[i]<=array_b[j]){
            compare_count++;
            array[k] = array_a[i];
            i++;
        }else if(array_a[i]>array_b[j]){
            compare_count++;
            array[k] = array_b[j];
            j++;
        }k++;
    }while(i<mid-l+1){
        array[k] = array_a[i];
        i++;
        k++;
    }while(j<h-mid){
        array[k] = array_b[j];
        j++;
        k++;
    }return;
}void mergeSort(int* array, int l, int h){
    if(l<h){
        int mid = (l+h)/2;
        mergeSort(array,l, mid);
        mergeSort(array,mid+1,h);
        merge(array,l,mid,h);
    }return;
}int main(){
    int array[] = {10,9,8,7,6,5,4,3,2,1};
    int n = sizeof(array)/sizeof(array[0]);
    mergeSort(array,0,n-1);
    printf("No. of comparisons performed: %d\n",compare_count);
    printf("No. of swaps performed: %d\n",swap_count);
    for(int i=0; i<n; i++){
        printf("%d ", array[i]);
    }printf("\n");
    return 0;
}