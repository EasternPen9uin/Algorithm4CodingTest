def main():
    # dpTable : 가로502 세로501 사이즈 dp 배열 생성 (0번째 행 전체, 그리고 각 행의 좌우 끝은 더미)
    dpTable = [[0]*502 for _ in range(501)]
    # N 입력받음
    CONST_N = int(input())
    # 최댓값 구하기 용 변수
    maxValue = 0 # 값의 범위는 0 이상 9999 이하

    for y in range(1, CONST_N+1):
        intValueIterator = map(int, input().split(' '))
        for x in range(1, y+1):
            # dp 실행
            dpTable[y][x] = max(dpTable[y-1][x], dpTable[y-1][x-1]) + next(intValueIterator)
            # 최댓값 갱신
            maxValue = maxValue if maxValue > dpTable[y][x] else dpTable[y][x]
    print(maxValue)
#####
main()