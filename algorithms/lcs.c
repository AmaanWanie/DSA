#include<stdio.h>

/*

   if(x[i]==y[j]){
       
	   cost[i][j]=1+cost[i-1][j-1] 
  }
  else{
     
  cost[i][j]=   maxValue(cost[i][j-1],cost[i-1][j])
  
}

*/

/*


algorithm LCS(X[],Y[],cost[][])

input:
output:
desc:

variable integer := i,j;

for (i=0;i<len_X) do//step=step+1
	cost[0][j]=0

	end for

for (j=0;i<len_Y) do //step=step+1
	cost[i][0]=0
	
	end for

for (i=1 < len_X)do //step=step+1
	
	for(j=1 < len_Y)//step=step+1
	
		if (X[i]==Y[j])
		   cost[i][j]= 1 + cost[i-1][j-1]
		
		else
		cost[i][j]= maxValue(cost[i-1][j],cost[i][j-1])
		
	end for

end for	

*/
int maxValue(int a,int b){
	
	if(a>=b){
		return a;
	}else{
		return b;
	}
	
	
	
	
	
}
void LCS(char X[5],char Y[5],int cost[5][5]){

	int i=0,j=0;
	
	for(i=0;i<5;i++){
		cost[i][0]=0;
	}
	
	for(j=0;j<5;j++){
		cost[0][j]=0;
	}
	
	for(i=1;i<=4;i++){
		//i side top to down
		for(j=1;j<=4;j++){
			//j side left to right
			
		if (X[i]==Y[j]){
		
		   cost[i][j]= 1 + cost[i-1][j-1];
	}
		else{
		
		int a =	cost[i-1][j];
		int b =	cost[i][j-1];
		
		cost[i][j]= maxValue(a,b);
			}
		}
		
		
		
	}
	printf("the longest seq is: %d ",cost[5][5]);
}


int main(){
	
	char X[5] = {'a', 'b', 'a', 'a', 'b'};
	char Y[5] = {'b', 'a', 'b', 'b', 'a'};

	int cost[5][5];
	
	LCS(X,Y,cost);
	
}