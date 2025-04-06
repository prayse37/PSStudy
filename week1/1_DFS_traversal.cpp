#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

map<char, vector<char>> graph;
set<char> visited;
vector<char> result;
// 이 문제는 코딩테스트  합격자 되기 C++ 교제의 문제 36 깊이우선탐색순회 구현문제

void dfs(char node) {
    visited.insert(node);
    result.push_back(node);

    for (int i = 0; i < graph[node].size(); i++) {
        char next = graph[node][i];

        if (visited.count(next) == 0) {
            dfs(next);
        }
    }
}

vector<char> solution(vector<pair<char, char>> edges, char start) {
    for (int i = 0; i < edges.size(); i++) {
        char from = edges[i].first;
        char to = edges[i].second;
        graph[from].push_back(to);
    }

    dfs(start);
    
    return result;
}
