#include <iostream>
#include <vector>   // vector를 사용하기 위함
using namespace std;

// * C++에서 전역변수영역인 .data .bss는 
// * 실행시 모든 영역이 0으로 초기화된다.
// graph를 입력받기 위한 vector들의 배열 (2차원 배열)
// graph는 무방향그래프
vector<int> graph[9];
// 방문했는지 아닌지 나타내는 그래프
bool        visited[9];

void dfs(int idx) {
    visited[idx] = true;
    cout << idx << " ";
    // 현재 노드와 연결된 다른 노드를 재귀적으로 방문
    for (int i = 0; i < graph[idx].size(); i++) {
        int y = graph[idx][i];
        if (!visited[y]) dfs(y);
    }
}

int main(void) {
    // graph에 입력
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(8);

    graph[2].push_back(1);
    graph[2].push_back(7);

    graph[3].push_back(1);
    graph[3].push_back(4);
    graph[3].push_back(5);
    
    graph[4].push_back(3);
    graph[4].push_back(5);

    graph[5].push_back(3);
    graph[5].push_back(4);
    
    graph[6].push_back(7);
    
    graph[7].push_back(2);
    graph[7].push_back(6);
    graph[7].push_back(8);

    graph[8].push_back(1);
    graph[8].push_back(7);

    dfs(1);
    return 0;
}