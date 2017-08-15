/**
 * @author zybang
 * @time 2017/8/15 15:03
 * @desc 二叉树相关
 * 例如：
 * int nodeArr[10] = {10, 2, 3, 4, 5, 6, 7, 8, 9, 10};
 * Node *root = buildTree(nodeArr, 10);
 * destroyTree(root);
 **/
#include <deque>
using namespace std;
#ifndef C_BINARYTREE_H
#define C_BINARYTREE_H

#endif //C_BINARYTREE_H

#ifndef nullptr
#define nullptr NULL
#endif

/**
 * 二叉树节点
 */
typedef struct Node{
    int val;
    Node *left;
    Node *right;
    Node(int value){
        val = value;
        left = NULL;
        right = NULL;
    }
};

/**
 * 根据数组创建完全二叉树
 * @param arr
 * @param size
 * @return
 */
Node* buildTree(int *arr, int size){
    Node *tmp[size];
    for(int i=0; i<size; i++){
        tmp[i] = new Node(arr[i]);
    }
    for(int i=0; i<size; i++){
        if(2*i+1 < size) tmp[i]->left = tmp[2*i+1];
        if(2*i+2 < size) tmp[i]->right = tmp[2*i+2];
    }
    return tmp[0];
}

/**
 * 销毁二叉树
 * @param root
 */
void destroyTree(Node *root){
    if(NULL == root){
        return ;
    }
    if(root->left != NULL){
        destroyTree(root->left);
    }
    if(root->right != NULL){
        destroyTree(root->right);
    }
    delete(root);
}

/**
 * 打印每一层的最大值
 * @param root
 */
void printLevelMax(Node *root){
    deque<Node *> q;
    Node *p = root;
    q.push_back(p);
    int last=1, cur=0;
    int max = 0x80000000;
    int level=0;
    while(!q.empty()){
        p = q.front();
        last --;
        q.pop_front();
        if(p->left != NULL){
            q.push_back(p->left);
            cur ++;
        }
        if(p->right != NULL){
            q.push_back(p->right);
            cur ++;
        }
        if(last == 0){
            last = cur;
            cur = 0;
            max = p->val > max? p->val: max;
            level ++;
            printf("level: %d, max: %d\n", level, max);
            max = 0x80000000;
        }
    }
}

/**
 * 按层打印二叉树
 * @param root
 */
void printLevelVal(Node *root){
    deque<Node *> q;
    Node *p = root;
    q.push_back(p);
    int last=1, cur=0;
    int level=0;
    printf("level %d: ", level+1);
    while(!q.empty()){
        p = q.front();
        printf("%d ", p->val);
        last --;
        q.pop_front();
        if(p->left != NULL){
            q.push_back(p->left);
            cur ++;
        }
        if(p->right != NULL){
            q.push_back(p->right);
            cur ++;
        }
        if(last == 0){
            last = cur;
            cur = 0;
            level ++;
            printf("\n");
            if(last > 0){
                printf("level %d: ", level+1);
            }
        }
    }
}
