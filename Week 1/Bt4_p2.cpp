#include<stdio.h>

int counteven(int* arr, int size){
    int count = 0;
    int i = 0;
    /*****************
    # YOUR CODE HERE #
    *****************/
    for (i = 0; i< size; i++){
    	if (*(arr+i) % 2 == 0){
    		count += 1;
		}
	}
    return count;    
}

int main(){
	int arr[100];
	int size = 7;
	for (int i=0;i<size; i++){
		scanf("%d", &arr[i]);
	}
	printf("%d", counteven(arr, size));
	return 0;
}
