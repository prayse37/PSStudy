#include <string>
#include <vector>

using namespace std;

int answer = 0;

void backtrack(int k, vector<vector<int>>& dungeons, vector<bool>& visited, int count) {
    if (count > answer) answer = count;

    for (int i = 0; i < dungeons.size(); i++) {
        int need = dungeons[i][0];
        int use = dungeons[i][1];

        if (!visited[i] && k >= need) {
            visited[i] = true;
            backtrack(k - use, dungeons, visited, count + 1);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    vector<bool> visited(dungeons.size(), false);
    backtrack(k, dungeons, visited, 0);
    return answer;
}
