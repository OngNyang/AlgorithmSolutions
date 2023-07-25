/*
ideas
2차원 정수 배열로 맵을 만듦
모든 점을 한번씩 시작점으로 할거임. (2중 for문)
	시작점으로 함수를 호출
해당 지점이 0이면 2로 바꾸고 사방을 탐색할것임. 재귀함수로.
이런 이벤트 하나당 1개의 아이스크림인것이다.

*/


#include <iostream>

void	search(int **map, int i, int j, int N, int M)
{
	if (!(0<=i && i<=(N-1) && 0<=j && j<=(M-1)))
		return ;
	if (map[i][j] == 0)
	{
		map[i][j] = 2;
		search(map, i-1, j, N,M);
		search(map, i+1, j,N,M);
		search(map, i, j-1,N,M);
		search(map, i, j+1,N,M);
	}
}

int	main(void)
{
	int			cnt = 0;
	int			N, M;
	std::cin >> N >> M;
	std::string	temp;
	// int			map[N][M];
	int			**map = new int*[N];	//함수로 주고 받는데 동적할당이 가장 좋은 방법일까?
	for (int i=0; i<N; i++)
		map[i] = new int[M];

	std::cin.ignore();	//얘 없으면 쓰레기값 들어있는것 볼수 있다. cin 사용하고 ignore사용하는 습관.
	for (int i=0; i<N; i++)
	{
		getline(std::cin, temp);
		for (int j=0; j<temp.size(); j++)
		{
			map[i][j] = temp[j] - '0';
		}
	}

	for (int i=0; i<N; i++)
	{
		for (int j=0; j<M; j++)
		{
			if (map[i][j] == 0)
			{
				cnt++;
				search(map, i, j, N, M);
			}
		}
	}

	std::cout << cnt << std::endl;
}