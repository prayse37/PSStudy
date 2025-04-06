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

vector<char> solution(vector<pair<char, char>> graph, char start) {
    for (auto &edge : graph) {
        char u = edge.first;
        char v = edge.second;
        adjList[u].push_back(v);
    }

    dfs(start);
    return result;
}