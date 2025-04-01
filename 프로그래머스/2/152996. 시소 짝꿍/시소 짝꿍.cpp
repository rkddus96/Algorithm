#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    unordered_map<int, int> freq;
    vector<pair<int, int>> ratios = {{1,1}, {2, 3}, {1,2}, {3, 4}};
    
    
    sort(weights.begin(), weights.end());
    reverse(weights.begin(), weights.end());
    
    for (int w : weights)
    {
        for (auto [a, b] : ratios)
        {
            int num = w * b;
            if (num % a == 0)
            {
                answer += freq[num/a];
            }
        }
        freq[w]++;
    }
    
    
    
    
    
    return answer;
}