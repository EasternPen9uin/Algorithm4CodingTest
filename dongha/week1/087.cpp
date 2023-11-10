#include <iostream>
using namespace std;

int main(void) {
    // 화폐 단위 종류들의 배열
    const int COIN[4]{500, 100, 50, 10};
    // 동전의 총 갯수
    int answer = 0;

    // 입력값 초기화 + 입력받기
    int n;
    cin >> n;

    for(int i=0; i<sizeof(COIN)/sizeof(int); i++) {
        // 몫과 나머지 한번에 구하기 위한 div_t구조체
        // 이러면 나누기연산 1번만에 몫과 나머지 한 번에 구함
        std::div_t q = std::div(n, COIN[i]);

        // 몫을 answer에 추가
        answer += q.quot;
        
        // 나머지는 n이 되어 다음 계산에 사용
        n = q.rem;
    }

    // 답 출력
    cout << answer;
    
    return 0;    
}