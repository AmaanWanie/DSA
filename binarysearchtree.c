#include <stdio.h>
#include <stdlib.h>
struct bst{
	struct bst *l;
	int data;
	struct bst *r;
};
struct bst *root;
//funct prototypes
void insert();
void inorder(struct bst *t);
void postorder(struct bst *t);
void inorder(struct bst *t);
void preorder(struct bst *t);
void modify(struct bst *t,int x);

int main(){
	int c, el;
	struct bst *t;
	do{
		printf("enter 1 for insert, 2 for inorder, 3 for post order, 4 for preorder\n");
		scanf("%d",&c);
	switch(c){
		case 1:
			insert();
			break;
		case 2:
			if(root==NULL){
				printf("empty root\n");
			}else{
				t=root;
				inorder(t);
				printf("\n");
			}
			break;
		case 3:
			if(root==NULL){
				printf("empty root\n");
			}else{
				t=root;
				postorder(t);
				printf("\n");
			}
			break;
			
			
			case 4:
			if(root==NULL){
				printf("empty root\n");
			}else{
				t=root;
				preorder(t);
				printf("\n");
			}
			break;				
		case 5:
			if(root==NULL)
			return;
			else{
				int x;
			t=root;
			printf("enter the element you wanna replace\n");
			scanf("%d",&x);
			modify(t,x);
			break;
			}
			default:
				printf("enter correct");
				
	}	
	}while(c!=0);
	return;
}
void insert(){
	int el;
	struct bst *p,*prev,*curr;
	p=(struct bst*)malloc(sizeof(struct bst));
	printf("enter the elements\n");
	scanf("%d",&el);
	p->data=el;
	p->l=NULL;
	p->r=NULL;	
	if(root==NULL){
		root=p;
	}else{
		prev=NULL;
		curr=root;
		while(curr!=NULL){
		 prev=curr;
			if(el<curr->data)
			curr=curr->l;
			else{
				curr=curr->r;
			}
			
		}
		if(el<prev->data)
		prev->l=p;
		else {
			prev->r=p;
		}
	}
}

void inorder(struct bst *t){
	if(t==NULL){
	
		return;
	}else{
		inorder(t->l);
		printf("%d  ",t->data);
		inorder(t->r);
		
	}
}

void postorder(struct bst *t){
if(t==NULL){
	
	return;
}
postorder(t->l);
postorder(t->r);
printf("%d ",t->data);
	
}

void preorder(struct bst *t){
	if(t==NULL){
		return;
	}
	printf("%d ",t->data);
	preorder(t->l);
	preorder(t->r);
}



void modify(struct bst *t,int x){
	
}

