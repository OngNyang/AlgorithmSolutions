/*
1. 문제유형
	자료구조 - 큐 - 우선순위 큐
2. 알고리즘
	큐
3. 자료구조
	큐 또는 뎈
4. 구현 전략
	페어 만들고 큐에 넣기

	카운팅.
	일단 팝프론트.
	우선순위 최상인지 검증
		아니다
			푸시백
		맞다
			목적 인덱스인지 확인
				맞다
					리턴.
				아니다

	

우선순위큐인것 같음
그런데 우선순위를 그대로 쓰기에는 무리가 있음. 뒤로 다시 집어 넣어야 함.
queue를 사용하면 됨 deque 사용이 좋을듯 


*/

#include <string>
#include <vector>
#include <utility>
#include <deque>
#include <iostream>


using namespace std;

bool	check_priority(deque<pair<int,int> > &dq)
{
	int	target = (dq.front()).second;
	int	max = 0;

	for (int i=0; i<dq.size(); i++)
	{
		if (dq[i].second > max)
			max = dq[i].second;
	}
	if (target == max)
		return (true);
	return (false);
}

int solution(vector<int> priorities, int location) {
    int						answer = 0;
	int						cnt = 0;
	deque<pair<int,int> >	dq;

	//create deque
	for (int i=0; i<priorities.size(); i++) 
	{
		pair<int, int>			pr;	//인덱스, 우선순위
		pr.first = i;	pr.second = priorities[i];
		dq.push_back(pr);
	}

	while (1)
	{
		//우선순위 최상위인지 검증.
		//	맞으면
		//		팝
		//	아니면
		//		팝 하고 푸시백
		if (check_priority(dq) == true)
		{
			cnt++;
			if ((dq.front()).first == location)
			{
				return (cnt);
			}
			dq.pop_front();
		}
		else
		{
			pair<int,int>	temp;
			temp.first = (dq.front()).first;	temp.second = (dq.front()).second;
			dq.pop_front();
			dq.push_back(temp);
		}
		if (dq.empty())
			break ;
	}
    return answer;
}

int	main(void)
{
	cout << solution({2,1,3,2}, 2) << endl;
	cout << solution({1,1,9,1,1,1}, 0) << endl;

}