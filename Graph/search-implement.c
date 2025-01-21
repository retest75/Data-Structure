/** use command line:
 * gcc search-implement.c search.c basicOperation.c
 */
#include "GraphADT.h"
#include <stdio.h>

int main(void){
    // prepare graph with 8 vertex
    int graphSize = 8;
    nodePointer adjList[graphSize];
    for (int i = 0; i < graphSize; i++){
        adjList[i] = NULL;
    }
    int visited[MAXSIZE];
    resetVisited(visited);

    // the example graph has 10 edges
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 1, 4);
    addEdge(adjList, 2, 5);
    addEdge(adjList, 2, 6);
    addEdge(adjList, 3, 7);
    addEdge(adjList, 4, 7);
    addEdge(adjList, 5, 7);
    addEdge(adjList, 6, 7);
    printAdjList(adjList, graphSize);

    printf("dfsUsingRecursion(0):");
    dfsUsingRecursion(adjList, visited, 0);
    puts("");
    resetVisited(visited);
    
    printf("dfsUsingStack(0):");
    dfsUsingStack(adjList, visited, 0);
    puts("");
    resetVisited(visited);

    printf("bfs(0):");
    bfs(adjList, visited, 0);
    puts("");
    resetVisited(visited);

    freeList(adjList, graphSize);
}

/* output
adjList[0]: 2 1
adjList[1]: 4 3 0
adjList[2]: 6 5 0
adjList[3]: 7 1
adjList[4]: 7 1
adjList[5]: 7 2
adjList[6]: 7 2
adjList[7]: 6 5 4 3
dfsUsingRecursion(0): 0 2 6 7 5 4 1 3
dfsUsingStack(0): 0 1 3 7 4 5 2 6
bfs(0): 0 2 1 6 5 4 3 7
*/