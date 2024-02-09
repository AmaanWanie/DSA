#include <stdio.h>

int a[]={9,8,7,6,5,4,3};
//       0 1 2 3 4 5 6
void insertion(int a[],int n){
	int i,temp,j;
	for(i=1;i<n;i++){//i=1
		temp=a[i];//8
		j=i-1;   //0
		while(j>=0 && a[j]>temp){//0>=0 and a[0]=9>8
			a[j+1]=a[j];//a[0+1]=a[1] => a[1]=9
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
		for(int k=0;k<n;k++){
		printf("%d ",a[k]);
	}
	printf("\n");
	insertion(a,n);

}