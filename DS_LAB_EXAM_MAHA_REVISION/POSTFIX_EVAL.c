#include<stdio.h>
#include<stdlib.h>
#define maxi 100
int st[maxi];
int top = -1;
void push(int val){
    st[++top] = val;
    return;
}int pop(){
    return st[top--];
}int op(int a, int b, char o){
    switch(o){
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '%':
            return a%b;
        case '/':
            return a/b;
        case '*':
            return a*b;
    }return 0;
}int eval(const char* exp, int n){
    for(int i=0; i<n; i++){
        if((int)exp[i]>=48 && (int)exp[i]<=57){
            push((int)exp[i]-'0');
        }else{
            int b = pop();
            int a = pop();
            push(op(a,b,exp[i]));
        }
    }return pop();
}int main(){
    char exp[maxi];
    scanf("%s", exp);
    int n = 0;
    while(exp[n]!='\0'){
        n++;
    }printf("%d\n",eval(exp,n));
    return 0;
}