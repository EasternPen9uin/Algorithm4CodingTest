#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    // N : 입력으로 주어질 숫자의 갯수
    // M : 더하는 총 횟수
    // K : 같은 인덱스 연속으로 더할 수 있는 최대 뭐시기
    // N, M, K 입력받기
    int N, M, K;
    cin >> N >> M >> K;
    

    // N만큼의 크기만큼 int배열 동적할당하여 생성
    int* numbers_array = new int[N];
    // 입력받기
    for(int i=0; i<N; i++) {
        cin >> numbers_array[i];
    }

    // 정렬
    stable_sort(numbers_array, numbers_array+N);

    // numbers_array[n-1]이 가장 큰 거,
    // numbers_array[n-2]가 그 다음 큰 거
    const int FMV = numbers_array[N-1];
    const int SMV = numbers_array[N-2];
    
    // 정답 출력용 변수 초기화
    int answer{0};

    /*
    // 첫번째 시도했던 바보 코드
    // 일단 가장 큰 숫자 한 번 더하기 (1번째)
    answer += FMV;
    //2부터 M(포함해서) 세기 [2,M]
    for(int i=2; i<=M; i++) {
        // 지금이 K*n(n:임의의자연수)번째가 아니면 FMV를 더함
        // 그거 아니면 SMV더함
        answer += i%K != 0 ? FMV : SMV;
    }
    */

    // 책 내용 보고 수정
    // 책에서는 첫번쨰 큰 수를 더하는 횟수를 먼저 구했으나,
    // 두번쨰 더하는 큰 수를 구하는게 더 간단명료할듯? 답은 얼추 맞는데 이거 맞나?
    // 더하는 두번째 큰 수 갯수 : M // (K+1)
    // 더하는 첫번째 큰 수 갯수 : M - (M // (K+1))
    const int SMV_MULTIPLIER = M / (K+1);
    const int FMV_MULTIPLIER = M - SMV_MULTIPLIER;
    answer = (FMV * FMV_MULTIPLIER) + (SMV * SMV_MULTIPLIER);

   // 답안 출력
    std::cout << answer;
    
    // 동적으로 생성한 배열 해제
    delete[] numbers_array;
    return 0;
}