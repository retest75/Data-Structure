#include "stdio.h"
#include "GraphADT.h"

void findConnected(nodePointer adjList[], int visited[], int graphSize){
    puts("Connected component:");
    for (int i = 0; i < graphSize; i++){
        if (!visited[i]){
            bfs(adjList, visited, i);
            puts("");
        }
    }
}

// /** test code
//  * 0 - 1 - 2
//  *     |
//  *     3
//  * 
//  * 4 - 5
//  * |
//  * 6 - 7
//  */
// int main(){
//     int graphSize = 8;
//     nodePointer adjList[graphSize];
//     for (int i = 0; i < graphSize; i++){
//         adjList[i] = NULL;
//     }
//     int visited[MAXSIZE];
//     resetVisited(visited);

//     addEdge(adjList, 0, 1);
//     addEdge(adjList, 1, 2);
//     addEdge(adjList, 1, 3);
//     addEdge(adjList, 4, 5);
//     addEdge(adjList, 4, 6);
//     addEdge(adjList, 6, 7);
//     printAdjList(adjList, graphSize);

//     findConnected(adjList, visited, graphSize);
//     resetVisited(visited);
//     freeList(adjList, graphSize);
// }