//
// Created by zybang on 2017/8/15.
//
#ifndef C_HASH_H
#define C_HASH_H

#endif //C_HASH_H
typedef struct bucket{
    char* key;
    char* val;
    bucket *next;
    bucket(char *k, char *v){
        key = k;
        val = v;
        next = nullptr;
    }
};

typedef struct hashTable{
    bucket *node[100];
    int count;
    int used;
    hashTable(){
        count = 100;
        used = 0;
        for(int i=0; i<100; i++){
            node[i] = nullptr;
        }
    }
};

int hashCode(hashTable *ht, string key){
    int size = key.size();
    int code=0;
    for(int i=0; i<size; i++){
        code += key[i];
    }
    int hash = code % ht->count;
    return hash;
}

char* get(hashTable *ht, string key){
    int hash = hashCode(ht, key);
    bucket *p = ht->node[hash];
    if(nullptr != p){
        while(p->next != nullptr){
            if(key == p->key){
                return p->val;
            }
        }
    }
    return "";
}

bool set(hashTable *ht, string key, string val){
    int hash = hashCode(ht, key);
    bucket *p = ht->node[hash];
    if(p != nullptr){
        while(p->next != nullptr){
            if(key == p->key){
                p->val = val;
            }
        }
        bucket *tmp = new bucket(key, val);
        p->next = tmp;
    }else{
        bucket *tmp = new bucket(key, val);
        ht->node[hash] = tmp;
    }
    return true;
}

