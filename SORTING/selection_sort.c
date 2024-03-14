#include <stdio.h>
int main(){
    int array[] = {5,4,3,2,1};
    int n = sizeof(array)/sizeof(array[0]);
    for(int i=0; i<n; i++){
        int min_idx = i;
        for(int j=i+1; j<n; j++){
            if(array[min_idx] > array[j]){
                min_idx = j;
            }
        }if(min_idx!=i){
            array[i] = array[i]^array[min_idx];
            array[min_idx] = array[min_idx]^array[i];
            array[i] = array[i]^array[min_idx];
        }
    }for(int i=0; i<n; i++){
        printf("%d ",array[i]);
    }printf("\n");
    return 0;
}