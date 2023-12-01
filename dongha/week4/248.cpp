#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
// 최대 노드 갯수는 100000개라고 가정 : 
// https://github.com/ndb796/python-for-coding-test/blob/master/9/1.cpp    
const int MAX_NODES = 100000;
// 무한을 설정하는 값으로 10억 설정
const int VAL_INF = 1e9; 
// 방문한 적이 있는지 체크하는 목적의 배열
// bool arrayVisited[MAX_NODES+1];
// 각 노드에 연결된 노드에 대한 정보를 담는 리스트의 배열
vector< pair<int, int> > listGraphs[MAX_NODES+1];
// 최단거리 테이블
int arrayDistance[MAX_NODES+1];
// N : 노드의 갯수, M : 간선의 갯수
int N, M;


// 정수 하나 입력받기용 함수
int getInt() { int tmpVal; cin >> tmpVal; return tmpVal; }

// 우선순위큐에서 요소를 오름차순으로 꺼내기 위한 cmp함수
// 이러면 우선순위큐 맨 위가 가장 cost가 작은 값이 된다.
struct customCmp {
    bool operator()(const pair<int, int> p0, const pair<int, int> p1) {
        return p0.first > p1.first;
    }
};

// 다익스트라
void dijkstra(const int ARG_START) {
    // 오름차순 우선순위 큐 (가장 위가 가장 낮은 값)
    priority_queue<pair<int, int>, vector<pair<int, int>>, customCmp> pq; 

    // 시작 노드 넣기
    pq.push({0, ARG_START});
    arrayDistance[ARG_START] = 0;

    //int cnt = 0;
    while(!pq.empty()) {
        //cnt++;
        pair<int, int> pr = pq.top();
        int cost{pr.first}, now{pr.second};
        pq.pop();                
        if(arrayDistance[now] < cost) {
            continue;
        }
        else {
            arrayDistance[now] = cost;
        }

        for(pair<int, int> node : listGraphs[now]) {
            // listGraphs의 요소 순서는 to, cost순서임
            pq.push({node.second+cost, node.first});
        }        
    }
    //cout << "count : " << cnt << '\n';
    // cnt : 12
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