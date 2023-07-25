/*
IDEAS
	bfs 일까 dfs일까..?

	3개를 어디에 놓아야 할까?

	만약 놓았다면 남은 방의 수는 어떻게 계산할까?

	빈 칸을 위주로 탐색하기 보다 바이러스 위주로 탐색하는게 어떨까?

*/


#include <iostream>

int	main(void)
{
	int 		**map;
	std::string	temp;
	int			N, M;

	std::cin >> N >> M;
	std::cin.ignore();
	map = new int*[N];
	for (int i=0; i<N; i++)
		map[i] = new int[M];

	for (int i=0; i<N; i++)
	{
		getline(std::cin, temp);
		for (int j=0; j<M; j++)
			map[i][j] = temp[j] - '0';
	}

	for (int i=0; i<N; i++)
	{
		for (int j=0; j<M; j++)
		{
			std::cout << map[i][j] << " ";
		}
		std::cout << std::endl;
	}
}