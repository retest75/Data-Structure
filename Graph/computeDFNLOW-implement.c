/** command line:
 * gcc computeDFNLOW-implement.c findBiConnected.c basicOperation.c
 */
#include <stdio.h>
#include "GraphADT.h"

int main(void){
    // prepare graph with 10 vertics
    int graphSize = 10;
    nodePointer adjList[graphSize];
    for (int i = 0; i < graphSize; i++){
        adjList[i] = NULL;
    }
    int visited[MAXSIZE];
    resetVisited(visited);

    addEdge(adjList, 0, 1);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 2, 4);
    addEdge(adjList, 3, 4);
    addEdge(adjList, 3, 5);
    addEdge(adjList, 5, 7);
    addEdge(adjList, 5, 6);
    addEdge(adjList, 6, 7);
    addEdge(adjList, 7, 8);
    addEdge(adjList, 7, 9);
    printAdjList(adjList, graphSize);

    int dfn[MAXSIZE];
    int low[MAXSIZE];
    int count;
    init(dfn, low, &count);

    printf("%s", "show traversal path: ");
    countDFNLOW(adjList, visited, dfn, low, 3, -1, &count);
    puts("");

    printf("%s\n", "Vertex | 0 1 2 3 4 5 6 7 8 9");
    
    printf("%s", "dfn    |");
    for (int i = 0; i < graphSize; i++){
        printf(" %d", dfn[i]);
    }
    puts("");

    printf("%s", "low    |");
    for (int i = 0; i < graphSize; i++){
        printf(" %d", low[i]);
    }
    puts("");

    freeList(adjList, graphSize);
    return 0;
}

/* output
adjList[0]: 1
adjList[1]: 3 2 0
adjList[2]: 4 1
adjList[3]: 5 4 1
adjList[4]: 3 2
adjList[5]: 6 7 3
adjList[6]: 7 5
adjList[7]: 9 8 6 5
adjList[8]: 7
adjList[9]: 7
show traversal path:  3 5 6 7 9 8 4 2 1 0
Vertex | 0 1 2 3 4 5 6 7 8 9
dfn    | 9 8 7 0 6 1 2 3 5 4
low    | 9 0 0 0 0 1 1 1 5 4
*/