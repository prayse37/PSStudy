#include <string>
#include <vector>

using namespace std;

vector<int> res(11, 0);
int maxDiff = 0;

// https://school.programmers.co.kr/learn/courses/30/lessons/92342 양궁대회

int calc(vector<int>& a, vector<int>& cur) {
    int s1 = 0, s2 = 0;
    for (int i = 0; i <= 10; i++) {
        if (a[i] == 0 && cur[i] == 0) continue;
        if (cur[i] > a[i]) s1 += (10 - i);
        else s2 += (10 - i);
    }
    return s1 - s2;
}

void dfs(int n, vector<int>& a, vector<int>& cur, int i) {
    if (i == 11 || n == 0) {
        cur[10] += n;
        int diff = calc(a, cur);
        if (diff > maxDiff) {
            maxDiff = diff;
            res = cur;
        } else if (diff == maxDiff) {
            for (int j = 10; j >= 0; j--) {
                if (cur[j] > res[j]) {
                    res = cur;
                    break;
                } else if (cur[j] < res[j]) break;
            }
        }
        cur[10] -= n;
        return;
    }

    int need = a[i] + 1;
    if (n >= need) {
        cur[i] = need;
        dfs(n - need, a, cur, i + 1);
        cur[i] = 0;
    }

    dfs(n, a, cur, i + 1);
}

vector<int> solution(int n, vector<int> a) {
    vector<int> cur(11, 0);
    dfs(n, a, cur, 0);
    if (maxDiff <= 0) return {-1};
    return res;
}
