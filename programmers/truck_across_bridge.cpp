/*
1. 문제 유형
	자료구조.
2. 알고리즘
	탐색 문제는 아님.
		정해진 순서를 지켜야함. -> 자료구조 문제일 가능성 높음

3. 자료구조
	들어온곳과 나가는곳이 다르니까 큐같음.
	덱 사용.

4. 구현 전략

	만족시켜야 하는 조건
		무게제한
		최대 트럭수(== bridge_length)
	무게제한 확인
		현재 대기열 전체의 트럭 무게 확인 >=< 무게제한
		대기열의 사이즈 >=< 최대 트럭수

	
	다리를 건너는 트럭에 대한 자료구조 만들기.
	반복문으로 시간 표현
	그 대기열 안에서 위의 조건에 맞게 



*/


#include <string>
#include <vector>
#include <iostream>
#include <deque>
#include <utility>

using namespace std;

bool	check_entering(deque<pair<int,int> > &bridge, pair<int,int> &truck, int weight_limit, int bridge_length)
{
	int	sum = 0;

	//무게 제한 괜찮은지
	//	전체무게 + 트럭무게 >=< 무게제한
	for (int i=0; i<bridge.size(); i++)
		sum += bridge[i].first;
	sum += truck.first;
	if (sum > weight_limit)
		return (false);
	//길이 제한 괜찮은지
	if (bridge.size() >= bridge_length)
		return (false);
	return (true);
}

void	control_time(deque<pair<int,int> > &bridge, int bridge_length, int &cnt)
{
	for(int i=0; i<bridge.size(); i++)
	{
		bridge[i].second += 1;
		// if (bridge[i].second == bridge_length + 1)
		if (bridge[i].second == bridge_length)
		{
			bridge.pop_front();
			cnt++;
			i--;
		}
	}
}

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int						len = truck_weights.size();
	int						sec = 0;
	pair<int, int>			truck;		//무게, 경과시간.
	deque<pair<int,int> >	bridge;
	int						cnt = 0;
	int						idx = 0;

	while (1)
	{
		// cout << sec << "sec" <<endl;

		//일제히 시간 올려주기
		//시간이 다 됐으면 덱에서 빼주기
		sec++;
		control_time(bridge, bridge_length, cnt);

		if (0 <= idx && idx <= len-1)
		{
			truck.first = truck_weights[idx];	truck.second = 0;
			if (check_entering(bridge, truck, weight, bridge_length))
			{
				bridge.push_back(truck);
				// std::cout << truck.first << "truck entering" << endl;
				idx++;
			}
		}	
		if (cnt == len)
			break ;
	}
    return sec;
}

int	main(void)
{
	// std::cout << solution(2, 10, {7,4,5,6}) << endl;
	// std::cout << solution(100, 100, {10}) << endl;
	std::cout << solution(100, 100, {10,10,10,10,10,10,10,10,10,10}) << endl;
	
}