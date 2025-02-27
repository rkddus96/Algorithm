#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> wantIndex;
    vector<int> wantCount(want.size(), 0);
    //품목 인덱스 저장
    for (int i = 0; i < want.size(); i++)
    {
        wantIndex[want[i]] = i;
    }
    //10개 찾아보기
    for (int i = 0; i < 10; i++)
    {
        string item = discount[i];
        auto it = wantIndex.find(item);
        if (it != wantIndex.end())
        {
             wantCount[it->second]++;
        }
    }
    if (number == wantCount)
            answer++;
    //discount 순회
    for (int i = 10; i < discount.size(); i++)
    {
        //아이템 넣기
        string item = discount[i];
        auto it = wantIndex.find(item);
        if (it != wantIndex.end())
        {
             wantCount[it->second]++;
        }
        //뒤 아이템 빼기
        string popItem = discount[i-10];
        it = wantIndex.find(popItem);
        if (it != wantIndex.end() && wantCount[it->second] != 0)
        {
             wantCount[it->second]--;
        }
        // 같은지 확인
        if (number == wantCount)
            answer++;
    }
    
    
    
    return answer;
}