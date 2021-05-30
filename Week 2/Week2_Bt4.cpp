#include <stdio.h>

int cube(int x) {
    //# tr? v? l?p phuong c?a x
    /*****************
    # YOUR CODE HERE #
    *****************/
    return x*x*x;
}

//# vi?t hàm tính l?p phuong c?a m?t s? ki?u double
/*****************
# YOUR CODE HERE #
*****************/
double cube(double x){
	return x*x*x;
}

int main() {
    int n;
    double f;
    scanf("%d %lf", &n, &f);
    
    printf("Int: %d\n", cube(n));
    printf("Double: %.2lf\n", cube(f));
    
    return 0;
}
