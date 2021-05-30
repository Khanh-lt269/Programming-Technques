#include <stdio.h>
int main(){
    int a[7]= {13, -355, 235, 47, 67, 943, 1222};
	int *ptr = &a[0]; 
    printf("address of first five elements in memory.\n");
    for (int i=0; i<5;i++){
    	ptr = &a[i];
    	printf("\ta[%d] = %d ",i, ptr);
	}
    printf("\n");
    
    /*****************
    # YOUR CODE HERE #
    *****************/
           
    return 0;
}
