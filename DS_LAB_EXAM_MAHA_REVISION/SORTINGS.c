#include <stdio.h>
void swap(int *arr, int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
    return;
}void insertionSort(int* arr, int n){
    for(int i=0; i<n; i++){
        int j = i-1;
        int trend = arr[i];
        while(j>=0 && arr[j]>trend){
            arr[j+1] = arr[j]; j--;
        }arr[j+1] = trend;
    }return;
}void merge(int *arr, int l, int m, int h){
    int a = m-l+1, b = h-m, t = 0;
    int arr1[a]; int arr2[b];
    for(int i=l; i<=m; i++){
        arr1[t++] = arr[i];
    }t = 0;
    for(int i=m+1; i<=h; i++){
        arr2[t++] = arr[i];
    }t = l;
    int i = 0, j = 0;
    while(i<a && j<b){
        if(arr1[i]<=arr2[j]){
            arr[t++] = arr1[i++];
        }else{
            arr[t++] = arr2[j++];
        }
    }while(i<a){
        arr[t++] = arr1[i++];
    }while(j<b){
        arr[t++] = arr2[j++];
    }return;
}void mergeSort(int* arr, int l, int h){
    if(l<h){
        int m = (l+h)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,h);
        merge(arr,l,m,h);
    }return;
}void selectionSort(int* arr, int n){
    for(int i=0; i<n; i++){
        int min_idx = i;
        for(int j=i+1; j<n; j++){
            if(arr[min_idx]>arr[j]){
                min_idx = j;
            }
        }if(min_idx!=i){
            swap(arr, i, min_idx);
        }
    }return;
}int getPi(int* arr, int l, int h){
    int i = l, j = h, pi = l;
    while(i<j){
        while(arr[i]<=arr[pi]){
            i++;
        }while(arr[j]>arr[pi]){
            j--;
        }if(i<j){
            swap(arr,i,j);
        }
    }swap(arr,pi,j);
    return j;
}void quickSort(int* arr, int l, int h){
    if(l<h){
        int pi = getPi(arr, l, h);
        quickSort(arr,l,pi-1);
        quickSort(arr,pi+1, h);
    }return;
}int main(){
    int arr[] = {7,6,5,4,3,2,1};
    // insertionSort(arr,7);
    // selectionSort(arr,7);
    // mergeSort(arr,0,6);
    // quickSort(arr,0,6);
    for(int i=0; i<7; i++){
        printf("%d ", arr[i]);
    }printf("\n");
    return 0;
};
