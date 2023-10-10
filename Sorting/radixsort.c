#include <stdio.h>
#include <stdlib.h>

int arr[]={170, 45, 75, 90, 802, 24, 2, 66};
int n=sizeof(arr) / sizeof(arr[0]);

int times=0;//ignore


void countSort(int pos){
	int output[n];
	int count[10]={0};

	for(int i=0;i<n;i++){
		count[(arr[i]/pos)%10]++;
	}
	
	for(int i=1;i<=9;i++){
		count[i]=count[i]+count[i-1];
	}
	
	for(int i=n-1;i>=0;i--){
		output[--count[(arr[i]/pos)%10]]=arr[i];
	}
	
	for (int k = 0; k < n; k++) {
        arr[k] = output[k];
    }
    
    // im displaying for each time pos is updated (3 times)

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    times++;
    printf("times countSort ran = %d\n",times);
}

int getMax(){	
//to get the maximum value in the array
	int max=arr[1];
	for(int i=0;i<n;i++){
		if(arr[i]>max){
			max=arr[i];
		}
	}
	return max;
}

void radixSort(){
	int max=getMax();
	// calls contsort 3 times as pos is 3(pos is the no. of digits of max no ) 
	for(int pos=1;max/pos>0;pos*=10){
		countSort(pos);
	}
}

int main(){
	printf("iniitially array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
	radixSort();
	
	
}