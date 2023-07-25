/*
IDEAS
	상하좌우... 주변으로 퍼지는거니 bfs가 맞는것 같다.
	바이러스 종류가 있고, 작은 숫자부터 퍼지는것.
		'퍼진다' 그 자체는 그 칸에 그 바이러스의 이름을 넣어준다.
	번호 낮은것 부터 증식 -> 낮은것부터 퍼트리면 되고, 해당 위치가 0이 아니면 건드리지 않으면 됨.


*/


#include <iostream>
#include <queue>

typedef struct s_pos
{
	int x;
	int y;
	int c;
}				pos;

std::queue<pos> q;

void	draw(int **map, int i, int j, int N, int k)
{
	if (0 <= i-1 && i-1 < N && 0 <= j && j < N)
	{
		if (map[i-1][j] == 0)
			map[i-1][j] = k;
	}
	if (0 <= i+1 && i+1 < N && 0 <= j && j < N)
	{
		if (map[i+1][j] == 0)
			map[i+1][j] = k;
	}
		if (0 <= i && i < N && 0 <= j-1 && j-1 < N)
	{
		if (map[i][j-1] == 0)
			map[i][j-1] = k;
	}
		if (0 <= i && i < N && 0 <= j+1 && j+1 < N)
	{
		if (map[i][j+1] == 0)
			map[i][j+1] = k;
	}
}

void	bfs(int **map, int N, int K)
{
	for (int i=0; i<N; i++)
	{
		for (int j=0; j<N; j++)
		{
			for (int k=1; k<=K; k++)
			{
				if (map[i][j] == k)
				{
					pos	temp;
					temp.x = i;
					temp.y = j;
					temp.c = k;
					q.push(temp);
				}
			}
		}
	}
	while (!q.empty())
	{
		pos	temp2 = q.front();
		q.pop();
		draw(map, temp2.x, temp2.y, N, temp2.c);
	}


	// for (int i=0; i<N; i++)
	// {
	// 	for (int j=0; j<N; j++)
	// 	{
	// 		std::cout << map[i][j] << " ";
	// 	}
	// 	std::cout << std::endl;
	// }
	// std::cout << std::endl;
}

int	main(void)
{
	int	N, K;
	int	S, X, Y;
	int	**map;

	std::cin >> N >> K;
	map = new int*[N];
	for (int i=0; i<N; i++)
		map[i] = new int[N];
	for (int i=0; i<N; i++)
	{
		for (int j=0; j<N; j++)
		{
			std::cin >> map[i][j];
		}
	}
	std::cin.ignore();
	std::cin >> S >> X >> Y;

	for (int i=0; i<S; i++)
	{
		bfs(map, N, K);
	}
	std::cout << map[X-1][Y-1] << std::endl;
}