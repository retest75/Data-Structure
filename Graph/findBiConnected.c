#include <stdio.h>
#include "GraphADT.h"

void init(int dfn[], int low[], int *count){
    /* reset dfn, low, and count */
    for (int i = 0; i < MAXSIZE; i++){
        dfn[i] = -1;
        low[i] = -1;
    }
    *count = 0;
}

void countDFNLOW(nodePointer *adjList, int *visited, int *dfn, int *low, int u, int parent, int *count){
    visited[u] = TRUE;
    printf(" %d", u); // show go through path

    dfn[u] = low[u] = (*count)++;

    nodePointer current = adjList[u];
    while(current){
        int vertex = current->vertexIdx; // next adjacent vertex

        if (vertex == parent){       // if next vertex is parent
            current = current->link; // go next adjacent vertex
            continue;
        }
        // if next vertex didn't pass through
        // go through next adjacent vertex and update low value of u
        if (!visited[vertex]){
            countDFNLOW(adjList, visited, dfn, low, vertex, u, count); 
            low[u] = MIN(low[u], low[vertex]);
        }
        // if next vertex have ever pass through
        // check that the edge is back edge or not, then update low value of u
        else{                                  
            low[u] = MIN(low[u], dfn[vertex]);
        }
        current = current->link;
    }
}

void findBCC(nodePointer *adjList, int *visited, int *dfn ,int *low, int u, int parent, int *count, struct edge *stack, int *top){
    visited[u] = TRUE;
    dfn[u] = low[u] = (*count)++;

    nodePointer current = adjList[u]; // next adjacent vertex
    while (current){
        int v = current->vertexIdx;

        if (v == parent){
            current = current->link;
            continue;
        }
        
        // push to stack
        // if dfn[v] < dfn[u] 的重要性在於 v 是子頂點，所以里碖上來說應該沒有被拜訪過，dfn[v] 應該比 dfn[u] 大
        // 但當 dfn[v] < dfn[u] 時表示 v 已經在之前出現過了
        // 現在這組 (u, v) 是一個回邊，是第二次出現，所以不用再推入 stack 中
        if (dfn[v] < dfn[u]){
            stack[++(*top)].u = u;
            stack[*top].v = v;
        }

        if (!visited[v]){
            findBCC(adjList, visited, dfn, low, v, u, count, stack, top);
            low[u] = MIN(low[u], low[v]);

            if (low[v] >= dfn[u]){ // u 是接合點
                printf("articulation point: %d\n", u);
                // pop from stack
                int x, y;
                do {
                    x = stack[*top].u;
                    y = stack[(*top)--].v;
                    printf(" (%d,%d)", x, y);
                } while (!((x == u) && (y == v)));
                puts("");
            }
        }
        else if (dfn[v] < dfn[u]){
            low[u] = MIN(low[u], dfn[v]);
        }
        current = current->link;
    }
}

// test code
// int main(void){
//     // prepare graph with 10 vertics
//     int graphSize = 10;
//     nodePointer adjList[graphSize];
//     for (int i = 0; i < graphSize; i++){
//         adjList[i] = NULL;
//     }
//     int visited[MAXSIZE];
//     resetVisited(visited);

//     addEdge(adjList, 0, 1);
//     addEdge(adjList, 1, 2);
//     addEdge(adjList, 1, 3);
//     addEdge(adjList, 2, 4);
//     addEdge(adjList, 3, 4);
//     addEdge(adjList, 3, 5);
//     addEdge(adjList, 5, 7);
//     addEdge(adjList, 5, 6);
//     addEdge(adjList, 6, 7);
//     addEdge(adjList, 7, 8);
//     addEdge(adjList, 7, 9);
//     printAdjList(adjList, graphSize);

//     int dfn[MAXSIZE];
//     int low[MAXSIZE];
//     int count;
//     struct edge stack[MAXSIZE * (MAXSIZE / 2)];
//     int top = -1;
//     init(dfn, low, &count);

//     findBCC(adjList, visited, dfn, low, 3, -1, &count, stack, &top);

//     freeList(adjList, graphSize);
//     return 0;
// }

