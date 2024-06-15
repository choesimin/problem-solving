/*
# 옹알이(1)

<https://school.programmers.co.kr/learn/courses/17584/17584-내일은-코딩테스트-with-파이썬자료구조와-알고리즘의-기초부터-실전까지>

---

# 문제 설명

머쓱이는 태어난 지 6개월 된 조카를 돌보고 있습니다. 조카는 아직 "aya", "ye", "woo", "ma" 네 가지 발음을 최대 한 번씩 사용해 조합한(이어 붙인) 발음밖에 하지 못합니다. 문자열 배열 `babbling`이 매개변수로 주어질 때, 머쓱이의 조카가 발음할 수 있는 단어의 개수를 return하도록 solution 함수를 완성해주세요.

---

# 제한사항

- 1 ≤ `babbling`의 길이 ≤ 100
- 1 ≤ `babbling[i]`의 길이 ≤ 15
- `babbling`의 각 문자열에서 "aya", "ye", "woo", "ma"는 각각 최대 한 번씩만 등장합니다.
    - 즉, 각 문자열의 가능한 모든 부분 문자열 중에서 "aya", "ye", "woo", "ma"가 한 번씩만 등장합니다.
- 문자열은 알파벳 소문자로만 이루어져 있습니다.

---

# 입출력 예

| babbling | result |
| --- | --- |
| ["aya", "yee", "u", "maa", "wyeoo"] | 1 |
| ["ayaye", "uuuma", "ye", "yemawoo", "ayaa"] | 3 |

---

# 입출력 예 설명

## 입출력 예 #1

- ["aya", "yee", "u", "maa", "wyeoo"]에서 발음할 수 있는 것은 "aya"뿐입니다. 따라서 1을 return합니다.

## 입출력 예 #2

- ["ayaye", "uuuma", "ye", "yemawoo", "ayaa"]에서 발음할 수 있는 것은 "aya" + "ye" = "ayaye", "ye", "ye" + "ma" + "woo" = "yemawoo"로 3개입니다. 따라서 3을 return합니다.

---

# 유의사항

- 네 가지를 붙여 만들 수 있는 발음 이외에는 어떤 발음도 할 수 없는 것으로 규정합니다. 예를 들어 "woowo"는 "woo"는 발음할 수 있지만 "wo"를 발음할 수 없기 때문에 할 수 없는 발음입니다.

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling)
{
  int answer = 0;
  vector<string> patterns = {"aya", "ye", "woo", "ma"};

  // 각 문자열에 대해 반복
  for (string word : babbling)
  {
    // 각 패턴에 대해 반복
    for (string pattern : patterns)
    {
      size_t position = word.find(pattern); // 패턴이 나타나는 위치 찾기
      while (position != string::npos)
      {                                              // 패턴이 존재하는 동안 반복
        word.replace(position, pattern.size(), " "); // 패턴을 공백으로 대체함
        position = word.find(pattern);               // 다음 패턴 위치를 찾기
      }
    }

    // 공백 문자 모두 제거하기
    word.erase(remove(word.begin(), word.end(), ' '), word.end());

    // 문자열이 비어 있으면 결과 값을 증가시킴
    if (word.empty())
    {
      answer++;
    }
  }

  return answer; // 최종 결과 반환
}

int main()
{
  vector<string> babbling = {"ayaye", "uuuma", "ye", "yemawoo", "ayaa"};
  int answer = solution(babbling);
  cout << answer << endl;
}
