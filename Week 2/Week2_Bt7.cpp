#include <iostream>

using namespace std;

//# vi?t hàm arr_sum
/*****************
# YOUR CODE HERE #
*****************/
template <typename param,typename param1>

param arr_sum(param *a, param1 n, param *b, param1 m){
	double ans = 0;
	for (int i=0; i<n; i++){
		ans += a[i];
	}
	for (int i=0; i<m; i++){
		ans += b[i];
	}
	return ans;
}



int main() {
    int val;
    cin >> val;
    
    {
        int a[] = {3, 2, 0, val};
        int b[] = {5, 6, 1, 2, 7};
        cout << arr_sum(a, 4, b, 5) << endl;
    }
    {
        double a[] = {3.0, 2, 0, val * 1.0};
        double b[] = {5, 6.1, 1, 2.3, 7};
        cout << arr_sum(a, 4, b, 5) << endl;
    }

    return 0;
}
