#include <iostream>
#include <queue>
using namespace std;

// * 전역변수
int N, M; // N : row, M : col
// 미로
int maze[200][200];

// * 구조체 정의
struct Edge {
    int y, x, cost;
    Edge(int arg_y, int arg_x, int arg_cost) {
        y = arg_y;
        x = arg_x;
        cost = arg_cost; 
    }
};

// * 함수 정의
int main(void) {
    // N, M 입력받기
    cin >> N >> M;

    // 미로 입력받기
    for(int n=0; n<N; n++) {
        string line;
        cin >> line;
        for(int m=0; m<M; m++) {
            maze[n][m] = line[m] - '0';
        }
    }

    // 큐
    queue<Edge> q;
    // 맨 처음에는 좌측 상단에서 시작
    // 첫 지점 cost는 1
    q.push(Edge(0,0,1));

    // bfs 진행
    while(!q.empty()) {
        Edge edg = q.front(); q.pop();
        int x = edg.x;
        int y = edg.y;
        int cost = edg.cost;
        // 미로 바깥으로 이탈시 함수 실행X
        // 이미 지나간 곳이여도 실행X
        if(!(x >= 0 && x < M && y >= 0 && y < N) || maze[y][x] != 1) {
            continue;
        }
        maze[y][x] = cost;

        q.push(Edge(x-1, y, cost+1));
        q.push(Edge(x, y-1, cost+1));
        q.push(Edge(x+1, y, cost+1));
        q.push(Edge(x, y+1, cost+1));
    }

    // 시작지점 cost가 변경되었을 경우를 상정
    maze[0][0] = 1;

    // 목적지 cost가 1이라면 도달 불능이라 -1 출력
    // 아니라면 cost 그대로 출력
    cout << ( (maze[N-1][M-1] != 1) ? maze[N-1][M-1] : -1 ); 
    return 0;
}