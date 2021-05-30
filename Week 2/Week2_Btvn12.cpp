#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

vector<pair<int, int>> myList;

void ReadInput()
{
    int key = 0;
    int value = 0;
    while (cin >> key && cin >> value)
    {
        myList.push_back(make_pair(key, value));
    }
}

void PrintOutput()
{
    size_t length = myList.size();
    for (size_t i = 0; i < length; ++i)
    {
        std::cout << myList[i].first << ' ' << myList[i].second << '\n';
    }
}

int main()
{
	printf("Le Trong Khanh 20194082 \n\n");
    ReadInput();
    sort(myList.begin(), myList.end(), [](pair<int, int> pair1, pair<int, int> pair2) -> bool
        {
            return (pair1.second > pair2.second || (pair1.second == pair2.second && pair1.first > pair2.first));
        });
    PrintOutput();
    return 0;
}
