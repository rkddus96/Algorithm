#include <iostream>
#include <cmath>

using namespace std;

int countDivisors(int number)
{
    int count = 0;
    for (int i = 1; i<= number; i++)
    {
        if (number % i == 0)
        {
                count += 1;
        }
    }
    
    return count;
}

int solution(int left, int right) {
    int answer = 0;
    for (int i = left; i <= right; i++)
    {
        if (countDivisors(i) %2 == 0)
        {
            answer += i;
        }
        else
        {
            answer -= i;
        }
    }
    
    
    return answer;
}