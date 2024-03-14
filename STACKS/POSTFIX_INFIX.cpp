#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector <string> st(100);
int top = -1;
void Push(string str){
    top++;
    st[top] = str;
    return;
}void Pop(){
    st[top] = "nil";
    top--;
    return;
}string Top(){
    return st[top];
}string getResult(string exp){
    for(int i=0; i<exp.length(); i++){
        if(isalpha(exp[i])){
            string mt = "";
            mt += exp[i];
            Push(mt);
        }else{
            string str = Top();
            Pop();
            str = '('+ Top() + exp[i] + str + ')';
            Pop();
            Push(str);
        }
    }return Top();
}int main(){
    string exp;
    cin>>exp;
    cout<<getResult(exp)<<endl;
    return 0;
}