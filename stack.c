#include <stdio.h>
void push();
void pop();
void disp();
int top=-1;
int stk[5];

int main(){
	int c;
	do{
	
	printf("\npress 1 for push , 2 for pop , 3 for disp , 0 to exit\n");
	scanf("%d",&c);
    switch (c){
    	case 1:
    		push();
    		break;
    	case 2:
		    pop();
			break;
		case 3:
		    disp();
			break;
		case 0:
			printf("exited");
		break;
			default:
			printf("\nenter the correct choice");
					
	}

}
	while(c!=0);
	return 0;
}
void push(){
	int el;
if (top>=4){
	printf("\nstack overflow");
	return 0;
}
top+=1;
printf("\nenter the element\n");
scanf("%d",&el);

stk[top]=el;

}
void pop(){
	int el;
	if (top==-1){
		printf("stack underflow");
		return 0;
	}
	el=stk[top];
	printf("the deleted element is %d",el);
	top-=1;
	
}
void disp(){
	int i;
	if(top==-1){
		printf("stack empty");
		return 0;
	}
	for(i=top;i>=0;i--){
		printf("\n stack[%d]=%d\n",i,stk[i]);	
	}
}
