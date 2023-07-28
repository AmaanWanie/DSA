#include <stdio.h>
#include <stdio.h>
void enque();
void deque();
void display();
void count();
int F=-1,R=-1,c=0,Q[7];

void main(){
	int e;
	do{
	printf("enter 1 for insert\nenter 2 for delete\nenter 3 for display\nenter 4 for count\n");
	scanf("%d",&e);
	switch(e){
		case 1 :
			enque();
			break;
		case 2 :
			deque();
			break;
		case 3 :
			display();
			break;
		case 4 :
			count();
			break;
		default :
			printf("entercorrectvalue");
	        }
	        
	    
      }
	  while(e!=0);
}
void enque(){
	if(R>=7){
		printf("queue full");
		return;
	}
	int e;
	printf("enter the element\n");
	scanf("%d",&e);
	if(F==-1 && R==-1){
		F+=1;
		R+=1;
	}
	else{
		R+=1;
	}
	Q[R]=e;
	
}
void deque(){
	if(F==-1 && R==-1){
		printf("queue empty\n");
		return;
	}
	int e;
	e=Q[F];
	printf("the element del is %d\n",e);
	F++;
	if(F>R){
	F=-1;
	R=-1;	
	}
}
void display(){
	if(F==-1 && R==-1){
		printf("empty queue\n");
		return;
	}
	int i;
	for(i=F;i<=R;i++){
	
     printf("Q[%d]=%d    ",i,Q[i]);
	 	}
	 	printf("\nF=%d R=%d",F,R);
	 	printf("\n");
}
void count(){
	if(F==-1 && R==-1){
		printf("empty queue");
		return;
	}
	c=(R-F)+1;
	printf("count is %d\n",c);
}