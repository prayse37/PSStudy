#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> answer(2, 0);

    int xmax = board[0] / 2;
    int ymax = board[1] / 2;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    for (int i = 0; i < keyinput.size(); i++) {
        int dir;

        if (keyinput[i] == "left") dir = 0;
        else if (keyinput[i] == "right") dir = 1;
        else if (keyinput[i] == "up") dir = 2;
        else if (keyinput[i] == "down") dir = 3;

        int nx = answer[0] + dx[dir];
        int ny = answer[1] + dy[dir];

        if (nx >= -xmax && nx <= xmax && ny >= -ymax && ny <= ymax) {
            answer[0] = nx;
            answer[1] = ny;
        }
    }

    return answer;
}
