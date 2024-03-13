#include<stdio.h>
#define INT_MAX 999999

void printit(int dist[4][4]){
	int i,j;	
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			if(dist[i][j]==INT_MAX){
				printf("| inf ");
			}else{
		
			printf("|  %d  ",dist[i][j]);
			}
		}
		printf("\n");
	}
	
}
void floyd(int graph[4][4]){
	int dist[4][4];
	int i,j,parent[4];
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			dist[i][j]=graph[i][j];//making a copy of original graph into cost matrix
		}
	}
	int k;
	//main code
	for(k=0;k<4;k++){
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
			
			if(dist[i][k]+dist[k][j]<dist[i][j]){
				dist[i][j]=dist[i][k]+dist[k][j];
	
				}
				
			}
	}
		
	}
	printit(dist);
}


int main(){
	
	int graph[4][4]={{0,3,INT_MAX,7},
					{8,0,2,INT_MAX},
					{5,INT_MAX,0,1},
					{2,INT_MAX,INT_MAX,0}};
	int i,j;
	printf("<==============given matrix================>\n");
	printit(graph);
	printf("<==============the solution================>\n");
	floyd(graph);
}