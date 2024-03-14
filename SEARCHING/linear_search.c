#include <stdio.h>
int main(){
    int array[] = {1,2,2,4,5};
    int n = sizeof(array)/sizeof(array[0]);
    int target = 5;
    int flag = 1;
    for(int i=0; i<n; i++){
        if(array[i] == target){
            printf("%d\n", i);
            flag = 0;
        }
    }if(flag){
        printf("%d\n", -1);
    }int check[n];
    for(int i = 0; i < n; i++){
        check[i] = 1;
    }for(int i=0; i<n; i++){
        int c = 0;
        if(check[i]){
            for(int j=0; j<n; j++){
                if(array[i]==array[j]){
                    c++;
                    check[j] = 0;
                }
             }printf("%d %d\n", array[i],c);
        }
    }return 0;
}