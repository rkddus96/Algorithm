#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    set<int> right_set, left_set;
    vector<int> right_count(topping.size());
    for (int i = topping.size()-1; i >= 0; i--)
    {
        right_set.insert(topping[i]);
        right_count[i] = right_set.size();
    }
    
    for (int i = 0; i < topping.size(); i++)
    {
        left_set.insert(topping[i]);
        if (left_set.size() == right_count[i+1])
        {
            answer++;
        }
    }
    
    
    
    return answer;
}