#include <string>
#include <vector>
using namespace std;

vector<int> solution(string s) {
    int count = 0;
    int removed = 0;

    while (s != "1") {
        int zeros = 0;
        string next = "";

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') next += '1';
            else zeros++;
        }

        removed += zeros;
        count++;

        int len = next.size();
        s = "";
        while (len > 0) {
            s = (char)(len % 2 + '0') + s;
            len /= 2;
        }
    }

    return {count, removed};
}
