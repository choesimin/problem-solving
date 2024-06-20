/*
# 로또의 최고 순위와 최저 순위

<https://school.programmers.co.kr/learn/courses/17584/17584-내일은-코딩테스트-with-파이썬자료구조와-알고리즘의-기초부터-실전까지>

---

# 문제 설명

로또 `6/45`(이하 '로또'로 표기)는 1부터 45까지의 숫자 중 6개를 찍어서 맞히는 대표적인 복권입니다. 아래는 로또의 순위를 정하는 방식입니다. (실제로 사용되는 로또 순위의 결정 방식과는 약간 다르지만, 이 문제에서는 지문에 명시된 대로 로또 순위를 결정하도록 합니다.)

| 순위 | 당첨 내용 |
| --- | --- |
| 1 | 6개 번호가 모두 일치 |
| 2 | 5개 번호가 일치 |
| 3 | 4개 번호가 일치 |
| 4 | 3개 번호가 일치 |
| 5 | 2개 번호가 일치 |
| 6(낙첨) | 그 외 |

로또를 구매한 민우는 당첨 번호 발표일을 학수고대하고 있었습니다. 하지만, 민우의 동생이 로또에 낙서를 하여, 일부 번호를 알아볼 수 없게 되었습니다. 당첨 번호 발표 후, 민우는 자신이 구매했던 로또로 당첨이 가능했던 최고 순위와 최저 순위를 알아보고 싶어 졌습니다.
알아볼 수 없는 번호를 `0`으로 표기하기로 하고, 민우가 구매한 로또 번호 6개가 `44, 1, 0, 0, 31 25`라고 가정해보겠습니다. 당첨 번호 6개가 `31, 10, 45, 1, 6, 19`라면, 당첨 가능한 최고 순위와 최저 순위의 한 예는 아래와 같습니다.

| 당첨 번호 | 31 | 10 | 45 | 1 | 6 | 19 | 결과 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 최고 순위 번호 | 31 | 0→10 | 44 | 1 | 0→6 | 25 | 4개 번호 일치, 3등 |
| 최저 순위 번호 | 31 | 0→11 | 44 | 1 | 0→7 | 25 | 2개 번호 일치, 5등 |

- 순서와 상관없이, 구매한 로또에 당첨 번호와 일치하는 번호가 있으면 맞힌 걸로 인정됩니다.
- 알아볼 수 없는 두 개의 번호를 각각 10, 6이라고 가정하면 3등에 당첨될 수 있습니다.
    - 3등을 만드는 다른 방법들도 존재합니다. 하지만, 2등 이상으로 만드는 것은 불가능합니다.
- 알아볼 수 없는 두 개의 번호를 각각 11, 7이라고 가정하면 5등에 당첨될 수 있습니다.
    - 5등을 만드는 다른 방법들도 존재합니다. 하지만, 6등(낙첨)으로 만드는 것은 불가능합니다.

민우가 구매한 로또 번호를 담은 배열 lottos, 당첨 번호를 담은 배열 win_nums가 매개변수로 주어집니다. 이때, 당첨 가능한 최고 순위와 최저 순위를 차례대로 배열에 담아서 return 하도록 solution 함수를 완성해주세요.

---

# 제한사항

- lottos는 길이 6인 정수 배열입니다.
- lottos의 모든 원소는 0 이상 45 이하인 정수입니다.
    - 0은 알아볼 수 없는 숫자를 의미합니다.
    - 0을 제외한 다른 숫자들은 lottos에 2개 이상 담겨있지 않습니다.
    - lottos의 원소들은 정렬되어 있지 않을 수도 있습니다.
- win_nums은 길이 6인 정수 배열입니다.
- win_nums의 모든 원소는 1 이상 45 이하인 정수입니다.
    - win_nums에는 같은 숫자가 2개 이상 담겨있지 않습니다.
    - win_nums의 원소들은 정렬되어 있지 않을 수도 있습니다.

---

# 입출력 예

| lottos | win_nums | result |
| --- | --- | --- |
| [44, 1, 0, 0, 31, 25] | [31, 10, 45, 1, 6, 19] | [3, 5] |
| [0, 0, 0, 0, 0, 0] | [38, 19, 20, 40, 15, 25] | [1, 6] |
| [45, 4, 35, 20, 3, 9] | [20, 9, 3, 45, 4, 35] | [1, 1] |

---

# 입출력 예 설명

## 입출력 예 #1

문제 예시와 같습니다.

## 입출력 예 #2

알아볼 수 없는 번호들이 아래와 같았다면, 1등과 6등에 당첨될 수 있습니다.

| 당첨 번호 | 38 | 19 | 20 | 40 | 15 | 25 | 결과 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 최고 순위 번호 | 0→38 | 0→19 | 0→20 | 0→40 | 0→15 | 0→25 | 6개 번호 일치, 1등 |
| 최저 순위 번호 | 0→21 | 0→22 | 0→23 | 0→24 | 0→26 | 0→27 | 0개 번호 일치, 6등 |

## 입출력 예 #3

민우가 구매한 로또의 번호와 당첨 번호가 모두 일치하므로, 최고 순위와 최저 순위는 모두 1등입니다.

*/

#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> get_rank(int matched, int zeros)
{
    // 가장 많이 맞은 경우와 가장 못 맟춘 경우를 계산
    int highest_match = matched + zeros;
    int lowest_match = matched;

    // 순위 계산
    int highest_rank = (highest_match < 2) ? 6 : 7 - highest_match;
    int lowest_rank = (lowest_match < 2) ? 6 : 7 - lowest_match;

    return {highest_rank, lowest_rank};
}

vector<int> solution(vector<int> lottos, vector<int> win_nums)
{
    // 당첨 번호를 빠르게 검색할 수 있도록 Vector를 Set으로 바꾸기
    set<int> win_set(win_nums.begin(), win_nums.end());

    // 당첨 번호와 같은 로또 번호와 0을 세기
    int matched = 0, zeros = 0;
    for (int num : lottos)
    {
        if (num == 0)
        {
            zeros++;
        }
        else if (win_set.find(num) != win_set.end())
        {
            matched++;
        }
    }

    // 순위 구하기
    return get_rank(matched, zeros);
}

int print(vector<int> result)
{
    for (int res : result)
    {
        cout << res << " ";
    }
    cout << endl;

    return 0;
}

int main()
{
    vector<int> lottos1 = {44, 1, 0, 0, 31, 25};
    vector<int> win_nums1 = {31, 10, 45, 1, 6, 19};
    vector<int> result1 = solution(lottos1, win_nums1);
    print(result1);

    vector<int> lottos2 = {0, 0, 0, 0, 0, 0};
    vector<int> win_nums2 = {38, 19, 20, 40, 15, 25};
    vector<int> result2 = solution(lottos2, win_nums2);
    print(result2);

    vector<int> lottos3 = {45, 4, 35, 20, 3, 9};
    vector<int> win_nums3 = {20, 9, 3, 45, 4, 35};
    vector<int> result3 = solution(lottos3, win_nums3);
    print(result3);
}
