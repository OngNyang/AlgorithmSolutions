/*
상상하좌우 로 1직선으로 쭉 감시
ㅈㅏㅇ애물 3개, 모모두두가  피할수 있는지 계산

일단 모든 위치에 놓아보아야 함.  조합이라고 볼수있다.
 (N*N - T - S)! / (N*N - T - S -3)! 만큼의 경우의 수 <- 이건 오류임
 (N*N)개중 3개를 순서없이 고르는 것이다.
그때마다 선생님의 시야를 통해 학생들이 노출되는지 봐야함. 상하좌우로 1칸씩 전진하며 확인하고, O에 가려지면 탐색 중지



3*3 이라면
012
345
678

*/


/*
배운점

pair 클래스
	utility 헤더에 정의되어 있지만 utility 헤더가 vector 헤더 안에 들어가있다.

*/

#include <iostream>
#include <vector>

// using namespace std;

int		N;
char	**map;

bool	watch(int i, int j)
{
	int	ni = i;
	int nj = j;
//좌
	while (1)
	{
		nj--;
		if (!(0 <= ni && ni < N && 0<= nj && nj < N))
			break ;
		if (map[ni][nj] == 'O')
			break ;
		if (map[ni][nj] == 'X')
			continue ;
		if (map[ni][nj] == 'S')
			return (false);
	}
//우
	ni = i;
	nj = j;
	while (1)
	{
		nj++;
		if (!(0 <= ni && ni < N && 0<= nj && nj < N))
			break ;
		if (map[ni][nj] == 'O')
			break ;
		if (map[ni][nj] == 'X')
			continue ;
		if (map[ni][nj] == 'S')
			return (false);
	}
//상
	ni = i;
	nj = j;
	while (1)
	{
		ni--;
		if (!(0 <= ni && ni < N && 0<= nj && nj < N))
			break ;
		if (map[ni][nj] == 'O')
			break ;
		if (map[ni][nj] == 'X')
			continue ;
		if (map[ni][nj] == 'S')
			return (false);
	}
//하
	ni = i;
	nj = j;
	while (1)
	{
		ni++;
		if (!(0 <= ni && ni < N && 0<= nj && nj < N))
			break ;
		if (map[ni][nj] == 'O')
			break ;
		if (map[ni][nj] == 'X')
			continue ;
		if (map[ni][nj] == 'S')
			return (false);
	}
	return (true);
}

bool	surveillance(std::vector<std::pair<int, int> >& current)
{
//current의 모든 요소가 X인지 체크
	for (int i=0; i<3; i++)
	{
		if (map[current[i].first][current[i].second] != 'X')
			return (false);
	}
//map에 장애물 'O' 그리기
	for (int i=0; i<3; i++)
		map[current[i].first][current[i].second] = 'O';
//선생님의 수를 구함
	int	num_t = 0;
	for (int i=0; i<N; i++)
		for (int j=0;j<N; j++)
			if (map[i][j] == 'T')
				num_t++;
//map을 모두 돌며 선생을 찾고 선생마다 시선의 광선을 구현
	int	cnt = 0;
	for (int i=0; i<N; i++)
	{
		for (int j=0; j<N; j++)
		{
			if (map[i][j] == 'T')
			{
				if (watch(i, j) == true)
					cnt++;
			}
		}
	}
	if (cnt == num_t)
		return (true);
	else
	{
//map에 장애물 'O' 지우기
		for (int i=0; i<3; i++)
			map[current[i].first][current[i].second] = 'X';
		return (false);
	}

}

void	combinations(int k, int start, std::vector<std::pair<int, int> >& nums, std::vector<std::pair<int, int> >& current)
{
//조합 하나 완성시
	if (current.size() == k)
	{
		//----
		if (surveillance(current) == true)
		{
			std::cout << "YES" << std::endl;
			exit(0);
		}
		return ;
	}
	else
	{
		for (int i=start; i<nums.size(); i++)
		{
			current.push_back(nums[i]);
			combinations(k, i+1, nums, current);
			current.pop_back();
		}
	}
}



int	main(void)
{
	std::vector<std::pair<int, int> >	nums;
	std::vector<std::pair<int, int> >	current;
	int	k = 3;

//입력받기
	std::cin >> N;
	std::cin.ignore();
	map = new char*[N];
	for (int i=0; i<N; i++)
		map[i] = new char[N];
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			std::cin >> map[i][j];
//nums벡터 채워주기
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			nums.push_back(std::make_pair(i, j));
//조합 구하기
	combinations(k, 0, nums, current);

	std::cout << "NO" << std::endl;



	// for (int i=0; i<N; i++)
	// {
	// 	for (int j=0; j<N; j++)
	// 	{
	// 		std::cout << map[i][j] << " ";
	// 	}
	// 	std::cout <<std::endl;
	// }



}