#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void DFS(int idx, int CurHP, int joy ,int& maxJoy, vector<int>& loss, vector<int>& gain)
{
    if (CurHP <= 0)
        return ;

    if (idx == loss.size())
    {
        maxJoy = max(maxJoy, joy);
        return;
    }
    
    DFS(idx + 1, CurHP, joy, maxJoy, loss, gain);
    DFS(idx + 1, CurHP - loss[idx], joy + gain[idx], maxJoy, loss, gain);

}

int main()
{
    int N;
    cin >> N;
    int maxJoy = 0;
    vector<int> loss(N);
    vector<int> gain(N);

    for (int i = 0; i < N; i++)
        cin >> loss[i];
    for (int i = 0; i < N; i++)
        cin >> gain[i];


    DFS(0, 100, 0,maxJoy, loss, gain);
    cout << maxJoy << endl;
    return 0;

}