#include <stdio.h>

int a[]={5,8,3,7,10,4,6};
//       0 1
void insertion(int a[],int n){
	int i,temp,j;
	for(i=1;i<n;i++){
		temp=a[i];
		j=i-1;
		while(j>=0 && a[j]>temp){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
		
		for(int k=0;k<n;k++){
		printf("%d ",a[k]);
		
	}printf("\n");
	}
	
}

int main(){
	int n=7;
	
	insertion(a,n);
//	for(int k=0;k<n;k++){
//		printf("%d ",a[k]);
//	}
}