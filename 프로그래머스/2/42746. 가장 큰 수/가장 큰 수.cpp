#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string &a, string &b) {
    return a + b > b + a;
}


string solution(vector<int> numbers) {
    string answer = "";
    vector<string> stringNumbers(numbers.size());
    
    for (int i = 0; i < numbers.size(); i++)
    {
        stringNumbers[i] = to_string(numbers[i]);
    }
    
    sort(stringNumbers.begin(), stringNumbers.end(), compare);
    
    for (const string &s : stringNumbers)
    {
        answer += s;
    }
    
    if (answer[0] == '0') return "0";
    
    return answer;
}