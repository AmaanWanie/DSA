#include<stdio.h>

int a[]={1,3,5,8,9,12,17};
int found=0;
int n=sizeof(a)/sizeof(a[0]);
void LS(int data){
	for(int i=0;i<n;i++){
		if(a[i]==data){
		printf("data found\n");
		found=1;
		}
	}
	if(found==0){
		printf("data not found");
	}
	
}
int main(){
 int data=5;
	LS(data);
}