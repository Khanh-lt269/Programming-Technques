#include<stdio.h>

double* maximum(double* a, int size){
    double *max;
    max = a;
    if (a==NULL) return NULL;

    /*****************
    # YOUR CODE HERE #
    *****************/
    int i=0;
    for (i=0; i<size; i++){
    	if (*(a+i) > *max){
    		max = &a[i];
		}
	}
    return max;
}

int main(){
	double a[100];
	int n = 7;
	for (int i=0; i<n; i++){
		scanf("%lf", &a[i]);
	}
	printf("%lf", *maximum(a,n));
	return 0;
}
