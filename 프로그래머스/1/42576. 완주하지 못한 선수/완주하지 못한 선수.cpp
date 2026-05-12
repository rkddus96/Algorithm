#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    int n = participant.size();
    unordered_map<string, int> CheckList;
    for (string &p : participant)
    {
        CheckList[p]++;
    }
    
    for (string &s : completion)
    {
        unordered_map<string, int>::iterator it = CheckList.find(s);
        
        it->second--;
    }
    
    for (auto& [name, count] : CheckList)
    {
        if (count > 0)
            return name;
    }
    
    return answer;
}

