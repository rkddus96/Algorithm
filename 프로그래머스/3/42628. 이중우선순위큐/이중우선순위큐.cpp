#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    multiset<int> dq;
    
    for (string& op : operations)
    {
        if (op[0] == 'I')
        {
            int num = stoi(op.substr(2));
            dq.insert(num);
        }
        else if (op == "D 1")
        {
            if (!dq.empty()) {
                auto it = prev(dq.end()); 
                dq.erase(it);
            }
        }
        else if (op == "D -1")
        {
            if (!dq.empty()) {
                auto it = dq.begin(); 
                dq.erase(it);
            }
        }
    
    }
    if (dq.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        answer.push_back(*prev(dq.end()));
        answer.push_back(*dq.begin());
    }
    
    
    return answer;
}