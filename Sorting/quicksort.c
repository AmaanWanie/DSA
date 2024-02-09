#include <stdio.h>
a[]={5,7,2,1,67,99};

void swap(int start, int end){
	int temp=a[start];
	a[start]=a[end];
	a[end]=temp;
}

int partition(int l, int h){
	int piv=a[l];
	int start=l;
	int end=h;
	while(start<end){
	
	while(a[start]<=piv){
		start++;
	}
	while(a[end]>piv){
		end--;
	}
	if(start<end){
		swap(start,end);
	}
 }
 swap(l,end);
 return end;
}

void quicksort(int l ,int h){
    if(l<h){
    	int end=partition(l,h);
    	quicksort(l,end-1);
    	quicksort(end+1,h);
	}
}

int main(){
	int l=0;
	int h=5;
	quicksort(l,h);
	for(int k=0;k<=5;k++){
		printf("%d ",a[k]);
	}
	
}