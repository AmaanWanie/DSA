#include <stdio.h>

void enque();
void deque();
void display();
//void count();
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
			//count();
			break;
		default :
			printf("entercorrectvalue");
	        }
	        
	    
      }
	  while(e!=0);
}
void enque(){
	int el;
	if((R+1)%7==F){
		printf("que full");
		return;
	}
	printf("enter element\n");
	scanf("%d",&el);
	if(R==-1 && F==-1){
		R=0;
		F=0;
		
	}else{
		R=((R+1)%7);
	}
	Q[R]=el;
	
}
void deque(){
	int el;
	if(R==-1 && F==-1){
		printf("queue empty");
		return;
	}
	el=Q[F];
	printf("the deleted element is %d\n",el);
	if(F==R){
		F=-1;
		R=-1;
	}else{
		F=((F+1)%7);
	}
	
}
void display(){
	 if (F == -1 && R == -1) {
        printf("empty queue\n");
        return;
    }
    int i=F;
    while(1){
    	printf("Q[%d]=%d ",i,Q[i]);
    	 if (i == R){
    	 	 break;
    	 	  
		 }
     i = (i + 1) % 7;  
        
	}
	printf("\nF=%d R=%d\n", F, R);
    
}