#include <iostream>
using namespace std;

// * 전역변수 모음
// 입력받을 세로와 가로
int N, M;
// 얼음틀
int iceMap[1000][1000];

// 인덱스 검증용
bool isThisIndexValid(int y, int x) {
    return ((0 <= x) && (x < M) && (0 <= y) && (y < N));
}

// dfs 함수
int dfs(int y, int x) {
    // 이미 방문한 곳이면 0
    if(iceMap[y][x] == 1) {
        return 0;
    }
    // 방문처리
    iceMap[y][x] = 1;
    
    // 상하좌우의 인덱스가 갈 수 있는 인덱스면 거기로 퍼져나감 
    if(isThisIndexValid(y+1, x)) {
        dfs(y+1, x);
    }
    if(isThisIndexValid(y, x+1)) {
        dfs(y, x+1);
    }
    if(isThisIndexValid(y-1, x)) {
        dfs(y-1, x);
    }
    if(isThisIndexValid(y, x-1)) {
        dfs(y, x-1);
    }

    // 정답 더하기용 1 반환
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
            answer += dfs(y,x);
        }
    }

    cout << answer;

    return 0;
}