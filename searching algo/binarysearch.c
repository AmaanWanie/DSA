#include<stdio.h>

int a[]={1,3,5,8,9,12,17};
//       0     -       6
int n =sizeof(a)/sizeof(a[0]);  // 7

int BS(){
	
	int data=18;
	
	int l=0; // 4
	int h=n-1; // 6
	while(l<h){ //0<6
		int mid =(l+h)/2; //3
		if(data==mid){ //18==8
			return 1;
		}else{
		if(data<mid)  //18<8 no
		h=mid-1;
		else{
			l=mid+1;
		}	
		}
		
	}
	return 0;
}

int main(){
	
	int x =BS();
	if (x==1){
		printf("true");
		
	}else{
		printf("false");
	}
}