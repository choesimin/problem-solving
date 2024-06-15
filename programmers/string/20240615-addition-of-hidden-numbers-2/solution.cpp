#include <cctype>
#include <iostream>
#include <string>

using namespace std;

int solution(string my_string) {
  int answer = 0;
  string temp = "";

  for (char ch : my_string) {
    if (isdigit(ch)) {
      temp += ch;
    } else {
      if (!temp.empty()) {
        answer += stoi(temp);
        temp = "";
      }
    }
  }

  if (!temp.empty()) {
    answer += stoi(temp);
  }

  return answer;
}

int main() {
  string test1 = "aAb1B2cC34oOp";
  string test2 = "1a2b3c4d123Z";

  cout << solution(test1) << endl;
  cout << solution(test2) << endl;
}
