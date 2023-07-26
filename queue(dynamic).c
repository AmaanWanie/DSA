#include <stdio.h>
#include <stdlib.h>
struct queue {
	int data;
	struct queue *link;
};
 struct queue *start=NULL;
 struct queue *end =NULL;
 void insertR();
 void display();
void deleteB();

int main() {
	int el;
	do{
		printf("enter 1 for insert\nenter 2 for delete\nenter 3 for display\n");
		scanf("%d",&el);
		
		
		switch(el){
			case 1:
				insertR();
				break;
			case 2: 
			deleteB();
				break;
			case 3: 
			    display();
			    break;
			default: 
			printf("wrong option chosen");
			
				
		}
	
		
	}	while(el!=0);
	return 0;
}
 
void insertR(){
	int el;
	struct queue *p;
	p=(struct queue *)malloc(sizeof(struct queue));
	if(p==NULL){
		printf("stack overflow");
		return;
	}
	
	printf("enter the element\n");
	scanf("%d",&el);
	p->data=el;
	p->link=NULL;
	if(start==NULL && end==NULL){
		start=p;
		end=p;
	}
	else{
		end->link=p;
		end =p;
		
		
	}
}
void display(){
	struct queue *p;
	p=start;
	if (start==NULL){
		printf("empty stack");
		return;
	}
	else{ printf("start= %d\n", start);
		while(p->link!=NULL){
		printf("data = %d, data addr = %d , link= %d, link addr = %d \n", p->data, &p->data, p->link, &p->link);
		p=p->link;	
		}
		printf("data = %d, data addr= %d, link = %d, link addr = %d\n", p->data, &p->data, p->link, &p->link);
		

	
	} printf("end= %d\n", end);
} 
void deleteB(){
	struct queue *p;
	if(start==NULL){
		printf("stack empty\n");
		return;
	}
	else{
		printf("element %d has been deleted\n",start->data);
		p=start;
      start=p->link;
	p->link=NULL;
	
	
	}
	
	
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
