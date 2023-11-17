#include <iostream>
#include <queue>
using namespace std;
// * 전역변수 모음
// 입력받을 세로와 가로
int N, M;
// 얼음틀
int iceMap[1000][1000];

// bfs 큐에 넣을 구조체 정의
struct Edge {
    int y, x;
    Edge(int arg_y, int arg_x) {
        y = arg_y;
        x = arg_x; 
    }
};

// 인덱스 검증용
bool isThisIndexValid(int y, int x) {
    return ((0 <= x) && (x < M) && (0 <= y) && (y < N));
}

// bfs함수
int bfs(int yStart, int xStart) {
    // bfs함수를 처음부터 끝까지 매길 때, 이미 채워진 칸이면 0 더해지게 만듦
    if(iceMap[yStart][xStart] == 1) {
        return 0;
    }

    // 큐
    queue<Edge> q;

    // yStart,xStart에서 시작
    q.push(Edge(yStart,xStart));

    while(!q.empty()) {
        Edge edg = q.front(); q.pop();
        int x = edg.x;
        int y = edg.y;
        if(!isThisIndexValid(y, x) || iceMap[y][x] == 1) {
            continue;
        }
        iceMap[y][x] = 1;
        q.push(Edge(y+1, x));
        q.push(Edge(y-1, x));
        q.push(Edge(y, x+1));
        q.push(Edge(y, x-1));
    }

    // 정답용 1 반환
    return 1;
}


int main(void) {
    // N(세로)과 M(가로) 입력받음    
    cin >> N >> M;

    // 얼음틀 입력받음
    // https://foxtrotin.tistory.com/445 코드 참고함
    for(int n=0; n<N; n++) {
        string line;
        cin >> line;
        for(int m=0; m<M; m++) {
            iceMap[n][m] = line[m] - '0';
        }
    }

    // 정답
    int answer = 0;
    
    for(int y=0; y < N; y++) {
        for(int x=0; x < M; x++) {
            answer += bfs(y,x);
        }
    }

    cout << answer;
    return 0;
}