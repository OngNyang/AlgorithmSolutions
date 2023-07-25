/*
IDEAS
	얼마만큼의 거리~ 이런류의 문제는 bfs가 맞는것 같다.

	단방향이니까 벡터 방식은 조금 어려움
	반복문으로 이차원 배열의 0번 인덱스가 해당 노드인지 확인하고, 모두 탐색. (재방문 가능한듯)
	반복문 한번당 카운트 한번씩 해서.

	마지막은 배열로 해서 오름차순 정렬
*/

typedef	struct	s_node
{
	int	idx;
	int	depth;
}				node;

#include <iostream>
#include <queue>
#include <vector>

int	main(void)
{
	std::vector<int>	result;
	int	cnt = 0;
	int	**map;
	int	N, M, K, X;

//인자 받기.
	std::cin >> N >> M >> K >> X;
	std::cin.ignore();
	map = new int*[M];
	for (int i=0; i<M; i++)
		map[i] = new int[2];
	for (int i=0; i<M; i++)
		std:: cin >> map[i][0] >> map[i][1];
	std::cin.ignore();

//queue 생성
	std::queue<node> q;
	node	departure;
	departure.idx = X;
	departure.depth = 0;
	q.push(departure);
	while (!q.empty())
	{
		node	now = q.front();
		// std::cout << now.idx << std::endl;
		q.pop();
		for (int i=0; i<M; i++)
		{
			if (map[i][0] == now.idx)
			{
				node	next;
				next.idx = map[i][1];
				next.depth = now.depth + 1;
				if (next.depth == K)
					result.push_back(next.idx);
				else
					q.push(next);
			}
		}
	}

	for (int i=0; i<result.size(); i++)
	{
		std::cout << result.back() << std::endl;
		result.pop_back();
	}



	// for (int i=0; i<M; i++)
	// {
	// 	for (int j=0; j<2; j++)
	// 	{
	// 		std::cout << map[i][j] << " ";
	// 	}
	// 	std::cout << std::endl;
	// }


}