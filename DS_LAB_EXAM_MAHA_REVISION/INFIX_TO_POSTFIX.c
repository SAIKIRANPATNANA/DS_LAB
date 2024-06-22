#include <stdio.h>
#include <stdlib.h>
#define maxi 100
char st[maxi];
int top = -1;
void push(char ch){
    st[++top] = ch;
    return;
}char pop(){
    char ch =  st[top--];
    return ch;
}char peek(){
    return st[top];
}void display(){
    for(int i=0; i<=top; i++){
        printf("%c ",st[i]);
    }printf("\n");
    return;
}int gp(char ch){
    switch(ch){
        case '+':
            return 1;
        case '-':
            return 1;
        case '%': 
            return 2;
        case '*':
            return 2;
        case '/':
            return 2;
        case '^':
            return 3;
    }return 0;
}char* infixToPostfix(const char* exp, int n){
    printf("%d\n", n);
    char* ans = (char*)malloc(sizeof(char)*(n+1));
    int t = 0;
    for(int i=0; i<n; i++){
        if(exp[i]=='('){
            push(exp[i]);
        }else if(exp[i]==')'){
            while(peek()!='('){
                ans[t++] = pop();
            }pop();
        }else if((int)exp[i]>=97 && (int)exp[i]<=122 || (int)exp[i]>=65 && (int)exp[i]<=90 || (int)exp[i]>=48 && (int)exp[i]<=57){
            ans[t++] = exp[i];
        }else if(peek()!='(' && gp(peek())<gp(exp[i])){
            st[++top] = exp[i];
        }else if(top==-1 || peek()=='(' || gp(peek()) >= gp(exp[i])){
            while(top!=-1 && peek()!='(' && gp(peek())>=gp(exp[i])){
            if(peek()=='^' && exp[i]=='^'){
                push(exp[i]);
                break;
            }else{
                ans[t++] = pop();
            }
            }push(exp[i]);
        }
    }while(top!=-1){
        ans[t++] = pop();
    }ans[t++] = '\0';
    return ans;
}int main(){
    char exp[maxi];
    scanf("%s",exp);
    int n = 0;
    while(exp[n]!='\0'){
        n++;
    }printf("%s\n",infixToPostfix(exp,n));
    return 0;
}