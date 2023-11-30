#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 최대 노드 갯수는 100000개라고 가정 : 
// https://github.com/ndb796/python-for-coding-test/blob/master/9/1.cpp    
const int MAX_NODES = 100000;
// 무한을 설정하는 값으로 10억 설정
const int VAL_INF = 1e9; 
// 방문한 적이 있는지 체크하는 목적의 배열
bool arrayVisited[MAX_NODES+1];
// 각 노드에 연결된 노드에 대한 정보를 담는 리스트의 배열
vector< pair<int, int> > listGraphs[MAX_NODES+1];
// 최단거리 테이블
int arrayDistance[MAX_NODES+1];
// N : 노드의 갯수, M : 간선의 갯수
int N, M;


// 정수 하나 입력받기용 함수
int getInt() { int tmpVal; cin >> tmpVal; return tmpVal; }

// 현재 최단 거리가 가장 짧은 노드를 꺼내어 방문 처리함
int getSmallestNode() {
    int minValue = VAL_INF;
    int idx = 0; // 가장 최단 거리가 짧은 노드의 인덱스
    for(int i=1; i < N+1; i++) {
        bool condition =\
            (minValue > arrayDistance[i]) && (!arrayVisited[i]);
        if (condition) {
            minValue = arrayDistance[i];
            idx = i;
        }
    }
    return idx;
}

// 다익스트라
void dijkstra(const int ARG_START) {
    // 시작 노드 초기화
    arrayDistance[ARG_START] = 0;
    arrayVisited[ARG_START] = true;
    // 시작 노드에 연결된 각 간선들 정보 입력
    for(pair<int, int> objPair : listGraphs[ARG_START]) {
        const int to{objPair.first}, cost{objPair.second};
        arrayDistance[to] = cost;
    }
    // 시작 노드 제외 전체 n-1개 노드에 대해 반복
    for(int i=0; i < N-1; i++) {
        const int nowIdx = getSmallestNode();
        arrayVisited[nowIdx] = true;
        // 현재 노드와 연결된 타 노드 확인
        // cost가 더 적은 값으로 변경 가능하면 변경
        for(pair<int, int> objPair : listGraphs[nowIdx]) {
            const int new_cost = arrayDistance[nowIdx] + objPair.second;
            arrayDistance[objPair.first] = min({new_cost, arrayDistance[objPair.first]});
        }
    }
}

int main() {
    // 노드 갯수, 간선 갯수 입력받기
    N = getInt();
    M = getInt();
    
    // 시작 노드 번호 입력받기
    const int VAL_START = getInt();
    
    // 최단거리 테이블 내 모든 값을 INF로 초기화
    for(int i=1; i<MAX_NODES+1; i++) {
        arrayDistance[i] = VAL_INF;
    }

    // 간선 정보 입력받기
    for(int i=0; i < M; i++) {
        const int from{getInt()}, to{getInt()}, cost{getInt()};
        listGraphs[from].push_back({to, cost});
    }

    // 다익스트라 알고리즘 수행
    dijkstra(VAL_START);

    // 모든 노드로 가기 위한 최단거리 출력
    for(int i=1; i < N+1; i++) {
        if(arrayDistance[i] == VAL_INF) {
            cout << "INFINITY";
        }
        else {
            cout << arrayDistance[i];
        }
        cout << "\n";
    }
    return 0;
}