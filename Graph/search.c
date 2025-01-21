#include <stdio.h>
#include "GraphADT.h"

void dfsUsingRecursion(nodePointer adjList[], int visited[], int startVertex){
    visited[startVertex] = TRUE;
    printf(" %d", startVertex);

    nodePointer current = adjList[startVertex];
    while (current){
        if (!visited[current->vertexIdx]){
            dfsUsingRecursion(adjList, visited, current->vertexIdx);
        }
        current = current->link;
    }
}

void dfsUsingStack(nodePointer adjList[], int visited[], int startVertex){
    int stack[MAXSIZE];
    int top = -1;

    stack[++top] = startVertex;

    while (top != -1){
        int vertex = stack[top--];
        if (!visited[vertex]){
            printf(" %d", vertex);
            visited[vertex] = TRUE;
        }

        nodePointer temp = adjList[vertex];
        while (temp != NULL){
            if (!visited[temp->vertexIdx]){
                stack[++top] = temp->vertexIdx;
            }
            temp = temp->link;
        }
    }
}

void bfs(nodePointer adjList[], int visited[], int startVertex){
    int queue[MAXSIZE];
    int front = 0;
    int rear = 0;

    printf(" %d", startVertex);
    visited[startVertex] = TRUE;
    queue[rear++] = startVertex;

    while (front < rear){
        int vertex = queue[front++];
        
        for (nodePointer current = adjList[vertex]; current; current = current->link){
            if (!visited[current->vertexIdx]){
                printf(" %d", current->vertexIdx);
                visited[current->vertexIdx] = TRUE;
                queue[rear++] = current->vertexIdx;
            }
        }
    }
}

/** test code */
// int main(void){
//     int graphSize = 8;
//     nodePointer adjList[graphSize];
//     for (int i = 0; i < graphSize; i++){
//         adjList[i] = NULL;
//     }
//     int visited[MAXSIZE];
//     resetVisited(visited);

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

//     // printf("dfsUsingRecursion(0):");
//     // dfsUsingRecursion(adjList, visited, 0);

//     // printf("dfsUsingStack(0):");
//     // dfsUsingStack(adjList, visited, 0);

//     printf("bfs(0):");
//     bfs(adjList, visited, 0);

//     freeList(adjList, graphSize);
// }