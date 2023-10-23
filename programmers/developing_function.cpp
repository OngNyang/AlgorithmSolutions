/**
1. 문제유형
	자료구조
2. 알고리즘
3. 자료구조
	스택 vs 큐
	큐인것 같다. 한쪽에서만 작업이 이루어지면 안되니까
4. 구현전략
먼저 끝나면 대기열에 들어가있다가 이전의 것들 모두 끝나야 그 차례가 올수 있다.

{20,15,10,25,30}
선두 값보다 작은 애들 전부 팝
	카운트 세기 -> 벡터에 넣기.
다시 선두 잡고 위의 과정 반복

차라리 inser로 넣고 pop으로 빼자
근데 deque가 훨씬 적절할듯



*/


#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <deque>


using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int>	answer;
	// vector<int>	vt;
	deque<int>	vt;
	int			len = progresses.size();
	int			cnt = 0;
	int			pivot;
	int			idx = 0;

	//initializig vt
	for (int i=0; i<len; i++)
	{
		float f = (100 - (float)progresses[i]) / (float)speeds[i];
		f = ceil(f);
		vt.push_back((int)f);
	}
	pivot = vt.front();
	while (1)
	{
		if (vt[0] <= pivot)
		{
			vt.pop_front();
			cnt++;
			if (vt.empty())
			{
				answer.push_back(cnt);
				break ;
			}
		}
		else
		{
			answer.push_back(cnt);
			pivot = vt[0];
			cnt = 0;
		}
		if (vt.empty())
			break ;
	}
    return answer;
}

int	main()
{
	vector<int> vt = solution({93,30,55}, {1,30,5});

	for(auto i : vt)
	{
		cout << i << endl;
	}

}