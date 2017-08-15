#include <stdio.h>
#include <string>
#include "binaryTree.h"
#include "dp/matrix1.h"
using namespace std;
#ifndef nullptr
#define nullptr NULL
#endif


int main() {
//    int nodeArr[10] = {10, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//    Node *root = buildTree(nodeArr, 10);
//    printLevelMax(root);
//    printLevelVal(root);
//    destroyTree(root);
    int m[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
    int *matrix[3];
    matrix[0] = m[0];
    matrix[1] = m[1];
    matrix[2] = m[2];
    int max = maxSum(matrix, 3, 3);
    printf("max: %d", max);
    return 0;
}