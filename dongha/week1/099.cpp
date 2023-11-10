#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int tN, tK;
    cin >> tN >> tK;
    const int N{tN}, K{tK};

    // 정답 저장용 변수
    int answer{0};
    
    // N값 대신 줄일 용도로 쓰는 변수
    int n{N};

    while(n > K){
        // 몫과 나머지 한 번에 구하기 위한 div_t구조체
        std::div_t q = std::div(n, K);
        // 안 나눠지면
        if(q.rem != 0) {
            n -= q.rem;         // n에서 나머지만큼 빼기(나머지 횟수만큼 1 차감)
            answer += q.rem;    // 나머지 횟수만큼 1씩 뺐으므로 answer도 그만큼 증가
        }
        // 나눠지면
        else {
            n = q.quot;         // 몫을 n으로
            answer++;           // answer 1만큼 증가
        }
    }
    answer += (n-1);
    
    // 정답 출력
    cout << answer;

    return 0;
}