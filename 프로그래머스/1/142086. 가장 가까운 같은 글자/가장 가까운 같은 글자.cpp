#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<int> alphabet(26, -1);
    for (char c : s)
    {
        if ( alphabet[c - 'a'] == -1)
        {
            alphabet[c - 'a'] = 0;
            answer.push_back(-1);
        }
        else
        {
            answer.push_back(alphabet[c - 'a']);
            alphabet[c - 'a'] = 0;
        }
        
        for (int &a : alphabet)
        {
            if (a != -1)
            {
                a++;
            }
        }
        
    }
    
    
    
    return answer;
}