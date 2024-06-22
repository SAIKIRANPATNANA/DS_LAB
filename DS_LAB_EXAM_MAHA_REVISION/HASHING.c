#include <stdio.h>
#include <stdlib.h>
#define maxi 25
struct key_val{
    const char* key;
    const char* val;
    struct key_val* next;
}typedef key_val;
int calcHashValue(const char* key){
    int value = 0;
    int n = sizeof(key)/sizeof(key[0]);
    for(int i=0; i<n; i++){
        value += (int)key[i];
    }return value%maxi;
}key_val* dict[maxi];
void insertKeyVal(const char* key, const char* val){
    int hash = calcHashValue(key);
    key_val* newKeyVal = (key_val*)malloc(sizeof(struct key_val));
    newKeyVal->key = key;
    newKeyVal->val = val;
    newKeyVal->next = NULL;
    if(dict[hash]){
        key_val* tempKeyVal = dict[hash];
        while(tempKeyVal->next){
            tempKeyVal = tempKeyVal->next;
        }tempKeyVal->next = newKeyVal;
    }else{
        dict[hash] = newKeyVal;
    }return;
}void display(){
    for(int i=0; i<maxi; i++){
        key_val* tempKeyVal = dict[i];
        while(tempKeyVal){
            printf("%s -> %s\n", tempKeyVal->key, tempKeyVal->val);
            tempKeyVal = tempKeyVal->next;
        }
    }return;
}void deleteKeyVal(const char *key,const char *val){
    int hash = calcHashValue(key);
    key_val* tempKeyVal = dict[hash];
    int flag = 1;
    if(tempKeyVal->key == key && tempKeyVal->val == val){
        dict[hash] = tempKeyVal->next;
        free(tempKeyVal);
        flag = 0;
        return;
    }else{
        while(tempKeyVal->next){
            if(tempKeyVal->next->key == key && tempKeyVal->next->val == val){
                key_val* dup = tempKeyVal->next;
                tempKeyVal->next = tempKeyVal->next->next;
                flag = 0;
                free(dup);
                return;
            }tempKeyVal = tempKeyVal->next;
        }
    }if(flag){
        printf("Not Found!\n");
    }return;
}void searchKeyVal(const char* key, const char* val){
    int flag = 1;
    for(int i=0; i<maxi; i++){
        key_val* tempKeyVal = dict[i];
        while(tempKeyVal){
            if(tempKeyVal->key == key && tempKeyVal->val == val){
                flag = 0;
                printf("Found!\n");
                return;
            }tempKeyVal = tempKeyVal->next;
        }
    }if(flag){
        printf("Not found!\n");
    }return;
}int main(){
    insertKeyVal("apple","fruit");
    insertKeyVal("pineapple","fruit");
    insertKeyVal("bapaya","fruit");
    insertKeyVal("potato","vegetable");
    insertKeyVal("apple","fruits");
    display();
    deleteKeyVal("apple","fruits");
    display();
    deleteKeyVal("apple","fruits");
    display();
    searchKeyVal("apple","fruit");
    searchKeyVal("apple","fruits");
    return 0;
}