#include <stdio.h>
#include <string>
#include "dp/take_coin.h"
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
    int m[4] = {1, 3, 5, 2};
    printf("len: %d", taskCoin1(m, 4));
    return 0;
}