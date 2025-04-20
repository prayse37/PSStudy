#include <vector>
using namespace std;

vector<vector<int>> answer;

void backtrack(int N, int sum, int start, vector<int>& path) {
    if (sum == 10) {
        answer.push_back(path); // 정답 저장
        return;
    }

    for (int i = start; i <= N; i++) {
        if (sum + i > 10) continue; // 가지치기: 10 넘으면 스킵

        path.push_back(i);           // 선택
        backtrack(N, sum + i, i + 1, path); // 다음 숫자로 이동 (중복 방지)
        path.pop_back();             // 되돌리기 (백트래킹 핵심)
    }
}

vector<vector<int>> solution(int N) {
    answer.clear();
    vector<int> path;
    backtrack(N, 0, 1, path);
    return answer;
}