#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 26
struct pair{
    char* key;
    char* value;
    struct pair* next;
}typedef pair;
struct hashMap{
    pair* map[size];
}typedef hashMap;
pair* createPair(char* key, char* value){
    pair* newPair = (pair*)malloc(sizeof(pair));
    newPair->key = key;
    newPair->value = value;
    newPair->next = NULL;
    return newPair;
}hashMap* createHashMap(){
    hashMap* hm = (hashMap*)malloc(sizeof(hashMap));
    for(int i=0; i<size; i++){
        hm->map[i] = NULL;
    }return hm;
}int hashValue(char* key){
    char* dupKey = strdup(key);
    int i=0, hash = 0;
    while(dupKey[i]!='\0'){
        hash += dupKey[i];
        i++;
    }hash %= size;
    return hash;
}void addPair(hashMap* hm, char* key, char* value){
    int hash = hashValue(key); 
    pair* newPair = createPair(key,value);
    if(hm->map[hash]){
        pair* tempPair = hm->map[hash];
        while(tempPair->next){
            tempPair = tempPair->next;
        }tempPair->next = newPair;
    }else{
        hm->map[hash] = newPair;
    }return;
}void searchPair(hashMap* hm, char* key){
    int hash = hashValue(key);
    pair* tempPair = hm->map[hash];
    int flag = 1;
    while(tempPair){
        if(strcmp(tempPair->key,key)==0){
            printf("%s\n", tempPair->value);
            flag = 0;
            break;
        }tempPair = tempPair->next;
    }if(flag){
        printf("not found\n");
    }return;
}void deletePair(hashMap* hm, char* key){
    int hash = hashValue(key);
    pair* tempPair = hm->map[hash];
    int flag = 1;
    if(strcmp(tempPair->key, key) == 0){
        hm->map[hash] = tempPair->next;
        free(tempPair);
        return;
    }while(tempPair->next){
        if(strcmp(tempPair->next->key,key)==0){
            pair* dupPair = tempPair->next;
            if(tempPair->next->next){
                tempPair->next = tempPair->next->next;
            }else{
                tempPair->next = NULL;
            }free(dupPair);
            break;
        }tempPair = tempPair->next;
    }return;
}void displayHashMap(hashMap * hm){
    for(int i=0; i<size; i++){
        pair* tempPair = hm->map[i];
        while(tempPair){
            printf("%s->%s\n",tempPair->key,tempPair->value);
            tempPair = tempPair->next;
        }
    }return;
}int main(){
    hashMap* hm = createHashMap();
    addPair(hm,"apple","fruit");
    addPair(hm,"banana","fruit");
    addPair(hm,"carrot","vegetable");
    displayHashMap(hm);
    searchPair(hm,"banana");
    deletePair(hm,"banana");
    searchPair(hm,"banana");
    displayHashMap(hm);
    return 0;
}