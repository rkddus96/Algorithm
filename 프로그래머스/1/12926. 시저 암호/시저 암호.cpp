#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            answer += ' ';
        }    
        else if (int(s[i]) <= 90)
        {
            answer  +=  'A' +  (s[i] - 'A' + n) % 26;
        }
        else
        {
            answer  +=  'a' +  (s[i] - 'a' + n) % 26;
        }
    }
    
    return answer;
}