#include <iostream>
#include <algorithm>
using namespace std;
/* 전역변수, 상수 */
// 회사 갯수의 최대
const int MAX_COMPANY_NUMBER = 100;
// 10억을 무한으로 사용
const int INF = 1e9;
// 플로이드 워셜용 2차원 테이블(인덱스0은 더미용)
int floydWarshallTable[MAX_COMPANY_NUMBER+1][MAX_COMPANY_NUMBER+1];


/* 함수 */
// 정수형 숫자 하나 입력받는 용도
int getInt(void) {
    int tmpVal;
    cin >> tmpVal;
    return tmpVal;
}

// 플로이드 워셜용 테이블을 무한 및 0으로 초기화
void initializeFloydWarshallTable(void) {
    // 모든 수를 INF로 초기화
    for(int y=1; y<=MAX_COMPANY_NUMBER; y++) {
        for(int x=1; x<=MAX_COMPANY_NUMBER; x++) {
            floydWarshallTable[y][x] = INF;
        }
    }
    // 자기 자신으로 향한 거리는 0
    for(int a=1; a<=MAX_COMPANY_NUMBER; a++) {
        floydWarshallTable[a][a] = 0;
    }   
}

int main(void) {
    // N, M 입력받기
    // N : 회사의 갯수([1,N]), M : (양방향) 경로의 갯수
    const int N{getInt()}, M{getInt()};

    // 플로이드 워셜 테이블 초기화
    initializeFloydWarshallTable();

    // M회만큼 연결 입력받기 (양방향)
    // ex) 1 3 : 1번과 3번 회사 간 거리는 1
    for(int i=0; i<M; i++) {
        const int val0{getInt()}, val1{getInt()};
        floydWarshallTable[val0][val1] = 1;
        floydWarshallTable[val1][val0] = 1;
    }

    // X, K 입력받기
    // X : K번 회사에서 이동하는 회사의 번호
    // K : 처음에 1번 회사에서 이동하는 회사의 번호
    const int X{getInt()}, K{getInt()};

    // 플로이드 워셜 진행
    for(int a=1; a<=MAX_COMPANY_NUMBER; a++) {
        for(int b=1; b<=MAX_COMPANY_NUMBER; b++) {
           for(int c=1; c<=MAX_COMPANY_NUMBER; c++) {
                floydWarshallTable[a][b] = min({
                    floydWarshallTable[a][b], 
                    floydWarshallTable[a][c] + floydWarshallTable[c][b]
                });
            }
        }
    }

    // 1번 -> K번 -> X번 회사로 이동하면서 걸린 최단 거리의 합을 출력  
    // 도달 불가능시 -1 출력
    const int TOTAL_COST = floydWarshallTable[1][K] + floydWarshallTable[K][X];
    const int ANSWER = (TOTAL_COST >= INF) ? -1 : TOTAL_COST;
    cout << ANSWER << '\n';
    return 0;
}