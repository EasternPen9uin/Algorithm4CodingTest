#include <iostream>
#include <stack>        // 스택 사용을 위해 include
using namespace std;

int main(void) {
    // 스택 준비
    stack<int> stk;
    
    // 삽입(5) - 삽입(2) - 삽입(3) - 삽입(7)
    stk.push(5);
    stk.push(2);
    stk.push(3);
    stk.push(7);
    
    // 삭제
    stk.pop();
    
    // 삽입(1) - 삽입(4) - 삭제
    stk.push(1);
    stk.push(4);
    stk.pop();

    // C++의 스택, 큐는 중간부터 접근하는거 불가능
    // 그런 짓을 할거면 vector같은거 써야지
    // 최상단 원소부터 출력하는거만 진행
    while(!stk.empty()) {
        //int num = stk.pop(); // - C++의 pop은 요소 반환을 안 한대요...
        int num = stk.top(); stk.pop();
        std::cout << num << ' ';
    }
    return 0;
}