#include <string>
#include <vector>

using namespace std;



vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer(arr1.size(), vector<int>(arr2[0].size(), 0));
    int p = arr1.size();
    int q = arr1[0].size();
    int r = arr2[0].size();
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < r; j++)
        {
            for (int k = 0; k < q; k++)
            {
                answer[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    
    
    
    return answer;
}