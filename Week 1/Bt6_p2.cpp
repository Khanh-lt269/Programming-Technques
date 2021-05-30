#include<stdio.h>


void reversearray(int arr[], int size){
    int l = 0, r = size - 1, tmp, mid = (l+r)/2;
    
    /*****************
    # YOUR CODE HERE #
    *****************/
    for (int i = l; i<=mid; i++){
    	tmp = arr[i];
    	arr[i] = arr[size-1-i];
    	arr[size-1-i] = tmp;
	}
}

void ptr_reversearray(int *arr, int size){
    int l = 0, r = size - 1, mid = (l+r)/2;
    /*****************
    # YOUR CODE HERE #
    *****************/
    int temp;
    for(int i=l; i<=mid; i++){
    	temp = *(arr+i);
		*(arr+i) = *(arr+size-1-i);
		*(arr+size-1-i) = temp; 	
	}
}

int main(){
	int arr[5] = {9, -1, 4, 5, 7};
//	reversearray(arr,5);
	ptr_reversearray(arr,5);
	for (int i=0;i<5;i++){
		printf("\t%d",arr[i]);
	}
	return 0;
}
