#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<string> babbling)
{
    int answer = 0;
    vector<string> patterns = {"aya", "ye", "woo", "ma"};

    for (string word : babbling)
    {
        for (string pattern : patterns)
        {
            size_t pos = word.find(pattern);
            while (pos != string::npos)
            {
                word.replace(pos, pattern.size(), " ");
                pos = word.find(pattern);
            }
        }

        word.erase(remove(word.begin(), word.end(), ' '), word.end());

        if (word.empty())
        {
            answer++;
        }
    }

    return answer;
}

int main()
{
    vector<string> babbling = {"ayaye", "uuuma", "ye", "yemawoo", "ayaa"};
    int answer = solution(babbling);

    cout << answer << endl;
}
