
/*
1. 문제유형
	자료구조 - 큐, 덱
2. 알고리즘
	자료구조
3. 자료구조
	큐, 덱
4. 구현 전략
	대기열에 넣고 값보다 작은 값 만나면 팝 하면 될듯
		덱 사용
	버틴 시간을 체크해야 함. 
		페어 사용
		

*/


#include <string>
#include <vector>
#include <iostream>
#include <deque>
#include <utility>

using namespace std;

void	increase_time(deque<pair<int,int> >& dq)
{
	for (int i=0; i<dq.size(); i++)
		dq[i].second += 1;
}

void	check_dq(deque<pair<int,int> >& dq, pair<int,int>& pr, vector<int> &answer)
{
	int	target = pr.first;

	for (deque<pair<int,int> >::iterator it = dq.begin(); it != dq.end(); it++)
	{

		if (it->first > target)
		{
			// answer.push_back(it->second);
			answer[it-dq.begin()] = it->second;
			dq.erase(it);
			it--;
		}
	}
}

vector<int> solution(vector<int> prices) {
	int						len = prices.size();
    vector<int>				answer;
	pair<int,int>			pr;			//price, time
	deque<pair<int,int> >	dq;

	answer.resize(len);
	for (int i=0; i<len; i++)
		answer[i] = 0;
	for (int i=0; i<len; i++)
	{
		//시간 증가
		increase_time(dq);
		//페어 초기화.
		pr.first = prices[i];	pr.second = 0;
		//더 작은 애 만나면 팝
		check_dq(dq, pr, answer);
		//덱에 넣기
		dq.push_back(pr);
	
	}
	
	// for (int i=0; i<dq.size(); i++)
		// cout <<dq[i].second << "sec" << endl;
	for (int i=0; i<len; i++)
	{
		if (answer[i] == 0)
		{
			answer[i] = (dq.front()).second;
			dq.pop_front();
		}
	}

    return answer;
}

int	main()
{
	vector<int>	answer = solution({1,2,3,2,3});

	for (int i=0; i<answer.size(); i++)
	{
		cout << answer[i] << endl;
	}
}