#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> quiz) {
  vector<string> answer;

  for (string q : quiz) {
    stringstream ss(q);
    int X, Y, Z;
    char op, eq;

    ss >> X >> op >> Y >> eq >> Z;  // 수식을 구성하는 요소들을 추출

    int result = (op == '+') ? X + Y : X - Y;  // 연산자에 따라 계산

    if (result == Z) {
      answer.push_back("O");
    } else {
      answer.push_back("X");
    }
  }

  return answer;
}

int main() {
  vector<string> quiz1 = {"3 - 4 = -3", "5 + 6 = 11"};
  vector<string> quiz2 = {"19 - 6 = 13", "5 + 66 = 71", "5 - 15 = 63",
                          "3 - 1 = 2"};

  vector<string> result1 = solution(quiz1);
  vector<string> result2 = solution(quiz2);

  for (string res : result1) {
    cout << res << " ";  // X O
  }
  cout << endl;

  for (string res : result2) {
    cout << res << " ";  // O O X O
  }
  cout << endl;

  return 0;
}
