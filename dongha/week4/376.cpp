#include <iostream>
#include <algorithm>  //min, max함수 쓰기 위함
using namespace std;

// * 전역변수
// dp테이블 (기본적으로 C++ 전역변수는 0으로 초기회)
int dpTable[501][502];

// Java의 nextInt()같은식으로 코드 짜려고 만듦
int getInt() {
    int retValue;
    cin >> retValue;
    return retValue;
}

int main(void) {
    // 삼각형의 크기 n을 입력받음
    const int CONST_N = getInt();
    // 최댓값 구하기용 변수
    int maxValue = 0;
    // DP 진행
    for(int y=1; y<=CONST_N; y++) {
        for(int x=1; x<=y; x++) {
            dpTable[y][x] = max({dpTable[y-1][x], dpTable[y-1][x-1]}) + getInt();
            // 최댓값 갱신
            maxValue = maxValue > dpTable[y][x] ? maxValue : dpTable[y][x];
        }
    }
    cout << maxValue;
    return 0;
}