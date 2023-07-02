/*
adjacency matrix (인접 행렬)
	: 2차원 배열에 각 노드가 연결된 형태를 기록하는 방식.
	- 비용을 기입.
	- 연결 되어 있지 않다면, 무한의 비용.
*/

#include <iostream>

int	main(void)
{
	long long	INF = 9999999999999999LL;

	int	adj_mat[3][3] = {{0,7,5}, {7, 0,INF}, {5,INF,0}};
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
		{
			std::cout << adj_mat[i][j] << " ";
		}
		std::cout << std::endl;
	}

}