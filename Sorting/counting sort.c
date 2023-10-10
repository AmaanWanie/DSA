#include <stdio.h>
#include <stdlib.h>

int arr[]={4,2,2,8,3,3,1,9};

void countingSort(int r,int n){
int count[r+1];

 for (int i = 0; i <= r; i++) {
        count[i] = 0;
    }	
    
	for(int i=0;i<n;i++){
		count[arr[i]]++;
	}
	
	for(int i=1;i<=r;i++){
		count[i]+=count[i-1];
	}
	
	int* output = (int*)malloc(n * sizeof(int));
	
	for(int i=n-1;i>=0;i--){
		output[count[arr[i]]-1]=arr[i];
		count[arr[i]]--;
	}
	
	for(int i=0;i<n;i++){
		printf("%d ",output[i]);
	}
}

int main(){
	countingSort(9,8);
}