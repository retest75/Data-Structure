#include <stdlib.h>
#include "BST.h"

/** example of binary search tree 
 *       20
 *     /    \
 *   15      25
 *  /  \    /
 * 12  10  22
*/
treePointer exampleBST(){
    element data1 = {20, 'a'}, data2 = {15, 'b'}, data3 = {25, 'c'}, data4 = {12, 'd'};
    element data5 = {17, 'e'}, data6 = {22, 'f'};
    treePointer nodeA, nodeB, nodeC, nodeD, nodeE, nodeF;

    MALLOC(nodeA, sizeof(struct node));
    MALLOC(nodeB, sizeof(struct node));
    MALLOC(nodeC, sizeof(struct node));
    MALLOC(nodeD, sizeof(struct node));
    MALLOC(nodeE, sizeof(struct node));
    MALLOC(nodeF, sizeof(struct node));

    nodeA->leftChild = nodeB;
    nodeA->data = data1;
    nodeA->rightChild = nodeC;

    nodeB->leftChild = nodeD;
    nodeB->data = data2;
    nodeB->rightChild = nodeE;

    nodeC->leftChild = nodeF;
    nodeC->data = data3;
    nodeC->rightChild = NULL;

    nodeD->leftChild = NULL;
    nodeD->data = data4;
    nodeD->rightChild = NULL;

    nodeE->leftChild = NULL;
    nodeE->data = data5;
    nodeE->rightChild = NULL;

    nodeF->leftChild = NULL;
    nodeF->data = data6;
    nodeF->rightChild = NULL;

    return nodeA;
}

void traversalBST(treePointer root){
    /* LVR */
    if (root){
        traversalBST(root->leftChild);
        printf("%d ", root->data.key);
        traversalBST(root->rightChild);
    }
}

void freeBST(treePointer root){
    if (root){
        freeBST(root->leftChild);
        freeBST(root->rightChild);
        free(root);
    }
}

element *search(treePointer root, int key){
    /* recursion ver. */
    if (!root) return NULL;
    if (key == root->data.key) return &root->data;
    if (key < root->data.key)
        return search(root->leftChild, key);
    else
        return search(root->rightChild, key);
}

element *iterSearch(treePointer tree, int key){
    /* iteration ver. */
    while (tree){
        if (key == tree->data.key) return &tree->data;
        if (key > tree->data.key)
            tree = tree->rightChild;
        else
            tree = tree->leftChild;
    }
    return NULL;
}

void insert(treePointer *ptr, int k, char ch){
    treePointer node, lastNode = modifiedSearch(*ptr, k);
    if (lastNode){
        MALLOC(node, sizeof(struct node));
        node->data.ch = ch;
        node->data.key = k;
        node->leftChild = node->rightChild = NULL;

        if (*ptr){
            if (k < lastNode->data.key)
                lastNode->leftChild = node;
            else
                lastNode->rightChild = node;
        }
        else
            *ptr = node;
    }
    else
        printf("key exist.\n");
}

treePointer modifiedSearch(treePointer node, int key){
    for(;;){
        if (key == node->data.key) return NULL;
        if (key > node->data.key){
            if (!(node->rightChild))
                return node;
            else
                node = node->rightChild;
        }
        else{
            if (!(node->leftChild))
                return node;
            else
                node = node->leftChild;
        }
    }
}






