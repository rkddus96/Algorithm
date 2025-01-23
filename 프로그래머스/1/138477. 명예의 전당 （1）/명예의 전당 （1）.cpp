#include <string>
#include <vector>

using namespace std;

void merge(vector<int> &arr, int low, int high)
{
    vector<int> temp = arr;
    int mid = (low + high) / 2;
    int i = low;
    int j = mid+1;
    int index = low;
    while (i<=mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            temp[index++] = arr[i++];
        }
        else
        {
            temp[index++] = arr[j++];
        }
    }
    
    while(i <= mid)
    {
        temp[index++] = arr[i++];
    }
    while(j <= high)
    {
        temp[index++] = arr[j++];
    }
    arr = temp;
    
    
}

void mergeSort(vector<int> &arr, int low, int high)
{
    if (low >= high) return; // 재귀 종료 조건 추가
    int mid = (low+high)/2;
    
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, high);    
    
    
}

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> temp;
    for (int number : score)
    {
        temp.push_back(number);
        int s = temp.size();
        
        mergeSort(temp, 0, s-1);
        if (s <= k)
        {
            answer.push_back(temp[0]);
        }
        else
        {
            answer.push_back(temp[s-k]);
        }
    }
    
    
    
    return answer;
}