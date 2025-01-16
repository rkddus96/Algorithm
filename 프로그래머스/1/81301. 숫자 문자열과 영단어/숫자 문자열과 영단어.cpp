#include <string>
#include <vector>
#include <utility>

using namespace std;

vector<pair<string, int>> literalNumber = {
        {"ze", 3},
        {"on", 2},
        {"tw", 2},
        {"th", 4},
        {"fo", 3},
        {"fi", 3},
        {"si", 2},
        {"se", 4},
        {"ei", 4},
        {"ni", 3}
};

int solution(string s) {
    string stringNumber = "";
    int answer = 0;
    
    for (int i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i]))
        {
            stringNumber += s[i];
        }
        else
        {
            for(int j = 0; j < 10; j++)
            {
                if (s.substr(i, 2) == literalNumber[j].first)
                {
                    stringNumber += to_string(j);
                    i += literalNumber[j].second;
                    break;
                }
            }
        }
    }
    answer = stoi(stringNumber);
    return answer;
}