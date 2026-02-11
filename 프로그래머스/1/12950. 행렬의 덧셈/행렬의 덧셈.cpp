#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int hang = arr1.size();
    int yul = arr1[0].size();
    vector<vector<int>> answer(hang, vector<int>(yul));
    for(int i = 0; i < hang; i++)
    {
        for(int j = 0; j < yul; j++)
        {
            answer[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
    return answer;
}