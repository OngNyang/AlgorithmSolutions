/*
이게 왜 dfs..

인접 행렬을 만드는건가?
	N*N개이다. N*N개 만큼의 도시가 있는것이고 그에 맞춰 각각 4개의 인접행렬이 있을수 있다.

각 위치마다 인접 리스트 만들기
인접 리스트로 bfs 이용해서 각 위치마다 연합 리스트 만들기

2차원 배열을 전부 순회하며, 평균값 연산 할곳은 해주고, 넘어갈곳은 넘어가 주기


*/



/*
알고리즘 테스트를 진행할때, 일괄적으로 적용시킬 폼이 있음 좋겠다. 예를 들면

자료구조는 무엇을 선택할것인가.
알고리즘은 무엇을 선택할것인가
시간 복잡도 계산
메모리 계산

*/


#include <iostream>
#include <vector>
#include <queue>

int	N,L,R;
int	**map;


void	check_LR(int i, int j, int ni, int nj, std::vector<std::vector<std::pair<int, int> > >& adj_list)
{
	int	diff = 0;

	if (!(0 <= ni && ni < N && 0<= nj && nj < N))
		return ;
	diff = abs(map[i][j] - map[ni][nj]);
	if (L <= diff && diff <= R)
		adj_list[(i*N)+j].push_back(std::make_pair(ni, nj));
}

int	main(void)
{
//입력받기
	std::cin >> N >> L >> R;
	std::cin.ignore();
	map = new int*[N];
	for (int i=0; i<N; i++)
		map[i] = new int[N];
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			std::cin >> map[i][j];
//인접 리스트 생성
	std::vector<std::vector<std::pair<int, int> > > adj_list(N*N);
//상하좌우 탐색
	for (int i=0; i<N; i++)
	{
		for (int j=0; j<N; j++)
		{
			check_LR(i, j, i-1, j, adj_list);
			check_LR(i, j, i+1, j, adj_list);
			check_LR(i, j, i, j-1, adj_list);
			check_LR(i, j, i, j+1, adj_list);
		}
	}
//bfs와 인접리스트를 이용해서 연합 구해내기.
	std::vector<std::queue<std::pair<int, int> > >	aliance;
	
	for (int )


//인접 리스트 출력 체크
	// for (int i=0; i<(N*N); i++)
	// {
	// 	std::cout << "idx : " << (i/N) << " " << (i%N) << std::endl;
	// 	for (int j=0; j<adj_list[i].size(); j++)
	// 	{
	// 		std::cout << adj_list[i][j].first << "," << adj_list[i][j].second << " ";
	// 	}
	// 	std::cout << std::endl;
	// }
//map 입력 출력 체크
	// for (int i=0; i<N; i++)
	// {
	// 	for (int j=0; j<N; j++)
	// 	{
	// 		std::cout << map[i][j] << " ";
	// 	}
	// 	std::cout << std::endl;
	// }

}