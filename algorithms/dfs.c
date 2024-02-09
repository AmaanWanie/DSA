#include <stdio.h>
#include <stdlib.h>

/*
Depth-First Search (DFS) is a graph traversal algorithm where you explore one path in
 the graph as deeply as possible before backtracking. 
 
It visits one node at a time and prioritizes exploring unvisited nodes 
adjacent to the current node
*/


void dfs(int graph[5][5],int start);

void dfs(int graph[5][5],int start){
	static int visited[5]={0};
	if (visited[start]==0){
		printf("%d is visited\n",start);
		visited[start]=1;
		
		int i;
    for(i=0;i<5;i++){
    	if(graph[start][i]==1 && visited[i]==0){
    		dfs(graph,i);
		}
	}
    }
    
}

int main(){
    int graph[5][5] = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {1, 1, 0, 1, 0}
    };
    int start=4;
    
    dfs(graph,start);
    
    return 0;
}