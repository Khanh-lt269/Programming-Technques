#include<bits/stdc++.h>

using namespace std;

const int MAX = 100;
int n,k;
int availablePath[MAX][MAX];
int m;
//vector< vector<int> > listPath;
bool visited[MAX];
int x[MAX];
int ans;

void input(){
	cin >> n >> k;
	cin >> m;
	int v1,v2;
	for (int i = 0; i < m; i++){
		cin >> v1 >> v2;
		availablePath[v1-1][v2-1] = 1;
		availablePath[v2-1][v1-1] = 1;
	}
	for (int i = 0 ; i < n ; i++){
		visited[i] = false;
	}
	ans = 0;
}

bool check(int a, int i){
	if(a == 0) return true;
	if(visited[i] == true) return false;
	if(availablePath[x[a-1]][i] == 0) return false;
	return true;
}

void updated(){
	ans++;
}

void TRY(int a){
	for (int i=0; i < n; i++){
		if (check(a,i)){
			visited[i] = true;
			x[a] = i;
			if (a == k){
				updated();
			}
			else {
				TRY(a+1);
			}
			visited[i] = false;
		}
	}
}

int main(){
	input();
	TRY(0);
	cout << ans/2;
	return 0;
}
