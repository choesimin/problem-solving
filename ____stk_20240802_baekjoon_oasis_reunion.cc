/*
# 오아시스 재결합

- <https://www.acmicpc.net/problem/3015>

- 시간 제한 : 1 초
- 메모리 제한 : 256 MB

---

# 문제

오아시스의 재결합 공연에 N명이 한 줄로 서서 기다리고 있다.

이 역사적인 순간을 맞이하기 위해 줄에 서서 기다리고 있던 백준이는 갑자기 자기가 볼 수 있는 사람의 수가 궁금해 졌다.

두 사람 A와 B가 서로 볼 수 있으려면, 두 사람 사이에 A 또는 B보다 키가 큰 사람이 없어야 한다.

줄에 서 있는 사람의 키가 주어졌을 때, 서로 볼 수 있는 쌍의 수를 구하는 프로그램을 작성하시오.

---

# 입력

첫째 줄에 줄에서 기다리고 있는 사람의 수 N이 주어진다. (1 ≤ N ≤ 500,000)

둘째 줄부터 N개의 줄에는 각 사람의 키가 나노미터 단위로 주어진다. 모든 사람의 키는 2^31 나노미터 보다 작다.

사람들이 서 있는 순서대로 입력이 주어진다.

---

# 출력

서로 볼 수 있는 쌍의 수를 출력한다.

---

# 예제

## 입력 1

```
7
2
4
1
2
2
5
1
```

## 출력 1

```
10
```

---

# 출처

Olympiad > Croatian Highschool Competitions in Informatics > 2007 > Croatian Olympiad in Informatics 2007 1번

- 문제를 번역한 사람: baekjoon

---

# 알고리즘 분류

- 자료 구조
- 스택

*/

// #include <iostream>
// #include <stack>
// #include <vector>
// using namespace std;

// int main()
// {
//     int N;
//     cin >> N;

//     vector<int> heights(N);
//     for (int i = 0; i < N; i++)
//     {
//         cin >> heights[i];
//     }

//     int answer = 0;
//     for (int i = 0; i < N; i++)
//     {
//         int current_height = heights[i];
//         stack<int> visible_heights;

//         int max_height = 0;
//         for (int j = i + 1; j < N; j++)
//         {
//             int comparing_height = heights[j];

//             if (comparing_height >= max_height)
//             {
//                 max_height = comparing_height;
//                 visible_heights.push(comparing_height);
//             }
//         }

//         cout << current_height << " " << visible_heights.size() << "\n";

//         answer += visible_heights.size();
//     }

//     cout << answer << endl;

//     return 0;
// }

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> heights(N);
    for (int i = 0; i < N; i++)
    {
        cin >> heights[i];
    }

    stack<pair<int, int>> s;
    long long answer = 0;

    for (int i = 0; i < N; i++)
    {
        int current_height = heights[i];
        int count = 1;

        while (!s.empty() && s.top().first <= current_height)
        {
            answer += s.top().second;
            if (s.top().first == current_height)
            {
                count += s.top().second;
            }
            s.pop();
        }

        if (!s.empty())
        {
            answer += 1;
        }

        s.push({current_height, count});
    }

    cout << answer << endl;

    return 0;
}