#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
  int answer = 0;
  vector<string> patterns = {"aya", "ye", "woo", "ma"};

  // 각 문자열에 대해 반복
  for (string word : babbling) {
    // 각 패턴에 대해 반복
    for (string pattern : patterns) {
      size_t position = word.find(pattern);  // 패턴이 나타나는 위치 찾기
      while (position != string::npos) {  // 패턴이 존재하는 동안 반복
        word.replace(position, pattern.size(), " ");  // 패턴을 공백으로 대체함
        position = word.find(pattern);  // 다음 패턴 위치를 찾기
      }
    }

    // 공백 문자 모두 제거하기
    word.erase(remove(word.begin(), word.end(), ' '), word.end());

    // 문자열이 비어 있으면 결과 값을 증가시킴
    if (word.empty()) {
      answer++;
    }
  }

  return answer;  // 최종 결과 반환
}

int main() {
  vector<string> babbling = {"ayaye", "uuuma", "ye", "yemawoo", "ayaa"};
  int answer = solution(babbling);
  cout << answer << endl;
}
