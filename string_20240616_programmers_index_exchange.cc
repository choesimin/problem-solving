/*
# OX 퀴즈

<https://school.programmers.co.kr/learn/courses/17584/17584-내일은-코딩테스트-with-파이썬자료구조와-알고리즘의-기초부터-실전까지>

---

# 문제 설명

문자열 `my_string`과 정수 `num1`, `num2`가 매개변수로 주어질 때, `my_string`에서 인덱스 `num1`과 인덱스 `num2`에 해당하는 문자를 바꾼 문자열을 return 하도록 solution 함수를 완성해보세요.

---

# 제한사항


- 1 < `my_string`의 길이 < 100
- 0 ≤ `num1`, `num2` < `my_string`의 길이
- `my_string`은 소문자로 이루어져 있습니다.
- `num1` ≠ `num2`

- 연산 기호와 숫자 사이는 항상 하나의 공백이 존재합니다. 단 음수를 표시하는 마이너스 기호와 숫자 사이에는 공백이 존재하지 않습니다.
- 1 ≤ `quiz`의 길이 ≤ 10
- X, Y, Z는 각각 0부터 9까지 숫자로 이루어진 정수를 의미하며, 각 숫자의 맨 앞에 마이너스 기호가 하나 있을 수 있고 이는 음수를 의미합니다.
- X, Y, Z는 0을 제외하고는 0으로 시작하지 않습니다.
- -10,000 ≤ X, Y ≤ 10,000
- -20,000 ≤ Z ≤ 20,000
- [연산자]는 + 와 - 중 하나입니다.

---

# 입출력 예

| my_string | num1 | num2 | result |
| --- | --- | --- | --- |
| "hello" | 1 | 2 | "hlelo" |
| "I love you" | 3 | 6 | "I l veoyou" |

---

# 입출력 예 설명

## 입출력 예 #1

- "hello"의 1번째 인덱스인 "e"와 2번째 인덱스인 "l"을 바꾸면 "hlelo"입니다.

## 입출력 예 #2

- "I love you"의 3번째 인덱스 "o"와 " "(공백)을 바꾸면 "I l veoyou"입니다.

*/

#include <string>
#include <iostream>

using namespace std;

string solution(string my_string, int num1, int num2)
{
    // num1과 num2 위치의 문자를 교환
    char temp = my_string[num1];
    my_string[num1] = my_string[num2];
    my_string[num2] = temp;

    return my_string;
}

int main()
{
    string test1 = "hello";
    int num1_1 = 1;
    int num2_1 = 2;
    string result1 = solution(test1, num1_1, num2_1);
    cout << result1 << endl;

    // 테스트 케이스 2
    string test2 = "I love you";
    int num1_2 = 3;
    int num2_2 = 6;
    string result2 = solution(test2, num1_2, num2_2);
    cout << result2 << endl;

    return 0;
}
