#include <iostream>
#include <vector>
#include <cmath>
#include <climits>


using namespace std;

int AccumulateTeamPerformance(vector<vector<int>>& matrix, vector<int> team)
{
    int teamPerformance = 0;
    for (int player : team)
    {
        for (int c : team)
        {
            teamPerformance += matrix[player][c];
        }

    }

    return teamPerformance;
}

int main()
{
    int n;
    cin >> n;
    //matrix 초기화
    int minDiff = INT_MAX;
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j]; 
        }
    }

    for (int mask = 0; mask < (1 << n); mask++)
    {
        vector<int> team1, team2;
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
            {
                team1.push_back(i);
            }
            else
            {
                team2.push_back(i);
            }
        }
        if (team1.size() == n / 2)
        {
            int team1Performance = AccumulateTeamPerformance(matrix, team1);
            int team2Performance = AccumulateTeamPerformance(matrix, team2);
            int diff = abs(team1Performance-team2Performance);

            if (diff < minDiff)
            {
                minDiff = diff;
            }
        }

    }


    cout << minDiff << endl;

}