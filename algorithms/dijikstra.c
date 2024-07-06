#include <stdio.h>
#include <limits.h>
#define V 6

void dijikstra(int graph[V][V],int source);
int minDistance(int distance[V],int visited[V]);
void display(int distances[V], int source);

void display(int distances[V], int source) {
    printf("Shortest distances from source vertex %d:\n", source);
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t\t %d\n", i, distances[i]);
    }
}


int minDistance(int distance[V],int visited[V]){
	int min=INT_MAX , min_index;
	
	for(int i=0;i<V;i++){
		if(visited[i]==0 && distance[i]<min){
			min=distance[i];
			min_index=i;
		}
	}
	
	return min_index;
}


void dijikstra(int graph[V][V],int source){
	
	int distance[V];
	int visited[V];
	
	//start all distances with infinity and visited as 0.
	for (int i=0;i<V;i++){
		distance[i]=INT_MAX;
		visited[i]=0;
	}
	//make the source's dist as 0
	distance[source]=0;
	
	
	//find shortest path for all verticies
	int count=0;
	while(count<V-1){
		
		int u = minDistance(distance,visited);
		
		// mark the min vertex as visited
		visited[u]=1;
		
		
        // Update distance[v] only if it's not visited,and there is an edge 
        // and the total weight of path from source to v through u is smaller than current value
			
		for(int v=0;v<V;v++){
			
			if(visited[v]==0 && graph[u][v] && distance[u] +graph[u][v]<distance[v]){
				distance[v]=distance[u] +graph[u][v];
			}
					
		}
		
		count++;
	}
	
	//display result
    display(distance,source);
	
	
	
}



int main() {
 
    int graph[V][V] = {
    //   0  1  2  3  4  5
        {0, 4, 2, 0, 0, 0},
        {4, 0, 1, 5, 0, 0},
        {2, 1, 0, 8, 10, 0},
        {0, 5, 8, 0, 2, 6},
        {0, 0, 10, 2, 0, 4},
        {0, 0, 0, 6, 4, 0}
    };
    
    // choose a Source vertex
    int source = 3;
    
    // Run Dijkstra's algorithm
    dijikstra(graph, source);
    
    return 0;
}
