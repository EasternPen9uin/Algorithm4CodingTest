#include <iostream>
using namespace std;

int main(void) {
    // N : 행 갯수, M : 열 갯수
    int N, M;
    cin >> N >> M;
    
    // 정답 출력용 변수
    int answer{0};
    // 바깥 for문 : N번만큼 반복
    for(int i_n = 0; i_n<N; i_n++){
        // 줄 내 가장 작은 숫자 임시 저장용
        int smallest{ 999999 };
        // 안쪽 for문 : M번만큼 반복
        for(int i_m = 0; i_m<M; i_m++){
            int tmp_val; // 입력 저장용 임시변수
            cin >> tmp_val;
            if(tmp_val < smallest) {
                smallest = tmp_val;
            }
        }
        // 줄 내 가장 작은 숫자가 여태까지 나왔던 
        // 가장 큰 수(answer)보다 크면 answer 최신화
        if(smallest > answer){
            answer = smallest;
        }
    }

    // 답 출력
    cout << answer;

    return 0;
}