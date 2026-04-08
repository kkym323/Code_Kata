#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    bool isFirst = true;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            answer += ' ';
            isFirst = true;
        }
        else
        {
            if (isFirst)
            {
                answer += toupper(s[i]);
                isFirst = false;
            }
            else
            {
                answer += tolower(s[i]);
            }
        }
    }
    return answer;
}