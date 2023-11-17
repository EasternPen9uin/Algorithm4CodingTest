#include <iostream>
#include <algorithm>  //min, max함수 쓰기 위함
using namespace std;

// * 전역변수
// 금광 정보 저장할 배열(1<=가로,세로<=20)
// 양 끝 행은 더미행이므로, 그거 감안해서 +2씩 해야함
int goldMine[20+2][20];
// dp테이블
int dp[20+2][20];


// * 함수
// dp테이블 초기화
void clearDP() {
    // https://velog.io/@pikamon/CC-3 
    // 위 글 참고해서 memset 안 쓰고 걍 for문 돌림
    for(int y=0; y<20+2; y++)
    {
        for(int x=0; x<20; x++)
        {
            dp[y][x] = -999999;
        }
    }
}

int mineGold() {
    // 세로, 가로 크기 입력받기
    int ROWS, COLUMNS;
    cin >> ROWS >> COLUMNS;

    // dp 초기화
    clearDP();

    // 금광 정보가 1차원으로 개떡같이 넘어오므로
    // 2차원으로 바꿔서 넣어야 함
    for(int y=1; y<ROWS+1; y++) {
        for(int x=0; x<COLUMNS; x++) {
            cin >> goldMine[y][x];
        }
    }

    // * dp실행
    // 점화식 :
    // dp[1][0] = goldMine[1][0], dp[2][0] = goldMine[2][0], ...
    // dp[r][c] = max(dp[r][c-1], dp[r-1][c-1], dp[r+1][c-1]) + + goldMine[r][c]
    //  -- 이거 할 때 처음행과 마지막행에서 if문 쓰기 싫어서 더미행 넣음
    for(int y=1; y<ROWS+1; y++) {
        dp[y][0] = goldMine[y][0];
    }

    for(int x=1; x<COLUMNS; x++) {
        for(int y=1; y<ROWS+1; y++) {
            dp[y][x] = max({dp[y][x-1], dp[y-1][x-1], dp[y+1][x-1]}) + goldMine[y][x];
        }
    }

    int max_val = 0;
    for(int y=1; y<ROWS+1; y++) {
        max_val = max_val > dp[y][COLUMNS-1] ? max_val : dp[y][COLUMNS-1];
    }
    return max_val;
}

int main(void) {
    // 테스트케이스 T만큼 반복
    int T;
    cin >> T;
    for(int t=0; t<T; t++) {
        cout << mineGold() << '\n';
    }
    return 0;
}