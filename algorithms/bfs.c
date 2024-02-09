#include <stdio.h>
/*Breadth-First Search (BFS) Algorithm
 
 BFS is a graph traversal algorithm that explores the nodes in a graph level by level. 
 It starts at a chosen node (often called the 'root') and explores all of its neighbors at the present depth 
 before moving on to the nodes at the next depth level. 
 
 How BFS works:
 1. Start with a queue and enqueue the starting node.
 2. Dequeue a node from the queue and visit it.
 3. Enqueue all the adjacent nodes that haven't been visited yet.
 4. Repeat steps 2-3 until the queue is empty.*/

void bfs(int graph[5][5], int start);

int Q[5], front = -1, rear = -1;

void bfs(int graph[5][5], int start) {
    static int visited[5] = {0};
    
    
    // Enqueue the starting node
    Q[++rear] = start;
    visited[start] = 1;
    
    while (front != rear) {
        // Dequeue a vertex from the queue
        int current = Q[++front];
        printf("%d is visited\n", current);
        
        // Enqueue all adjacent unvisited vertices
        int i;
        for (i = 0; i < 5; i++) {
            if (graph[current][i] == 1 && visited[i] == 0) {
                Q[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int graph[5][5] = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {1, 1, 0, 1, 0}
    };
    int start = 1;
    
    bfs(graph, start);
    
    return 0;
}