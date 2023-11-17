#include <iostream>
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
void dfs(int y, int x, int cost) {
    // 미로 바깥으로 이탈시 함수 실행X
    // 이미 지나온 곳이여도 실행X
    if(!(0<=x && x<M && 0<=y && y<M) || maze[y][x] != 1) {
        return;
    }
    maze[y][x] = cost;
    dfs(y, x+1, cost+1);
    dfs(y+1, x, cost+1);
    dfs(y-1, x, cost+1);
    dfs(y, x-1, cost+1);
    
}

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

    // 과연 dfs에서도 동일한 답이 나올까?
    dfs(0,0,1);

    // 시작지점 cost가 변경되었을 경우를 상정
    maze[0][0] = 1;

    // 목적지 cost가 1이라면 도달 불능이라 -1 출력
    // 아니라면 cost 그대로 출력
    cout << ( (maze[N-1][M-1] != 1) ? maze[N-1][M-1] : -1 ); 
    return 0;
}

/*
이 문제는 dfs로 풀면 틀린다. 반례(dfs가 오른쪽->아래순으로 우선순위가 잡혔다고 가정할 시):
4 4
1111
1111
1110
1111
*/