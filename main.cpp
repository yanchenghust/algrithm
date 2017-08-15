#include <stdio.h>
#include <string>
#include "hash.h"
using namespace std;
#ifndef nullptr
#define nullptr NULL
#endif


int main() {
    hashTable *ht = new hashTable();
    string key,val;
    key = "key1";
    val = get(ht, key);
    printf("%s: %s \n", key, val);
    return 0;
}