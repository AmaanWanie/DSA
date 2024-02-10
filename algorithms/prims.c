#include<stdio.h>
#include <limits.h>
#include <stdbool.h>


int infinity = INT_MAX;

//prims functions
void primMST(int graph[5][5],int N,int S);
int isempty(int Q[5],int N);

int isempty(int Q[5], int N) {
    int i;
    for (i = 0; i < N; i++) {
        if (Q[i] != -1) // If there's any vertex left in Q
            return 0; // Not empty
    }
    return 1; // Q is empty
}


void primMST(int graph[5][5], int N, int S) {
    int i, u, j, l;
    int key[N], parent[N], stat_Q[N],Q[N];

    for (i = 0; i < N; i++) {
        key[i] = INT_MAX;
        parent[i] = -1;
        stat_Q[i] = 0;
        Q[i]=i;
    }

    key[S] = 0;

    while (!isempty(Q, N)) {
    int min = INT_MAX;
    u = -1;

    // Find the vertex with minimum key that has not been visited yet
    for (j = 0; j < N; j++) {
        if (Q[j] != -1 && key[j] < min) {
            min = key[j];
            u = j;
        }
    }

    if (u == -1)
        break;

    // Mark the selected vertex as visited
    Q[u] = -1;

    // Update keys and parents for adjacent vertices
    for (l = 0; l < N; l++) {
        if (graph[u][l] && Q[l] != -1 && graph[u][l] < key[l]) {
            key[l] = graph[u][l];
            parent[l] = u;
        }
    }
}

    // Print the MST
    printf("Edge   Weight\n");
    for (i = 0; i < N; i++) {
        if (i != S)
            printf("%d - %d    %d\n", parent[i], i, graph[i][parent[i]]);
    }
}

int main() {
    // Example graph represented using adjacency matrix
    int graph[5][5] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
    int N = 5; // Number of vertices in the graph
    int S = 3;

    printf("Minimum Spanning Tree (MST) using Prim's Algorithm:\n");
    
    primMST(graph,N,S);

    return 0;
}