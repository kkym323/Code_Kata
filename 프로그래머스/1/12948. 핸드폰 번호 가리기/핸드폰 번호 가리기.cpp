#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    int num = phone_number.length();
    for(int i = 0; i < num - 4; i++)
    {
        phone_number[i] = '*';
    }
    return phone_number;
}