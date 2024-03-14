#include <stdio.h>
int main(){
    int array[] = {5,4,3,2,1};
    int n = sizeof(array)/sizeof(array[0]);
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(array[j]>array[j+1]){
                array[j] = array[j+1]^array[j];
                array[j+1] = array[j]^array[j+1];
                array[j] = array[j+1]^array[j];
            }
        }
    }for(int i=0; i<n; i++){
        printf("%d ",array[i]);
    }print("\n");
    return 0;
}