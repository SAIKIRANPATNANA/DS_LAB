#include <stdio.h>
#include <stdlib.h>
#define maxi 100
void swap(int* mh, int a, int b){
    int temp = mh[a];
    mh[a] = mh[b];
    mh[b] = temp;
    return;
}void insert(int* mh, int val, int n){
    n++;
    int t = n;
    mh[t] = val;
    while(t/2>0 && mh[t]>mh[t/2]){
        swap(mh,t,t/2);
        t /= 2;
    }return;
}void remove(int* mh, int n){
    mh[1] = mh[n];
    mh[n] = -1;
    n--;
    int t = n;
    while(t*2<=n || t*2+1<=n){
        if(t*2<=n && t*2+1 <=n && mh[t*2]<mh[t*2+1] && mh[t*2]<mh[t]){
            swap(mh,t,t*2);
            t *= 2;
        }else if(t*2<=n && t*2+1 <=n && mh[t*2]>mh[t*2+1] && mh[t*2+1] < mh[t]){
            swap(mh,t,t*2+1);
            t = t*2+1;
        }else if(t*2<=n && mh[t*2]<mh[t]){
            swap(mh,t,t*2);
            t *= 2;
        }
    }return;
}void heapify(int* mh, int n){
    int t = n/2;
    while(t>0){
        if(t*2<=n && t*2+1<=n && mh[t*2]>mh[t*2+1] && mh[t*2]>mh[t]){
            swap(mh,t,t*2);
            t *= 2;
        }else if(t*2<=n && t*2+1<=n && mh[t*2]<mh[t*2+1] && mh[t*2+1]>mh[t]){
            swap(mh,t,t*2+1);
        }else if(t*2<=n && mh[t*2]>mh[t]){
            swap(mh,t,t*2);
        }t--;
    }t = 2;
    while(t*2 <= n || t*2+1 <= n){
        if(t*2<=n && t*2+1<=n && mh[t*2]<mh[t*2+1] && mh[t*2]<mh[t]){
            swap(mh,t,t*2);
        }else if(t*2<=n && t*2+1<=n && mh[t*2]>mh[t*2+1] && mh[t*2+1] < mh[t]){
            swap(mh,t,t*2+1);
        }else if(t*2<=n && mh[t*2]<mh[t]){
            swap(mh,t,t*2);
        }t++;
    }return;
}void heapSort(int* mh, int n){
    int t = n;
    while(t>0){
        heapify(mh,t);
        swap(mh, 1, t);
        t--;
    }return;
}int main(){
    int mh[] = {-1,12,11,13,5,6,7};
    heapSort(mh,6);
    for(int i=1; i<=6; i++){
        printf("%d ",mh[i]);
    }printf("\n");
    return 0;
}