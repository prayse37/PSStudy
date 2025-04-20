#include <vector>
using namespace std;

vector<vector<int>> answer;

void backtrack(int N, int sum, int start, vector<int>& path) {
    if (sum == 10) {
        answer.push_back(path);
        return;
    }

    for (int i = start; i <= N; i++) {
        if (sum + i > 10) continue;

        path.push_back(i);
        backtrack(N, sum + i, i + 1, path);
        path.pop_back();
    }
}

vector<vector<int>> solution(int N) {
    answer.clear();
    vector<int> path;
    backtrack(N, 0, 1, path);
    return answer;
}