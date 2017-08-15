#include <stdio.h>
#include <string>
#include "binaryTree.h"
using namespace std;
#ifndef nullptr
#define nullptr NULL
#endif


int main() {
    int nodeArr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Node *root = buildTree(nodeArr, 10);
//    printLevelMax(root);
    printLevelVal(root);
    destroyTree(root);
    return 0;
}