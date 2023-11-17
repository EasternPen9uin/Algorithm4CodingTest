# 테스트 케이스 하나 입력받아서 값 반환
def mineGold():
    # 세로, 가로 크기 입력받기
    ROWS, COLUMNS = map(int, input().split(' '))
    
    # 입력받을 금광 정보를 저장할 2차원 배열
    goldMine = [[0] * COLUMNS for _ in range(ROWS+2)]
    
    # DP용 리스트
    # +2하는 이유는 나중에 dp할 때 양 끝에서 if문 안쓰게 하려고
    dp = [[-9999999] * COLUMNS for _ in range(ROWS+2)]

    # 금광 정보가 1차원으로 개떡같이 넘어오므로
    # 2차원으로 바꿔서 넣어야 함
    # 양끝 행은 더미행임에 주의
    num_iter = map(int, input().split(' '))
    for y in range(1, ROWS+1):
        for x in range(COLUMNS):
            goldMine[y][x] = next(num_iter)

    # dp실행
    # 점화식 :
    # dp[1][0] = goldMine[1][0], dp[2][0] = goldMine[2][0], ...
    # dp[r][c] = max(dp[r][c-1], dp[r-1][c-1], dp[r+1][c-1]) + + goldMine[r][c]
    #  -- 이거 할 때 처음행과 마지막행에서 if문 쓰기 싫어서 더미행 넣음
    for y in range(1, ROWS+1):
        dp[y][0] = goldMine[y][0]

    for x in range(1,COLUMNS):
        for y in range(1, ROWS+1):
            dp[y][x] = max(dp[y][x-1], dp[y-1][x-1], dp[y+1][x-1]) + goldMine[y][x]
    return max([dp[y][-1] for y in range(1, ROWS+1)])

def main():
    # 테스트케이스 T만큼 반복
    for _ in range(int(input())):
        print(mineGold())
main()