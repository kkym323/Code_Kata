#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer(2);
    int mok;
    int na;
    int a = n;
    int b = m;
    int dae = 0;
    int yak = 0;
    while (b != 0)
    {
        mok = a / b;
        na = a % b;
        if (mok == 0)
        {
            int swap = 0;
            swap = a;
            a = b;
            b = swap;
            na = a % b;
            mok = a / b;
        }
        a = b;
        b = na;
    }
    dae = a;
    yak = n * m / a;
    answer[0] = dae;
    answer[1] = yak;
    return answer;
}