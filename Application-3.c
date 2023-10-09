/*APPLICATION PROGRAM 3:
Social networks consist of individuals connected through various 
relationships. Analyzing the connectivity within a social network can 
provide insights into communities, influence propagation, and 
information flow. One way to analyze the connectivity is to find the 
connected components within the network. Given a social network 
represented as an adjacency matrix, the task is to find the connected 
components using the Depth-First Search (DFS) algorithm. The 
program should implement the DFS algorithm to traverse the 
network, identify the connected components, and display them.
Dynamic Programming Approach...*/

#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
int vertices;

void initGraph() {
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            graph[i][j] = 0;
        }
        visited[i] = 0;
    }
}

void addEdge(int src, int dest) {
    graph[src][dest] = 1;
    graph[dest][src] = 1;
}

void dfs(int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < vertices; i++) {
        if (graph[vertex][i] && !visited[i]) {
            dfs(i);
        }
    }
}

void findConnectedComponents() {
    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            dfs(i);
            printf("\n");
        }
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    initGraph();

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Connected components:\n");
    findConnectedComponents();

    return 0;
}
