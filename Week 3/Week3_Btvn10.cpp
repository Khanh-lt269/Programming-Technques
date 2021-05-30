#include <iostream>

using namespace std;

int testCase;
int x[200];
int n[100];
int h[100];

void print_sol(int n){
	for(int i=1; i <= n; i++){
		cout << x[i];
	}
	cout << "\n";
}

void TRY(int i, int j, int l_0, int l_1, int n, int h){
	x[i] = j;
	if(i == n){
		if(l_1 == h){
			print_sol(n);
		}
		
		return;
	}
//	if(j == 0){
		if (l_0 < n-h){
			TRY(i+1, 0, l_0+1, l_1, n, h);
			TRY(i+1, 1, l_0, l_1+1, n, h);
		}
		else {
			TRY(i+1, 1, l_0, l_1+1, n, h);
		}
//	}
//	if(j == 1){
//		if()
//	}
	
}

void Hamming(int n, int h){
	int l_0 = 0, l_1 = 0;  
	TRY(1, 0, ++l_0, l_1, n, h);
	l_0 = 0;
	TRY(1, 1, l_0, ++l_1, n, h);	
}

int main(){
	cin >> testCase;
	
	for(int i = 0; i < testCase ; i++){
		cin >> n[i];
		cin >> h[i];
	}
	
	for(int i = 0; i < testCase ; i++){
		Hamming(n[i],h[i]);
		cout << endl;
	}
	return 0;
}
