#include <stdio.h>
void swap(int* arr, int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    return;
}int getPivot(int* arr, int low, int high){
    int i = low, j = high, pi = low;
    while(i<j){
        while(arr[i]<=arr[pi]){
            i++;
        }while(arr[j]>arr[pi]){//keep in mind
            j--;
        }if(i<j){
            swap(arr,i,j);
        }
    }swap(arr,j,pi);
    return j;
}void quickSort(int *arr, int low, int high){
    if(low<high){
        int pi = getPivot(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }return;
}void selectionSort(int *arr, int n){
    for(int i=0; i<n-1; i++){
        int min_idx = i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[min_idx]){
                min_idx = j;
            }
        }if(min_idx!=i){
            swap(arr,i,min_idx);
        }
    }return;
}void insertionSort(int* arr, int n){
    for(int i=1; i<n; i++){
        int j = i-1;
        int trend = arr[i];
        while(j>=0 && arr[j]>=trend){
            arr[j+1] = arr[j];
            j--;
        }arr[j+1] = trend;
    }return;
}void merge(int *arr, int l, int m, int h){
    int k=l,t=0,a=m-l+1,b=h-m,i=0,j=0;
    int arr1[a];
    int arr2[b];
    for(i=l,t=0; i<=m; i++,t++){
        arr1[t] = arr[i];
    }for(i=m+1,t=0; i<=h; i++,t++){
        arr2[t] = arr[i];
    }i=0;//keep in mind
    while(i<a && j<b){
        if(arr1[i]<=arr2[j]){
            arr[k] = arr1[i];
            i++; k++;
        }else{
            arr[k] = arr2[j];
            j++; k++;
        }
    }while(i<a){
        arr[k] = arr1[i];
        i++; k++;
    }while(j<b){
        arr[k] = arr2[j];
        j++; k++;
    }return;
}void mergeSort(int* arr, int l, int h){
    if(l<h){
        int m = (l+h)/2;
        mergeSort(arr,l,m);
        mergeSort(arr, m+1,h);
        merge(arr,l,m,h);
    }return;
}int main(){
    int arr[] = {5,4,3,2,1};
    quickSort(arr,0,4);
    // selectionSort(arr,5);
    // insertionSort(arr,5);
    // mergeSort(arr,0,4);
    for(int i=0;i<5;i++){
        printf("%d ",arr[i]);
    }return 0;
}

