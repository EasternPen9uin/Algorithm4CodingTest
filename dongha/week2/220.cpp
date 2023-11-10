#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {

    // 가능한 n의 최댓값
    const int N_MAX = 100;

    // * dp[k]:
    // * 식량 창고가 k칸까지만 존재한다고 가정했을 때,
    // * 해당 식량창고에서 구할 수 있는 최대한 많은 식량의 양 
    int dp[N_MAX+1] = {0,};
    // * storage[k]:
    // * 식량 창고의 k번쨰 칸에 있는 식량의 양
    int storage[N_MAX+1] = {0,};

    //printf("dps:%d,%d,%d,%d\n", dp[0], dp[2], dp[3], dp[4]);
    //printf("storages:%d,%d,%d,%d\n", storage[0], storage[2], storage[3], storage[4]);

    // N, K 입력받기
    int N; 
    std::cin >> N;
    for(int i=1; i<=N; i++) {
        int tmp_food; 
        std::cin >> tmp_food;
        storage[i] = tmp_food;
    }

    // 아무 칸도 없는 식량창고에서 식량을 구할 수는 없다.
    // dp[0] = 0;
    // 하지만 이미 위에서 배열 초기화할 때 문법으로 인해 이미 0이라 생략
    
    // 1칸만 있는 식량창고에서 가장 많이 터는 방법 : 그 칸을 턴다.
    dp[1] = storage[1];

    // 규칙:
    // dp[k] = max(dp[k-1], dp[k-2]+storage[k])
    for(int k=2; k<=N; k++) {
        dp[k] = max(dp[k-1], dp[k-2]+storage[k]);
    }
    // 했던 바보짓:
    // k를 1부터 넣어서 dp가 배열 이전의 초기화가 안 된 메모리를 가리켜서 괴값이 출력됨

    std::cout << dp[N];
    return 0;
}