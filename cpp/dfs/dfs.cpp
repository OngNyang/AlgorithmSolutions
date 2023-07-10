/*
DFS (깊이 우선 탐색)
	동작 story
		1. 탐색 시작 노드를 스택에 삽입 하고 방문 처리.
		2. 스택의 최상단 노드에 방문하지 않은 인접 노드가 있으면 그 인접 노드를 스택에 넣고 방문 처리.
		   방문하지 않은 인접 노드가 없으면 스택에서 최상단 노드를 꺼냄
		3. 2의 과정을 더이상 수행할수 없을때까지 진행.

*/

#include <iostream>
#include <vector>

bool	visited[9];
std::vector<int> graph[9];

void	dfs(int x)
{
	visited[x] = true;
	std::cout << x << ' ';
	for (int i=0; i<graph[x].size(); i++)
	{
		int	y = graph[x][i];
		if (visited[y] == false)
			dfs(y);
	}
}

int	main(void)
{
	graph[1].push_back(2);
	graph[1].push_back(3);
	graph[1].push_back(8);

	graph[2].push_back(1);
	graph[2].push_back(7);
		
	graph[3].push_back(1);
	graph[3].push_back(4);
	graph[3].push_back(5);
		
	graph[4].push_back(3);
	graph[4].push_back(5);
		
	graph[5].push_back(3);
	graph[5].push_back(4);
		
	graph[6].push_back(7);
		
	graph[7].push_back(2);
	graph[7].push_back(6);
	graph[7].push_back(8);
		
	graph[8].push_back(1);
	graph[8].push_back(7);

	dfs(1);
}

