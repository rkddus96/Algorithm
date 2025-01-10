#include <string>
#include <vector>
#include <cmath>

using namespace std;

string ReverseTernary(int number)
{
    string s = "";
    int r;
    while (number > 0)
    {
        
        r = number % 3;
        number /= 3;
        
        s.push_back(r);
    }
    
    return s;
}

int TernaryToDecimal(string s)
{
    int decimalNumber = 0;
    for (int i = s.size()-1; i >= 0; i--)
    {
        
        int num = s[i];
        decimalNumber += num * pow(3, (s.size()-1) - i);
    }
    
    return decimalNumber;
}

int solution(int n) {
    int answer = 0;
    string tnumber = ReverseTernary(n);
    answer = TernaryToDecimal(tnumber);
    
    return answer;
}