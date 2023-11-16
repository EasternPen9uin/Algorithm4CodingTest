#include <iostream>
#include <queue>        // 큐 사용을 위해 include
using namespace std;

int main(void) {
    // 스택 준비
    queue<int> q;
    
    // 삽입(5) - 삽입(2) - 삽입(3) - 삽입(7)
    q.push(5);
    q.push(2);
    q.push(3);
    q.push(7);
    
    // 삭제
    q.pop();

    // 삽입(1) - 삽입(4) - 삭제
    q.push(1);
    q.push(4);
    q.pop();

    // C++의 스택, 큐는 중간부터 접근하는거 불가능
    // 그런 짓을 할거면 vector같은거 써야지
    // 최상단 원소부터 출력하는거만 진행
    while(!q.empty()) {
        //int num = stk.pop(); // - C++의 pop은 요소 반환을 안 한대요...
        int num = q.front(); q.pop();
        std::cout << num << ' ';
    }
    return 0;
}