/** use command line:
 * gcc findBiConnected-implement.c findBiConnected.c basicOperation.c 
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
    struct edge stack[MAXSIZE * (MAXSIZE / 2)];
    int top = -1;
    init(dfn, low, &count);

    findBCC(adjList, visited, dfn, low, 3, -1, &count, stack, &top);

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
articulation point: 7
 (7,9)
articulation point: 7
 (7,8)
articulation point: 5
 (7,5) (6,7) (5,6)
articulation point: 3
 (3,5)
articulation point: 1
 (1,0)
articulation point: 3
 (1,3) (2,1) (4,2) (3,4)
*/