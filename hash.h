//
// Created by zybang on 2017/8/15.
//

#ifndef C_HASH_H
#define C_HASH_H

#endif //C_HASH_H
typedef struct _node{
    string key;
    string val;
    _node *next;
    void node(){
        key = "";
        val = "";
        next = nullptr;
    }
} node;

typedef struct _ht{
    _node *node[100];
    int count;
    int used;
    void ht(){
        count = 100;
        used = 0;
    }
} hashTable;

int hash(hashTable *ht, string key){
    int size = key.size();
    int code=0;
    for(int i=0; i<size; i++){
        code += key[i];
    }
    int hash = code % ht->count;
    return hash;
}

string get(hashTable *ht, const string key){
    int hash = hash(ht, key);
    node *p = ht->node[hash];
    while(p->next != nullptr){
        if(key == p->key){
            return p->val;
        }
    }
    return nullptr;
}

int set(hashTable *ht, string key, string val){
    int hash = hash(ht, key);
    node *p = ht->node[hash];
    while(p->next != nullptr){
        if(key == p->key){
            p->val = val;
        }
    }

    return 1;
}

