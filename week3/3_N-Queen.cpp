#include <string>
#include <vector>

using namespace std;

int answer = 0;

void backtrack(int row, int n, vector<int>& col) {
    if (row == n) {
        answer++;
        return;
    }

    for (int i = 0; i < n; i++) {
        bool canPlace = true;
        for (int j = 0; j < row; j++) {
            if (col[j] == i || abs(col[j] - i) == row - j) {
                canPlace = false;
                break;
            }
        }

        if (canPlace) {
            col[row] = i;
            backtrack(row + 1, n, col);
        }
    }
}

int solution(int n) {
    answer = 0;
    vector<int> col(n, 0);
    backtrack(0, n, col);
    return answer;
}
