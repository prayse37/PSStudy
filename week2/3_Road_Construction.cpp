#include <string>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int x, y, cost, dir;
};

int solution(vector<vector<int>> board) {
    int n = board.size();
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    vector<vector<vector<int>>> cost(n, vector<vector<int>>(n, vector<int>(4, 1e9)));
    queue<Node> q;

    for (int i = 0; i < 4; i++) {
        cost[0][0][i] = 0;
        q.push({0, 0, 0, i});
    }

    while (!q.empty()) {
        Node cur = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < n && ny < n && board[nx][ny] == 0) {
                int newCost = cur.cost + (cur.dir == i ? 100 : 600);
                if (cost[nx][ny][i] > newCost) {
                    cost[nx][ny][i] = newCost;
                    q.push({nx, ny, newCost, i});
                }
            }
        }
    }

    int answer = cost[n - 1][n - 1][0];
    for (int i = 1; i < 4; i++) {
        if (cost[n - 1][n - 1][i] < answer) {
            answer = cost[n - 1][n - 1][i];
        }
    }

    return answer;
}
