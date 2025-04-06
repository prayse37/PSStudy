#include <string>
#include <vector>

using namespace std;

void dfs(int n, vector<vector<int>>& c, vector<bool>& v) {
    v[n] = true;
    for (int i = 0; i < c.size(); ++i) {
        if (c[n][i] == 1 && !v[i]) {
            dfs(i, c, v);
        }
    }
}

int solution(int n, vector<vector<int>> c) {
    int ans = 0;
    vector<bool> v(n, false);
    for (int i = 0; i < n; ++i) {
        if (!v[i]) {
            dfs(i, c, v);
            ans++;
        }
    }
    return ans;
}