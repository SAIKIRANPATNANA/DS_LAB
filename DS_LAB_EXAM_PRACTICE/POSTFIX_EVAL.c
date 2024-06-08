#include <stdio.h>
#include <string.h>
#define maxi 100
int st[maxi];
int last = -1;
void push(int i){
    st[++last] = i;
    return;
}int pop(){
    int top = st[last];
    st[last--] = -1;
    return top;
}int op(char s, int a, int b){
    switch(s){
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        case '^':
            return a ^ b;
    }return 0;
}int main(){
    char exp[] = "12+3*45/-";
    int i = 0;
    while(exp[i] != '\0'){
        if((int)exp[i]>=48 && (int)exp[i]<=57){
            push(exp[i]-'0');
        }else{
            int b = pop(), a = pop();
            push(op(exp[i],a,b));
        }i++;
    }printf("%d\n",pop());
    return 0;
}