#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
  istringstream stream(my_string);
  vector<string> tokens;
  string token;

  // 공백 기준으로 문자열 분리
  while (stream >> token) {
    tokens.push_back(token);
  }

  // 첫 번째 숫자를 초기 값으로 설정
  int answer = stoi(tokens[0]);

  // 두 번째 요소부터 차례대로 '연산자를 확인'하고, '숫자를 연산'하기
  for (size_t i = 1; i < tokens.size(); i += 2) {
    string op = tokens[i];
    int number = stoi(tokens[i + 1]);

    if (op == "+") {
      answer += number;
    } else if (op == "-") {
      answer -= number;
    }
  }

  return answer;
}

int main() {
  string my_string = "3 + 4";
  int result = solution(my_string);
  cout << result << endl;
}
