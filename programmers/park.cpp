/*
1. 문제 유형
  구현
2. 알고리즘
  구현
3. 자료 구조
  배열
4. 풀이 방법
  맵을 만들까?
  무시될 조건에 관한 함수 구현
  


*/

#include <string>
#include <vector>
#include <utility>
#include <iostream>

using namespace std;
int width;
int height;
//				E  W S N
vector<int> dx = {1,-1,0, 0};
vector<int> dy = {0, 0,1,-1};


pair<int, int>	find_pos(vector<string> &park)
{
	pair<int, int> res;
	res.first = -1;
	res.second = -1;
		
	for (int i=0; i<park.size(); i++) 
	{
		for (int j=0; j<park.size(); j++) 
		{
			if (park[i][j] == 'S')
			{
				res.first = i;
				res.second = j;
				return (res);
			}
		}
	}
	return (res);
}

void			check_dest(vector<string> park, pair<int, int> &ori_pos, char dir, char amount)
{
	pair<int,int>	new_pos;
	pair<int,int>	cur_pos;
	int				c;
	bool			flag = true;

	cur_pos.first = ori_pos.first;
	cur_pos.second = ori_pos.second;
	if (dir == 'E')
		c = 0;
	else if (dir == 'W')
		c = 1;
	else if (dir == 'S')
		c = 2;
	else if (dir == 'N')
		c = 3;
	for (int i=0; i<(amount-'0'); i++)
	{
		new_pos.first = cur_pos.first + dy[c];
		new_pos.second = cur_pos.second +dx[c];
		if (park[new_pos.first][new_pos.second] == 'X')
		{
			flag = false;
			break ;
		}
		cur_pos.first = new_pos.first;
		cur_pos.second = new_pos.second;
	}
	if (!(0 <= new_pos.first && new_pos.first<= height -1 && 0 <= new_pos.second && new_pos.second<= width -1))
		flag = false;
		
	if (flag == true)
	{
		ori_pos.first = cur_pos.first;
		ori_pos.second = cur_pos.second;
	}
}

vector<int> solution(vector<string> park, vector<string> routes) {
	vector<int>	 answer;
	pair<int,int>   cur_pos;
	char			dir;
	char			amount;
		
	height = park.size();
	width = park[0].size();
		
	//시작 위치 찾기.
	cur_pos = find_pos(park);
	// std::cout << cur_pos.first << " " << cur_pos.second << std::endl;
		
	for (auto   i : routes)
	{
		dir = i[0];
		amount = i[2];
	//이동할 위치가 배제사항에 해당하는지 확인.
		check_dest(park, cur_pos, dir, amount);
	}
	answer.push_back(cur_pos.first);
	answer.push_back(cur_pos.second);
	return answer;
}

int	main(void)
{
	vector<int> answer = solution({"SOO","OOO","OOO"}, {"E 2","S 2","W 1"});
	for (auto i : answer)
	{
		std::cout << i << std::endl;
	}
}