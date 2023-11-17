#include <iostream>
#include <vector>   // vector를 사용하기 위함
#include <queue>    // 큐 사용을 위함
using namespace std;

// * C++에서 전역변수영역인 .data .bss는 
// * 실행시 모든 영역이 0으로 초기화된다.
// graph를 입력받기 위한 vector들의 배열 (2차원 배열)
// graph는 무방향그래프
vector<int> graph[9];
// 방문했는지 아닌지 나타내는 그래프
bool visited[9];

void bfs() {
    queue<int> q;
    
    // 처음 노드 입력
    q.push(1);
    visited[1] = true;
    
    while(!q.empty()) {
        int now_idx = q.front(); 
        // stack은 top, queue는 front (back아님)
        q.pop();
        cout << now_idx << ' ';
        for(int to : graph[now_idx]) {
            if(visited[to] != true) {
                q.push(to);
                visited[to] = true;
            }
        }
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

    bfs();

    return 0;
}