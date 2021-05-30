#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int val1, val2;
    cin >> val1 >> val2;
    vector< vector<int> > a = {
        {1, 3, 7},
        {2, 3, 4, val1},
        {9, 8, 15},
        {10, val2},
    };

    //# s?p x?p các vector trong a theo t?ng các ph?n t? gi?m d?n
    /*****************
    # YOUR CODE HERE #
    *****************/
    sort(a.begin(), a.end(), [](vector<int> i, vector<int> j) {
		return accumulate(i.begin(), i.end(), 0) > accumulate(j.begin(), j.end(), 0);
		});

    for (const auto &v : a) {
        for (int it : v) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}
