#include <bits/stdc++.h>

using namespace std;

int x[201];
int n, k1, k2;

void print_sol(){
	for(int i=1; i <= n; i++){
		cout << x[i];
	}
	cout << "\n";
}


void TRY(int i, int j, int day){
    x[i] = j;
    if (i == n) {
    	if (day >= k1){
    		print_sol(); 
		}
		return;
	}    
	if (j == 0) {
    	TRY(i + 1, 1, day = 1);
	}
	if (j == 1) {
		if (day < k1){
			TRY(i + 1, 1, day+1);
		}
		else if (day >= k1 && day <= k2){
			if(day == k2){
				TRY(i + 1, 0, day);
			}
			else{
				TRY(i + 1, 0, day=1);
				TRY(i + 1, 1, day+1);
			}
		}
		else {
			TRY(i+1, 0, day = 1); 
			
		}
	}
}

int main() {
    
    cin >> n >> k1 >> k2;
    if (n == 0 || n > 200 || k1 > 70 || k2 > 70){
    	return 0;
	}
    int day = 0;
    TRY(1,0,day);
    TRY(1,1,day+1);
    return 0;
}
