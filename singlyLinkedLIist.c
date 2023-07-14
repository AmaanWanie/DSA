#include <stdio.h>
#include <stdlib.h>
struct sll {
	int D;
	struct sll *l;
};
struct sll * start=NULL;
struct sll * end=NULL;

void insertFront();
void insertEnd();

void delFront();
void delEnd();
void display();

int main(){
	int a;
	do{
		printf("press 1 for insertAtFront\n");
        printf("press 2 for insertAtEnd\n");
        printf("press 3 for deleteAtFront\n");
        printf("press 4 for deleteAtEnd\n");
        printf("press 5 for display\n");
        scanf("%d",&a);
        
        switch(a){
         	case 1 :
        		insertFront();
        		break;
        	case 2 :
            insertEnd();
        	    break;
         	case 3 :
     		delFront();
        		break;
        	case 4 :
        		delEnd();
        		break;
        	case 5 :
       		display();
        		break;
        	default :
        		break;
		}
	}
	while (a!=0);
	return 0;
	
}
void insertFront(){
	struct sll *p;
	int el;
	p=(struct sll *)malloc(sizeof(struct sll));
	printf("enter the element");
	scanf("%d",&el);
		p->D=el;
		p->l=start;
	if(start==NULL){
	
		start=p;
		end=p;
	//	free(p);
		
	}
	else {
		start=p;
		
	}
}
void insertEnd(){
	struct sll *p;
	if(start==NULL){
		printf("empty sll");
		return;
	}
	int el;
	p=(struct sll *)malloc(sizeof(struct sll));
	
	printf("enter the element");
	scanf("%d",&el);
	p->D=el;
	p->l=NULL;
	if(start==NULL){
	
		start=p;
		end=p;
	//	free(p);
		
	}
	else{
		end->l=p;
		end = p;
		
	}
	
}


void display() {
    struct sll* p;
    if (start == NULL) {
        printf("Empty linked list\n");
        return;
    }
    p = start;
    
    while (p != NULL) {
       // printf("%d ", p->D);
       printf("el=: %d link =:%d pointer=:%d\n",p->D,p->l,p);
        p = p->l;
    }
    printf("\n");
    printf("start=%d\n",start);
    printf("end=%d\n",end);
}
void delFront(){
	struct sll *p;
	if(start==NULL){
		printf("stack empty");
		return;
	}	
		p=start;
		p=p->l;
		start=p;
	
	
}
void delEnd(){
	struct sll *p;
	if(start==NULL){
		printf("stack empty");
		return;
	}
	p=start;
	if (start->l == NULL) {
        free(start);
        start = NULL;
        end = NULL;
        return;
   }
      
	
	while(p->l->l!=NULL){
		p=p->l;
	}
	printf("the ele deleted is %d",p->l->D);
	p->l=NULL;
	end = p;
}
