#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string temp = "";
    vector<int> numbers;

    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == ' ')
        {
            numbers.push_back(stoi(temp));
            temp = "";
        }
        else
        {
            temp += s[i];
        }
    }
    numbers.push_back(stoi(temp));

    int min_val = numbers[0];
    int max_val = numbers[0];

    for(int i = 1; i < numbers.size(); i++)
    {
        if(numbers[i] < min_val)
        {
            min_val = numbers[i];
        }
        
        if(numbers[i] > max_val)
        {
            max_val = numbers[i];
        }
    }

    string answer = to_string(min_val) + " " + to_string(max_val);
    
    return answer;
}