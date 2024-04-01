#include <stdio.h>
int main() {
    int array[] = {1,0,2,1,0,1,1,5,6,7,5,4,2,2,0,0,1};
    int n = sizeof(array)/sizeof(array[0]);
    int max = -1;
    for(int i=0; i<n; i++){
        max = max<array[i]?array[i]:max;
    }int countArray[max+1];
    for(int i=0; i<=max; i++){
        countArray[i] = 0;
    }for(int i=0; i<n; i++){
        countArray[array[i]]++;
    }for(int i=1; i<=max; i++){
        countArray[i] += countArray[i-1];
    }int answer[n];
    for(int i=n-1; i>=0; i--){
        countArray[array[i]]--;
        answer[countArray[array[i]]] = array[i];
    }for(int i=0; i<n; i++){
        printf("%d ",answer[i]);
    }printf("\n");
    return 0;
}