#include <stdio.h>
void tower();
int main(){
	int n;
	printf("enter the no'of disk\n");
	scanf("%d",&n);
	tower(n,1,2,3);
	return 0;
}
void tower(int n,int a,int b , int c){
	if(n>0){
		tower(n-1,a,c,b);
		printf("moving a disk from %d to %d\n",a,c);
		tower(n-1,b,a,c);
	}
}
