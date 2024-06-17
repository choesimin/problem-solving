/*
# 369 게임

<https://school.programmers.co.kr/learn/courses/17584/17584-내일은-코딩테스트-with-파이썬자료구조와-알고리즘의-기초부터-실전까지>

---

# 문제 설명

머쓱이는 친구들과 369게임을 하고 있습니다. 369게임은 1부터 숫자를 하나씩 대며 3, 6, 9가 들어가는 숫자는 숫자 대신 3, 6, 9의 개수만큼 박수를 치는 게임입니다. 머쓱이가 말해야하는 숫자 `order`가 매개변수로 주어질 때, 머쓱이가 쳐야할 박수 횟수를 return 하도록 solution 함수를 완성해보세요.

---

# 제한사항

- 1 ≤ `order` ≤ 1,000,000

---

# 입출력 예

| order | result |
| --- | --- |
| 3 | 1 |
| 29423 | 2 |

---

# 입출력 예 설명

## 입출력 예 #1

- 3은 3이 1개 있으므로 1을 출력합니다.

## 입출력 예 #2

- 29423은 3이 1개, 9가 1개 있으므로 2를 출력합니다.

*/

#include <string>
#include <iostream>

using namespace std;

int solution(int order)
{
    int answer = 0;

    // 문자열을 순회하며 3, 6, 9가 있는지 확인
    for (char ch : to_string(order))
    {
        if (ch == '3' || ch == '6' || ch == '9')
        {
            answer++;
        }
    }

    return answer;
}

int main()
{
    int test1 = 3;
    int result1 = solution(test1);
    cout << result1 << endl;

    int test2 = 29423;
    int result2 = solution(test2);
    cout << result2 << endl;
}
