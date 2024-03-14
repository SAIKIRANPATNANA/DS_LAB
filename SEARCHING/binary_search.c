#include <stdio.h>
int main(){
    int array[] = {25,30,50,60};
    int n = sizeof(array)/sizeof(array[0]);
    int check[n];
    for(int i=0; i<n; i++){
        check[i] = 1;
    }for(int i=0; i<n; i++){
        if(check[i]){
            int low = 0;
            int high = n-1;
            int c = 0;
            while(low<=high){
                int mid = (low+high)/2;
                if(array[mid]==array[i]){
                    int j = mid-1;
                    c = 1;
                    while(j>=0 && array[j]==array[i]){
                        c++;
                        check[j] = 0;
                        j--;
                    }j = mid+1;
                    while(j<=n-1  && array[j]==array[i]){
                        c++;
                        check[j] = 0;
                        j++;
                    }if (check[i]){
                        printf("%d %d\n", array[i], c);
                    }
                    break;
                }else if(array[mid]>array[i]){
                    high = mid-1;
                }else {
                    low = mid+1;
                }
            }
        }
    }return 0;
}