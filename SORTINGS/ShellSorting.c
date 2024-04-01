#include <stdio.h>
int main(){
    int array[] = {23,29,15,19,31,7,9,5,2};
    int n = sizeof(array)/sizeof(array[0]);
    int gap = n/2;
    while(gap){
        int i=0; 
        while(1){
            if(i+gap>=n){
                break;
            }else if(array[i]>array[i+gap]){
                array[i] = array[i]^array[i+gap];
                array[i+gap] = array[i]^array[i+gap];
                array[i] = array[i]^array[i+gap];
                if(i-gap>=0 && array[i-gap]>array[i]){
                    array[i-gap] = array[i-gap]^array[i];
                    array[i] = array[i-gap]^array[i];
                    array[i-gap] = array[i-gap]^array[i];
                }
            }i++;
        }gap /= 2;
    }for(int i=0; i<n; i++){
        printf("%d ", array[i]);
    }printf("\n");
    return 0;
}