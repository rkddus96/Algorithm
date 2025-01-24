#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    vector<int> dayCount = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<string> days = {"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"};
    int ret = 0;
    for (int i = 1; i < a; i++)
    {
        ret += dayCount[i];
    }
    ret += b;
    int r = ret % 7;
    answer = days[r];
    
    
    return answer;
}