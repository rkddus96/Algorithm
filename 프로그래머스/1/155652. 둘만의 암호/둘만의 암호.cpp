#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    vector<bool> skipAlphabets(26, false);
    for (char c : skip)
    {
        skipAlphabets[c-'a'] = true;
    }
    
    for (char c : s)
    {
        int shiftCount = 0;
        int stringIndex = c-'a';
        while (shiftCount < index)
        {
            stringIndex = (stringIndex+1)%26;
            if (skipAlphabets[stringIndex])
            {
                continue;
            }
            shiftCount++;
        }
        answer += stringIndex + 'a'; 
        
    }
    return answer;
}