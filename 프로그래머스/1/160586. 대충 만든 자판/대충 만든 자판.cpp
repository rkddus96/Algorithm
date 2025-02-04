#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    vector<int> alphabets(26, 101);
    for (string ks : keymap)
    {
        for (int i = 0; i < ks.size(); i++)
        {
            if (i+1 < alphabets[ks[i] - 'A'])
                alphabets[ks[i] - 'A'] = i+1;
        }
    }
    
    for (string ts : targets)
    {
        int result = 0;
        for (char tc : ts)
        {
            if (alphabets[tc-'A'] == 101)
            {
                result = -1;
                break;
            }
            else
            {
                result += alphabets[tc-'A'];
            }
        }
        answer.push_back(result);
    }
    
    
    return answer;
}