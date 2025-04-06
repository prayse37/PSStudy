#include <string>
#include <vector>

using namespace std;

int res = 0;
vector<vector<int>> g;

// https://school.programmers.co.kr/learn/courses/30/lessons/92343 양과 늑대

void dfs(int cur, int s, int w, vector<int> nexts, vector<int>& info) {
    if (info[cur] == 0) s++;
    else w++;

    if (w >= s) return;

    if (s > res) res = s;

    for (int i = 0; i < g[cur].size(); i++) {
        nexts.push_back(g[cur][i]);
    }

    for (int i = 0; i < nexts.size(); i++) {
        int next = nexts[i];

        vector<int> nnexts;
        for (int j = 0; j < nexts.size(); j++) {
            if (j != i) nnexts.push_back(nexts[j]);
        }

        dfs(next, s, w, nnexts, info);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int n = info.size();
    g.resize(n);

    for (int i = 0; i < edges.size(); i++) {
        int from = edges[i][0];
        int to = edges[i][1];
        g[from].push_back(to);
    }

    vector<int> nexts;
    dfs(0, 0, 0, nexts, info);

    return res;
}
