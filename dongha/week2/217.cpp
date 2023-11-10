#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    const int X_MAX = 30000;
    // dp 메모이제이션용 테이블
    // dp[x]의 값은, 정수 x에서 시작해서 1로 가는 최소 연산
    int* dp = new int[X_MAX+1]; 
    // 인덱스는 0부터 30000까지
    // 0은 안 씀

    //dp[1]은 확실하게 0
    dp[1] = 0; 

    // 인덱스 2부터 30000까지 진행 (바텀업)
    for(int i=2; i<=X_MAX; i++) {
        // 갈 수 있는 이전dp의 최소값을 담기 위한 임시변수
        int min_prev_val = X_MAX;
        if(i%5==0) {
            min_prev_val = min(min_prev_val, dp[i/5]);
        }
        if(i%3==0) {
            min_prev_val = min(min_prev_val, dp[i/3]);
        }
        if(i%2==0) {
            min_prev_val = min(min_prev_val, dp[i/2]);
        }
        min_prev_val = min(min_prev_val, dp[i-1]);
        dp[i] = min_prev_val+1;
    }

    // 입력 받기
    int x;
    std::cin >> x;
    std::cout << dp[x];
    
    // 메모리 해제함
    delete[] dp;
    return 0;
}