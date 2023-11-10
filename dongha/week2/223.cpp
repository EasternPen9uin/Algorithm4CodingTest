#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    // N 최댓값
    const int N_MAX = 1000;
    // dp. 인덱스 0은 안 씀
    int dp[N_MAX+1] = {0,};
    // N 입력받기
    int N; cin >> N;
    
    // * 설명은 같이 첨부된 223.jpg 참고
    dp[1] = 1;
    dp[2] = 3;

    for(int i=3; i<N_MAX; i++) {
        dp[i] = ( (dp[i-2]*2) + dp[i-1] ) % 796796;
    }

    cout << dp[N];
    return 0;
}