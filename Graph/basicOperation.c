#include <stdio.h>
#include "GraphADT.h"

nodePointer createNode(int vertex){
    nodePointer node;
    MALLOC(node, sizeof(struct node));
    node->vertexIdx = vertex;
    node->link = NULL;

    return node;
}

void addEdge(nodePointer adjList[], int src, int dst){
    // from src to dst
    nodePointer dstNode = createNode(dst);
    dstNode->link = adjList[src];
    adjList[src] = dstNode;

    // from dst to src, bidirect graph don't need this segment
    nodePointer srcNode = createNode(src);
    srcNode->link = adjList[dst];
    adjList[dst] = srcNode;
}

void printAdjList(nodePointer adjList[], int graphSize){
    /* print adjacent list of graph */

    for (int i = 0; i < graphSize; i++){
        printf("adjList[%d]:", i);

        nodePointer temp = adjList[i];
        while (temp){
            printf(" %d", temp->vertexIdx);
            temp = temp->link;
        }
        puts("");
    }
}

void resetVisited(int visited[]){
    /* reset visited array with some graph */
    for (int i = 0; i < MAXSIZE; i++){
        visited[i] = FALSE;
    }
}

void freeList(nodePointer adjList[], int graphSize){
    for (int i = 0; i < graphSize; i++){
        nodePointer current = adjList[i];

        while (current){
            nodePointer temp = current;
            current = current->link;
            free(temp);
        }
        adjList[i] = NULL;
    }
}

/** example undirect graph with 8 vertex
 * adjList[0]: 1 -> 2 -> NULL
 * adjList[1]: 0 -> 3 -> 4 -> NULL
 * adjList[2]: 0 -> 5 -> 6 -> NULL
 * adjList[3]: 1 -> 7 -> NULL
 * adjList[4]: 1 -> 7 -> NULL
 * adjList[5]: 2 -> 7 -> NULL
 * adjList[6]: 2 -> 7 -> NULL
 * adjList[7]: 3 -> 4 -> 5 -> 6 -> NULL
 */

/** test code */
// int main(void){
//     int graphSize = 8;
//     nodePointer adjList[graphSize];
//     for (int i = 0; i < graphSize; i++){
//         adjList[i] = NULL;
//     }

//     // the example graph has 10 edges
//     addEdge(adjList, 0, 1);
//     addEdge(adjList, 0, 2);
//     addEdge(adjList, 1, 3);
//     addEdge(adjList, 1, 4);
//     addEdge(adjList, 2, 5);
//     addEdge(adjList, 2, 6);
//     addEdge(adjList, 3, 7);
//     addEdge(adjList, 4, 7);
//     addEdge(adjList, 5, 7);
//     addEdge(adjList, 6, 7);

//     printAdjList(adjList, graphSize);
//     freeList(adjList, graphSize);
// }

