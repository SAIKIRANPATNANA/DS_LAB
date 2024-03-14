#include <stdio.h>
#include <stdlib.h>
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
        return -1;
    }return st[last];
}void display(){
    if(st[last]==-1){
        printf("empty stack!\n");
    }for(int i=last; i>=0; i--){
        printf("%d ",st[i]);
    }printf("\n");
    return;
}int getPrecedence(int idx){
    switch (idx){
        case -1:
            return -1;
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 3;
        case 5:
            return 3;
        case 6:
            return 4;
    }return 5;
}int getIndex(char ch){
    switch (ch){
        case '(':
            return 0;
        case ')':
            return 1;
        case '+':
            return 2;
        case '-':
            return 3;
        case '*':
            return 4;
        case '/':
            return 5;
        case '^':
            return 6;
    }return 7;
}char getChar(int idx){
     switch (idx){
        case 0:
            return '(';
        case 1:
            return ')';
        case 2:
            return '+';
        case 3:
            return '-';
        case 4:
            return '*';
        case 5:
            return '/';
        case 6:
            return '^';
    }return '.';
}char* reverse(char* exp){
    int n = 0;
    while(exp[n]!='\0'){
        n++;
    }char* rev_exp = (char*)malloc(sizeof(char)*n);
    for(int i= 0; i<n; i++){
        if(exp[n-i-1]==')'){
            rev_exp[i] = '(';
        }else if(exp[n-i-1]=='('){
            rev_exp[i] = ')';
        }else{
            rev_exp[i] = exp[n-i-1];
        }
    }return rev_exp;
}char* getResult(char* exp){
    int n = 0;
    int j,top;
    while(exp[n] != '\0'){
        n++;
    }char* result = (char*)malloc((n+1)* sizeof(char));
    j = 0;
    for(int i=0; i<n; i++){
        int idx = getIndex(exp[i]);
        top = Top();
        if(idx==7){
            result[j] = exp[i];
            j++;
        }else if(getPrecedence(top)<getPrecedence(idx) || idx==0){
            Push(idx);
        }else{
            if(idx==1){
                while(top!=0){
                    result[j] = getChar(top);
                    j++;
                    Pop();
                    top = Top();
                }Pop();
            }else{
                while(getPrecedence(top)>=getPrecedence(idx)){
                        result[j] = getChar(top);
                        j++;
                        Pop();
                        top = Top();
                        if(top==idx && idx==6){
                            break;
                        }
                }Push(idx);
            }
        }
    }top = Top();
    while(top!=-1){
        result[j] = getChar(top);
        j++;
        Pop();
        top = Top();
    }result[j] = '\0';
    return result;
}int main() {
    char exp[100];
    scanf("%s",exp);
    printf("%s \n",reverse(getResult(reverse(exp))));
    return 0;
}