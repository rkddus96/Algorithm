#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{

    string str;
    cin >> str;
    vector<int> AlphabetCnt(26, 0);
    for (char c : str)
    {
        int n = c - 'a';
        AlphabetCnt[n]++;
    }

    for (int cnt : AlphabetCnt)
    {
        cout << cnt << " ";
    }

}