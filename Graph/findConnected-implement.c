/** use command line: 
 * gcc findConnected-implement.c findConnected.c search.c basicOperation.c 
 */
#include <stdio.h>
#include "GraphADT.h"

/** example disconnected graph
 * 0 - 1 - 2
 *     |
 *     3
 * 
 * 4 - 5
 * |
 * 6 - 7
 */
int main(){
    // create disconnected graph with 8 vertics and 10 edges
    int graphSize = 8;
    nodePointer adjList[graphSize];
    for (int i = 0; i < graphSize; i++){
        adjList[i] = NULL;
    }
    int visited[MAXSIZE];
    resetVisited(visited);

    addEdge(adjList, 0, 1);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 4, 5);
    addEdge(adjList, 4, 6);
    addEdge(adjList, 6, 7);
    printAdjList(adjList, graphSize);

    findConnected(adjList, visited, graphSize);
    resetVisited(visited);

    freeList(adjList, graphSize);
    return 0;
}

/* output
adjList[0]: 1
adjList[1]: 3 2 0
adjList[2]: 1
adjList[3]: 1
adjList[4]: 6 5
adjList[5]: 4
adjList[6]: 7 4
adjList[7]: 6
Connected component:
 0 1 3 2
 4 6 5 7
*/