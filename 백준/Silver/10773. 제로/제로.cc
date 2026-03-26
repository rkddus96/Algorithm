#include <iostream>

using namespace std;

#define MAX_INT 100000

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    int arr[MAX_INT];
    int len = 0;
    int totalMoney = 0;
    
    while (n--)
    {
        int m;
        cin >> m;
        if (m != 0)
        {
            arr[len++] = m;
            totalMoney += m;
        }
        else
        {
            totalMoney -= arr[--len];
        }
    }
    
    cout << totalMoney;
}