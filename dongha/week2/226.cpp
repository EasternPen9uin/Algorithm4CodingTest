#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    // 가치의 합(M)의 최댓값
    const int M_MAX = 10000;
    // 화폐 종류의 최댓값
    const int N_MAX = 100;
    // 무한(이거 이상이면 -1출력)
    const int INF = 9999999;
    // dp[M] : M을 만들기 위해 필요한 최소한의 화폐 개수.
    // 0~M_MAX만큼 배열 선언 및 정의
    int dp[M_MAX+1] = { 0, };
    // N : 화폐의 종류 수
    int N; cin >> N;
    // 만들어야 하는 가치의 합
    int M; cin >> M;
    // 화폐 종류의 배열
    int CURRENCIES[N_MAX+1] = { 0, };
    // 화폐 종류 입력받기
    for(int i=0; i<N; i++){
        int tmp_val; cin >> tmp_val;
        CURRENCIES[i] = tmp_val;
    }


    // 0을 만들기 위한 화폐의 개수는 0
    // dp[0] = 0;
    // 하지만 C++ 배열 초기화 문법때문에 이미 0 들어갔으므로 생략

    // 일단 1부터 M_MAX까지의 모든 화폐가치를 달성 불가능하다고 판단
    for(int i=1; i<=M_MAX; i++) {
        dp[i] = INF;
    }
    // 바보짓 했던거 : 저거 i=1이라 적어야 하는데 i=0이라 적어서 버그났었음

    // 그 후, 1부터 M까지 올라가면서, DP진행
    for(int i=1; i<=M; i++) {
        // dp에 더할 이전 dp요소의 최솟값
        int tmp_min_val = INF;
        // 화폐종류별로 한번씩 검토 
        for(int k=0; k<N; k++) {
            // i가 화폐의 값보다 크다면 이전dp에서 점프 가능
            if(i>=CURRENCIES[k]) {
                tmp_min_val = min(tmp_min_val, dp[i-CURRENCIES[k]]);
                // 불가능하면 큰거 선택하나 작은거 선택하나 INF이상의 값이 들어감
            }
        }
        // 검토 다 끝나면 선택된 이전 dp값에서 1추가
        dp[i] = tmp_min_val + 1;
    }

    // 달성 불가능이면 -1, 아니면 값 그대로 뽑기
    // INF 이상의 값이 들어갈 수도 있어서 조건 저래 처리함
    cout << (dp[M] >= INF ? -1 : dp[M]);
    return 0;
}