#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <unordered_map>


using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    
    unordered_map<string, int> reportedCount;
    unordered_map<string, set<string>> reportRecord;
    unordered_map<string, set<string>> reportUserRecord;
    string reportingUser;
    string reportedUser;
    
    for (string reportCase : report)
    {
        istringstream iss(reportCase);
        iss >> reportingUser >> reportedUser;
        //이전에 신고가 있었는지 검사
        if (reportRecord[reportingUser].find(reportedUser) == reportRecord[reportingUser].end()) {
            reportRecord[reportingUser].insert(reportedUser);
            reportUserRecord[reportedUser].insert(reportingUser);
            reportedCount[reportedUser]++; // 신고 당한 유저의 카운트 증가
        }
    }
    
    map<string, int> userIndex;
    for (int i = 0; i < id_list.size(); i++)
    {
        userIndex[id_list[i]] = i;
    }
    
    
    for (auto [id , count] : reportedCount)
    {
        if (count >= k)
        {
            // 정지 고지하기
            for (string id : reportUserRecord[id])
            {
                answer[userIndex[id]]++;
            }
        }
    }
    
    
    
    return answer;
}