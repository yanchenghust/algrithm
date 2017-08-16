#include <stdio.h>
#include <string>
#include "dp/lcs.h"
using namespace std;
#ifndef nullptr
#define nullptr NULL
#endif


int main() {
//    hashTable *ht = new hashTable();
//    string key,val;
//    key = "key1";
//    val = get(ht, key);
//    printf("%s: %s \n", key, val);
    char str1[]="123456789";
    char str2[]="173450689";
    int len = lcs(str1, str2);
    printf("len: %d", len);
    return 0;
}