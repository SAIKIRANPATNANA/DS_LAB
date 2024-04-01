#include <stdio.h>
#include <math.h>
void countSort(int* array, int n, int d){
    int countArray[10];
    int decimal = pow(10,d);
    for(int i=0; i<10; i++){
        countArray[i] = 0;
    }for(int i=0; i<n; i++){
        countArray[(array[i]/decimal)%10]++;
    }for(int i=1; i<10; i++){
        countArray[i] += countArray[i-1];
    }int answer[n];
    for(int i=n-1; i>=0; i--){
        countArray[(array[i]/decimal)%10]--;
        answer[countArray[(array[i]/decimal)%10]] = array[i];
    }for(int i=0; i<n; i++){
        array[i] = answer[i];
    }return;
}int main(){
    int array[] = {15,1,321,10,802,2,123,90,109,11};
    int n = sizeof(array)/sizeof(array[0]);
    int max = -1;
    for(int i=0; i<n; i++){
        max = max<array[i]? array[i]:max;
    }int d = 0;
    int temp = max;
    while(temp){
        d++;
        temp /= 10;
    }for(int i=0; i<d; i++){
        countSort(array,n,i);
    }for(int i=0; i<n; i++){
        printf("%d ",array[i]);
    }printf("\n");
    return 0;
}