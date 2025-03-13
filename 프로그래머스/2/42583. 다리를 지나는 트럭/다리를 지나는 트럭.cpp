#include <string>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<pair<int, int>> bridge;
    int currentWeight = 0;
    int truckIndex = 0;
    
    while (truckIndex < truck_weights.size() || !bridge.empty())
    {
        answer++;
        
        if (!bridge.empty() && bridge.front().second == answer)
        {
            currentWeight -= bridge.front().first;
            bridge.pop();
        }
        
        if (truckIndex < truck_weights.size() &&
            truck_weights[truckIndex] + currentWeight <= weight )
        {
            bridge.push({truck_weights[truckIndex], answer+bridge_length});
            currentWeight += truck_weights[truckIndex];
            truckIndex++;
        }
            
        
        
        
    }
    
    
    
    
    
    
    
    
    
    return answer;
}