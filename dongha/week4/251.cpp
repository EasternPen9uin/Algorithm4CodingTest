#include <iostream>
#include <algorithm>
using namespace std;

// * 상수, 전역변수
// 무한의 값으로 10억 사용
const int INF = 1e9;
// 노드의 개수는 최대 500개라고 가정 
// (https://github.com/ndb796/python-for-coding-test/blob/master/9/3.cpp)
const int MAX_NODES = 500;
//2차원 배열 만들기(인덱스 0은 더미인덱스)
int graph[MAX_NODES+1][MAX_NODES+1];

// * 함수
// 정수 하나 입력받기용 함수
int getInt(void) { int tmpVal; cin >> tmpVal; return tmpVal; }
// 그래프 초기화
void initailzeGraph(void) {
    // 전체를 무한으로 초기화
    for(int y=1; y<=MAX_NODES; y++) {
        for(int x=1; x<=MAX_NODES; x++) {
            graph[y][x] = INF;
        }
    }
    // 자기 자신에서 자기 자신으로 가는 비용은 0
    for(int a=1; a<=MAX_NODES; a++) {
        graph[a][a] = 0;
    }
}

// main
int main(void) {
    // N(노드 갯수), M(간선의 갯수) 입력받기
    const int N{getInt()}, M{getInt()};

    // 2차원배열 초기화시킴
    initailzeGraph();

    // 간선 정보 입력받기
    // 1 2 4 : 1에서 2로 가는데 드는 비용이 4
    for(int i=0; i<M; i++) {
        graph[getInt()][getInt()] = getInt();
    }

    // 플로이드 워셜 진행
    // D_ab := min(D_ab, D_ac+D_cb)
    for(int a=1; a<=N; a++) {
        for(int b=1; b<=N; b++) {
            for(int c=1; c<=N; c++) {
                graph[a][b] = min({graph[a][b], graph[a][c]+graph[c][b]});
            }
        }    
    }

    for(int y=1; y<=N; y++){
        for(int x=1; x<=N; x++){
            if(graph[y][x] >= INF) {
                cout << "INFINITY" << ' ';
            }
            else {
                cout << graph[y][x] << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}