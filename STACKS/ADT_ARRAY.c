#include <stdio.h>
int st[100];
int last = -1;
void Push(int x) {
    last++;
    st[last] = x;
    return;
}void Pop(){
    if(last==-1){
        printf("empty stack!\n");
        return;
    }st[last] = -1;
    last--;
    return;
}int Top(){
    if(last==-1){
        printf("empty stack!\n");
        return;
    }return st[last];
}void display(){
    if(st[last]==-1){
        printf("empty stack!\n");
    }for(int i=last; i>=0; i--){
        printf("%d ",st[i]);
    }printf("\n");
    return;
}int main() {
    // enter your stuff here..!
    return 0;
}
