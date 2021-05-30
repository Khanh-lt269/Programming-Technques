#include <bits/stdc++.h>
using namespace std;

struct state{
    int i, j, old_L;
    //# constructor
    state(int _i = 0, int _j = 0, int _L = 0):
        i(_i), j(_j), old_L(_L){}
};

int main() {
    int n, k;
    cin >> n >> k;
    int x[n + 1];
    stack<state> s;
    //# number of consecutive suffix 1
    int L = 0;
    // TRY(1, 0, 0)
	s.push(state(1, 1));
    s.push(state(1, 0));
    while (!s.empty())
    {
        state top = s.top();
        s.pop();
        x[top.i] = top.j;
        //# if a new binary sequence is found
        if (top.i == n)
        {
            for (int i = 1; i <= n; ++i)
                cout << x[i] << " \n"[i == n];
            continue;
        }
        //# Kh? d? quy
        /*****************
        # YOUR CODE HERE #
        *****************/
        L = top.j ? top.old_L + 1 : 0 ;
        if (L + 1 < k){
        	s.push(state(top.i + 1, 1, L));
		}
		s.push(state(top.i + 1, 0, L));
    }
    return 0;
}
