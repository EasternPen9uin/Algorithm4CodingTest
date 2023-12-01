#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

/* 전역변수, 상수 */
const int INF = 1e9;            // 무한
const int MAX_CITYS = 30000;   // 도시의 최대 개수

// 연결 정보 입력용 테이블 (인덱스 0은 더미)
// pair<int, int>에서 first는 향하는 도시, second는 거리
// nodeTable[FROM]에서 FROM이 출발하는 도시
vector<pair<int, int>> nodeTable[MAX_CITYS+1];

// 최단거리 입력용 테이블 (인덱스 0은 더미)
int distanceArray[MAX_CITYS+1];

/* 함수 */

// 우선순위큐에서 요소를 오름차순으로 꺼내기 위한 cmp함수
// 이러면 우선순위큐 맨 위가 가장 cost가 작은 값이 된다.
struct customCmp {
    bool operator()(const pair<int, int> p0, const pair<int, int> p1) {
        return p0.second > p1.second;
    }
};

// 정수 하나 입력받기
int getInt(void) {
    int tmpVal; cin >> tmpVal; return tmpVal;
}

// 최단거리 입력용 테이블 초기화
void initializeDistanceArray(void) {
    for(int i=0; i <= MAX_CITYS; i++) {
        distanceArray[i] = INF;
    }
}

// 다익스트라
void dijkstra(const int ARG_START) {
    // 오름차순 우선순위 큐 (가장 위가 가장 낮은 값)
    // pair<int, int>에서 first가 도시, second가 cost
    priority_queue<pair<int, int>, vector<pair<int, int>>, customCmp> pq; 

    // 시작 노드 넣기 (자기 자신으로 향하는 cost는 0)
    pq.push({ARG_START, 0});
    distanceArray[ARG_START] = 0;

    while(!pq.empty()) {
        // pair<int, int>에서 first가 도시, second가 cost
        const int NOW_CITY{pq.top().first}, COST{pq.top().second};
        pq.pop();

        // 큐에서 뽑은 거리가 최신화되지 않은 거리라면, 작업 건너뜀
        if(distanceArray[NOW_CITY] < COST) {
            continue;
        }

        // 현재 노드에서 이동 가능한 모든 간선 검토
        // nodeTable의 pair순서는 to, cost 순서
        for(pair<int, int> node : nodeTable[NOW_CITY]) {
            // 현재 노드(NOW_CITY)에서 이동할 수 있는 도시
            const int TO{node.first};
            // 현재 노드(NOW_CITY)에서 이동했을 때 거리 (최신화 여부는 불명)
            const int NEW_COST{node.second+COST};
            // 새로운 거리로 최신화 가능하면 최신화하고, 큐에 넣음
            if(NEW_COST < distanceArray[TO]) {
                distanceArray[TO] = NEW_COST;
                pq.push({TO, NEW_COST});
            }
        }
    }

}

int main(void) {
    /* N, M, C 입력받기 */
    // N : 도시의 갯수, M : 통로의 갯수, C : 출발 도시
    const int N{getInt()}, M{getInt()}, C{getInt()};

    // 최단거리 테이블 초기화
    initializeDistanceArray();

    /* M번에 걸쳐 간선 정보 입력받기 */
    for(int i=0; i<M; i++) {
        // X, Y, Z 입력받음
        // X : 출발도시, Y : 도착도시, Z : X->Y로의 cost
        const int FROM{getInt()}, TO{getInt()}, COST{getInt()};
        nodeTable[FROM].push_back({TO, COST});
    }

    /* 다익스트라 알고리즘 실행 */
    dijkstra(C);

    /* C에서 보낸 메시지를 받는 도시의 총 갯수와, 총 걸리는 시간을 출력 */
    int cityCounts{0}, maxCost{0}; 
    for(int i=1; i<=N; i++) {
        // 거리가 INF이상이라면 메시지 못받는다는 뜻
        if(distanceArray[i] < INF) {
            cityCounts++;
            maxCost = max({maxCost, distanceArray[i]});
        }
    }
    // 자기 자신도 계산에 포함되었으므로 뺌
    cityCounts--;
    maxCost -= distanceArray[C];
    
    // 출력
    cout << cityCounts << ' ' << maxCost << '\n';

    return 0;
}