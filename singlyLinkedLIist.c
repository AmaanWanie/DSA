#include <stdio.h>
#include <stdlib.h>

struct sll {
    int D;
    struct sll* l;
};

struct sll *start = NULL;


// Function prototypes
void insertFront(); // Insert element at the front of the linked list
void insertEnd();   // Insert element at the end of the linked list
void delFront();    // Delete element from the front of the linked list
void delEnd();      // Delete element from the end of the linked list
void display();     // Display the entire linked list

int main() {
    int a;
    do {
        printf("Press 1 for insertAtFront\n");
        printf("Press 2 for insertAtEnd\n");
        printf("Press 3 for deleteAtFront\n");
        printf("Press 4 for deleteAtEnd\n");
        printf("Press 5 for display\n");
        printf("Press 0 to exit\n");
        scanf("%d", &a);

        switch (a) {
        case 1:
            insertFront();
            break;
        case 2:
            insertEnd();
            break;
        case 3:
            delFront();
            break;
        case 4:
            delEnd();
            break;
        case 5:
            display();
            break;
        default:
            break;
        }
    } while (a != 0);
    return 0;
}

void insertFront() {
  struct sll *p;
  p=(struct sll *)malloc(sizeof(struct sll));
  printf("enter element\n");
  int el;
  scanf("%d",&el);
  p->D=el;
  p->l=NULL;
  if(start==NULL){
  	start=p;
  }else{
  	p->l=start;
  	start=p;
  	
  }
}

void insertEnd(){
   struct sll *p;
   p=(struct sll*)malloc(sizeof(struct sll));
   printf("enter element\n");
  int el;
  scanf("%d",&el);
  p->D=el;
  p->l=NULL;
  
  if(start==NULL){
  	start=p;
  }else{
  	struct sll *q;
  	q=start;
  	while(q->l!=NULL){
  		q=q->l;
	  }
	  q->l=p;
  }
  
}

void display() {
   struct sll *q;
   if(start==NULL){
   	printf("empty list\n");
   }else{
  	q=start;
  	while(q!=NULL){
  		printf("%d ",q->D);
  		q=q->l;
	  }
	  printf("\n");
   }
}

void delFront() {
    struct sll *p;
    p=start;
    if(start==NULL){
    	printf("empty list\n");
	}else{
		start=p->l;
		p->l=NULL;
		free(p);
	}
}

void delEnd() {
    struct sll *p;
    p=start;
    if(start==NULL){
    	printf("empty list\n");
	}else{
		while(p->l->l!=NULL || p->l!=NULL){
			p=p->l;
		}
		p->l=NULL;
	}
   
}
