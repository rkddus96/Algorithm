#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<char, int> term;
    int year, month, day;
    
    sscanf(today.c_str(), "%d.%d.%d", &year, &month, &day);
    
    for (string t : terms)
    {
        char k;
        int m;
        sscanf(t.c_str(), "%s %d", &k, &m);
        term[k] = m;
    }
    
    int index = 1;
    for (string s : privacies)
    {
        int y, m, d;
        char k;
        sscanf(s.c_str(), "%d.%d.%d %s", &y, &m, &d, &k);
        int t = term[k];
        m += t;
        if (m > 12)
        {
            int r = (m-1) / 12;
            m = (m-1)%12 + 1;
            y += r;
        }

        
        if (y < year || (y==year && m < month) || (y==year && m == month && d <= day) )
        {
            answer.push_back(index);
        }
        index++;
    }
    
    
    return answer;
}