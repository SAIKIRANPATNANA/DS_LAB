#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector <int> st(100);
int top = -1;
void Push(int val){
    top++;
    st[top] = val;
    return;
}void Pop(){
    st[top] = -1;
    top--;
    return;
}int Top(){
    return st[top];
}int performOperation(char op, int a, int b){
    switch(op){
        case '+':
            return a+b;
        case '-' :
            return a-b;
        case '/':
            return a/b;
        case '*':
            return a*b;
        case '^':
            return pow(a,b);
    }return 0;
}int getResult(string exp){
    for(int i=0; i<exp.length(); i++){
        if(isdigit(exp[i])){
            string c = "";
            c += exp[i];
            Push(stoi(c));
        }else{
            int b = Top();
            Pop();
            int a = Top();
            Pop();
            Push(performOperation(exp[i],a,b));
        }
    }return Top();
}int main(){
    string exp;
    cin>>exp;
    cout<<getResult(exp)<<endl;
    return 0;
}